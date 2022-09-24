#include <llvm/ADT/STLExtras.h>
#include <llvm/ADT/ScopedHashTable.h>
#include <mlir/IR/Attributes.h>
#include <mlir/IR/Builders.h>
#include <mlir/IR/BuiltinOps.h>
#include <mlir/IR/MLIRContext.h>
#include <mlir/IR/Value.h>
#include <mlir/IR/Verifier.h>

#include <algorithm>
#include <functional>
#include <numeric>
#include <set>
#include <unordered_map>

#include "common/location.hpp"
#include "common/node.hpp"
#include "dialect/dialect.hpp"
#include "syntax/parser.hpp"

namespace tl {
namespace common {

static mlir::RankedTensorType BuildType(mlir::OpBuilder& builder,
                                        mlir::StringRef name,
                                        mlir::ArrayRef<int64_t> shape) {
#define ITEM(NAME, TYPE)                                                   \
    {                                                                      \
        NAME,                                                              \
            [](mlir::OpBuilder& builder,                                   \
               mlir::ArrayRef<int64_t>& shape) -> mlir::RankedTensorType { \
                return mlir::RankedTensorType::get(shape, TYPE);           \
            }                                                              \
    }

    static std::unordered_map<
        std::string,
        std::function<mlir::RankedTensorType(mlir::OpBuilder & builder,
                                             mlir::ArrayRef<int64_t> & shape)>>
        mapper{
            ITEM("si8", mlir::IntegerType::get(
                            builder.getContext(), 1,
                            mlir::IntegerType::SignednessSemantics::Signed)),
            ITEM("ui8", mlir::IntegerType::get(
                            builder.getContext(), 1,
                            mlir::IntegerType::SignednessSemantics::Unsigned)),
            ITEM("si16", mlir::IntegerType::get(
                             builder.getContext(), 2,
                             mlir::IntegerType::SignednessSemantics::Signed)),
            ITEM("ui16", mlir::IntegerType::get(
                             builder.getContext(), 2,
                             mlir::IntegerType::SignednessSemantics::Unsigned)),
            ITEM("si32", mlir::IntegerType::get(
                             builder.getContext(), 4,
                             mlir::IntegerType::SignednessSemantics::Signed)),
            ITEM("ui32", mlir::IntegerType::get(
                             builder.getContext(), 4,
                             mlir::IntegerType::SignednessSemantics::Unsigned)),
            ITEM("si64", mlir::IntegerType::get(
                             builder.getContext(), 8,
                             mlir::IntegerType::SignednessSemantics::Signed)),
            ITEM("ui64", mlir::IntegerType::get(
                             builder.getContext(), 8,
                             mlir::IntegerType::SignednessSemantics::Unsigned)),
            ITEM("fp32", mlir::Float32Type::get(builder.getContext())),
            ITEM("fp64", mlir::Float64Type::get(builder.getContext())),
        };
#undef ITEM
    // TODO(XXX): add the type user defined and str
    return mapper.count(name.str()) ? mapper[name.str()](builder, shape)
                                    : throw name.str() + " is not supported!";
}

std::pair<mlir::LogicalResult, mlir::Value> ModuleNode::CodeGen(
    mlir::OpBuilder& builder,
    llvm::ScopedHashTable<mlir::StringRef, mlir::Value>& symbol_table) {
    the_module_ = mlir::ModuleOp::create(
        GetLocation().ToMLIRLocation(builder.getContext()));
    bool ret = true;
    for (auto& f : funcs_) {
        builder.setInsertionPointToEnd(the_module_->getBody());
        const auto& tmp = f->CodeGen(builder, symbol_table);
        if (tmp.first.failed()) {
            ret = false;
        }
    }
    return {
        ret ? mlir::LogicalResult::success() : mlir::LogicalResult::failure(),
        nullptr};
}

void ModuleNode::Print(DotHelper& helper) const {
    helper.WriteNode(GetId(), GetName() + "\n" + GetLocation().ToString());
    for (auto& f : funcs_) {
        f->Print(helper);
        helper.WriteEdge(GetId(), f->GetId(), "func");
    }
}

Status ModuleNode::Append(FunctionDeclaration* func) {
    funcs_.emplace_back(func);
    GetLocation().UpdateLocation(func->GetLocation());
    return Status::TL_OK;
}

std::pair<mlir::LogicalResult, mlir::Value> ExpressionNode::CodeGen(
    mlir::OpBuilder& builder,
    llvm::ScopedHashTable<mlir::StringRef, mlir::Value>& symbol_table) {
    if (op_ < 0) {
        auto hs = lhs_ ? lhs_ : rhs_;
        return hs->CodeGen(builder, symbol_table);
    }

    auto lhs_p = lhs_->CodeGen(builder, symbol_table);
    auto rhs_p = rhs_->CodeGen(builder, symbol_table);
    if (op_ == SY_PLUS) {
        auto ret = builder.create<tl::dialect::AddOp>(
            GetLocation().ToMLIRLocation(builder.getContext()), lhs_p.second,
            rhs_p.second);
        return {mlir::LogicalResult::success(), ret};
    }

    if (op_ == SY_MUL) {
        auto ret = builder.create<tl::dialect::MulOp>(
            GetLocation().ToMLIRLocation(builder.getContext()), lhs_p.second,
            rhs_p.second);
        return {mlir::LogicalResult::success(), ret};
    }
    return {mlir::LogicalResult::success(), nullptr};
}

void ExpressionNode::Print(DotHelper& helper) const {
    std::stringstream ss;
    ss << "name: " << GetName() << "\n" << GetLocation().ToString();
    if (op_ > 0 && lhs_ && rhs_) {
        ss << "\nop: " << TokenId2Str(op_);
    }
    helper.WriteNode(GetId(), ss.str());
    if (lhs_) {
        lhs_->Print(helper);
        helper.WriteEdge(GetId(), lhs_->GetId(), "lhs");
    }
    if (rhs_) {
        rhs_->Print(helper);
        helper.WriteEdge(GetId(), rhs_->GetId(), "rhs");
    }
}

Status Block::Append(std::shared_ptr<Node> node) {
    nodes_.emplace_back(node);
    GetLocation().UpdateLocation(node->GetLocation());
    return Status::TL_OK;
}

Status Block::Append(Node* node) { return Append(std::shared_ptr<Node>(node)); }

std::pair<mlir::LogicalResult, mlir::Value> Block::CodeGen(
    mlir::OpBuilder& builder,
    llvm::ScopedHashTable<mlir::StringRef, mlir::Value>& symbol_table) {
    for (auto& node : nodes_) {
        if (node) {
            node->CodeGen(builder, symbol_table);
        }
    }
    return {mlir::LogicalResult::success(), nullptr};
}

void Block::Print(DotHelper& helper) const {
    helper.WriteNode(GetId(), GetName() + "\n" + GetLocation().ToString());
    for (auto& node : nodes_) {
        node->Print(helper);
        helper.WriteEdge(GetId(), node->GetId(), "sub_node");
    }
}

std::pair<mlir::LogicalResult, mlir::Value> IdentifierNode::CodeGen(
    mlir::OpBuilder& builder,
    llvm::ScopedHashTable<mlir::StringRef, mlir::Value>& symbol_table) {
    if (!symbol_table.count(ident_)) {
        mlir::emitError(GetLocation().ToMLIRLocation(builder.getContext()))
            << ident_ << " does't exist!";
    }
    return {mlir::LogicalResult::success(), symbol_table.lookup(ident_)};
}

void IdentifierNode::Print(DotHelper& helper) const {
    std::string label = "";
    label += "name:";
    label += GetName();
    label += ", ident=";
    label += ident_;
    label += "\n";
    label += GetLocation().ToString();
    helper.WriteNode(GetId(), label);
}

std::pair<mlir::LogicalResult, mlir::Value> VarDeclarationNode::CodeGen(
    mlir::OpBuilder& builder,
    llvm::ScopedHashTable<mlir::StringRef, mlir::Value>& symbol_table) {
    auto type = BuildType(
        builder, var_dt_,
        var_shape_ ? var_shape_->ToSI64List() : llvm::ArrayRef<int64_t>());
    if (!expr_node_) {
        // ConstantOp
        auto data_shape =
            mlir::RankedTensorType::get(type.getShape(), mlir::Float64Type());
        mlir::DenseElementsAttr value = mlir::DenseElementsAttr::get(
            data_shape,
            var_inti_lt_
                ? static_cast<FP64ListNode*>(var_inti_lt_.get())->ToFP64List()
                : mlir::ArrayRef<double>());

        mlir::Value ret = builder.create<tl::dialect::ConstantOp>(
            GetLocation().ToMLIRLocation(builder.getContext()), value);
        if (symbol_table.count(var_ident_)) {
            mlir::emitError(GetLocation().ToMLIRLocation(builder.getContext()))
                << var_ident_ << " redifine!";
        }
        symbol_table.insert(var_ident_, ret);
        return {mlir::LogicalResult::success(), ret};
        // TODO: add str support
    }

    if (expr_node_) {
        auto p = expr_node_->CodeGen(builder, symbol_table);
        if (p.first.succeeded()) {
            symbol_table.insert(var_ident_, p.second);
        }
        return {mlir::LogicalResult::success(), p.second};
    }

    mlir::DenseElementsAttr init_val;
    if (type.getShape().empty()) {
        init_val = mlir::DenseElementsAttr::get(
            mlir::RankedTensorType::get({}, mlir::Float64Type()), {0});
    } else {
        auto shape = type.getShape();
        int64_t sz = std::accumulate(shape.begin(), shape.end(), 1,
                                     std::multiplies<int64_t>());
        init_val = mlir::DenseElementsAttr::get(
            mlir::RankedTensorType::get(type.getShape(), mlir::Float64Type()),
            mlir::ArrayRef<double>(std::vector<double>(sz, 0)));
    }
    mlir::Value ret = builder.create<tl::dialect::ConstantOp>(
        GetLocation().ToMLIRLocation(builder.getContext()), init_val);
    if (symbol_table.count(var_ident_)) {
        mlir::emitError(GetLocation().ToMLIRLocation(builder.getContext()))
            << var_ident_ << " redefine";
    }
    symbol_table.insert(var_ident_, ret);
    return {mlir::LogicalResult::success(), ret};
}

void VarDeclarationNode::Print(DotHelper& helper) const {
    std::stringstream label;
    label << "dt: " << var_dt_ << ", ";
    label << "ident: " << var_ident_;
    label << "\n" << GetLocation().ToString();
    helper.WriteNode(GetId(), label.str());
    if (var_shape_) {
        var_shape_->Print(helper);
        helper.WriteEdge(GetId(), var_shape_->GetId(), "var_shape");
    }
    if (var_inti_lt_) {
        var_inti_lt_->Print(helper);
        helper.WriteEdge(GetId(), var_inti_lt_->GetId(), "init_lt");
    }
    if (expr_node_) {
        expr_node_->Print(helper);
        helper.WriteEdge(GetId(), expr_node_->GetId(), "assign_stmt");
    }
}

std::pair<mlir::LogicalResult, mlir::Value> AssignStatement::CodeGen(
    mlir::OpBuilder& builder,
    llvm::ScopedHashTable<mlir::StringRef, mlir::Value>& symbol_table) {
    if (!symbol_table.count(ident_)) {
        mlir::emitError(GetLocation().ToMLIRLocation(builder.getContext()))
            << ident_ << "does't exist!";
    }
    auto ret = value_->CodeGen(builder, symbol_table);
    if (ret.first.succeeded()) {
        // update symbol table
        symbol_table.insert(ident_, ret.second);
    }
    return {mlir::LogicalResult::success(), ret.second};
}

void AssignStatement::Print(DotHelper& helper) const {
    std::string label = "ident: ";
    label += ident_;
    label += "\n";
    label += GetLocation().ToString();
    helper.WriteNode(GetId(), label);
    value_->Print(helper);
    helper.WriteEdge(GetId(), value_->GetId(), "value");
}

Status SliceList::Append(int64_t lo, int64_t hi, Location loc) {
    assert(lo < hi && "lo must be less hi");
    idxs_.emplace_back(std::make_optional(lo), std::make_optional(hi));
    GetLocation().UpdateLocation(loc);
    return Status::TL_OK;
}

Status SliceList::Append(int64_t idx, Position pos, Location loc) {
    assert(pos == Position::TO_END && "pos must be TO_END");
    idxs_.emplace_back(std::make_optional(idx), std::nullopt);
    GetLocation().UpdateLocation(loc);
    return Status::TL_OK;
}

Status SliceList::Append(Position pos, int64_t idx, Location loc) {
    assert(pos == Position::TO_BEGIN && "pos must be TO_BEGIN");
    idxs_.emplace_back(std::nullopt, std::make_optional(idx));
    GetLocation().UpdateLocation(loc);
    return Status::TL_OK;
}

Status SliceList::Append(Position pos1, Position pos2, Location loc) {
    assert(pos1 == Position::TO_BEGIN && pos2 == Position::TO_END &&
           "pos1 must be TO_BEGIN and pos2 must be TO_END");
    idxs_.emplace_back(std::nullopt, std::nullopt);
    GetLocation().UpdateLocation(loc);
    return Status::TL_OK;
}

Status SliceList::Append(int64_t idx, Location loc) {
    return Append(idx, idx + 1, loc);
}

Status SliceList::Append(SliceList* left, SliceList* right) {
    if (left) {
        GetLocation().UpdateLocation(left->GetLocation());
        idxs_.insert(idxs_.end(), left->idxs_.begin(), left->idxs_.end());
    }

    if (right) {
        GetLocation().UpdateLocation(right->GetLocation());
        idxs_.insert(idxs_.end(), right->idxs_.begin(), right->idxs_.end());
    }

    return Status::TL_OK;
}

void SliceList::Print(DotHelper& helper) const {
    std::stringstream label;
    label << "name: " << GetName() << " ,idxs: [";
    for (size_t i = 0; i < idxs_.size(); ++i) {
        auto& e = idxs_[i];
        if (i != 0) {
            label << ", ";
        }
        if (e.first.has_value()) {
            label << e.first.value();
        } else {
            label << " ";
        }
        label << ":";
        if (e.second.has_value()) {
            label << e.second.value();
        } else {
            label << " ";
        }
    }
    label << "]";
    label << "\n" << GetLocation().ToString();
    helper.WriteNode(GetId(), label.str());
}

std::pair<mlir::LogicalResult, mlir::Value> SliceList::CodeGen(
    mlir::OpBuilder& builder,
    llvm::ScopedHashTable<mlir::StringRef, mlir::Value>& symbol_table) {
    return {mlir::LogicalResult::success(), nullptr};
}

std::pair<mlir::LogicalResult, mlir::Value> SliceExpression::CodeGen(
    mlir::OpBuilder& builder,
    llvm::ScopedHashTable<mlir::StringRef, mlir::Value>& symbol_table) {
    return {mlir::LogicalResult::success(), nullptr};
}

void SliceExpression::Print(DotHelper& helper) const {
    std::stringstream label;
    label << "name: " << GetName() << ", ";
    label << "ident: " << ident_;
    label << "\n" << GetLocation().ToString();
    helper.WriteNode(GetId(), label.str());
    slice_lt_->Print(helper);
    helper.WriteEdge(GetId(), slice_lt_->GetId(), "slice_lt");
}

void IfElseStatement::Print(DotHelper& helper) const {
    helper.WriteNode(GetId(), GetName() + "\n" + GetLocation().ToString());
    for (size_t i = 0; i < if_else_stmts_.size(); ++i) {
        auto& item = if_else_stmts_[i];
        if (item.first) {
            item.first->Print(helper);
            std::string label = "if_stmt_";
            label += std::to_string(i);
            helper.WriteEdge(GetId(), item.first->GetId(), label);
        }

        if (item.second) {
            item.second->Print(helper);
            std::string label = "if_block_";
            label += std::to_string(i);
            helper.WriteEdge(GetId(), item.second->GetId(), label);
        }
    }
}

std::pair<mlir::LogicalResult, mlir::Value> IfElseStatement::CodeGen(
    mlir::OpBuilder& builder,
    llvm::ScopedHashTable<mlir::StringRef, mlir::Value>& symbol_table) {
    return {mlir::LogicalResult::success(), nullptr};
}

Status IfElseStatement::Append(std::shared_ptr<ExpressionNode> en,
                               std::shared_ptr<Block> block) {
    if_else_stmts_.emplace_back(en, block);
    GetLocation().UpdateLocation(en->GetLocation());
    GetLocation().UpdateLocation(block->GetLocation());
    return Status::TL_OK;
}

Status IfElseStatement::Append(ExpressionNode* en, Block* block) {
    return Append(std::shared_ptr<ExpressionNode>(en),
                  std::shared_ptr<Block>(block));
}

Status IfElseStatement::Append(const std::shared_ptr<IfElseStatement>& other) {
    if (other) {
        if_else_stmts_.insert(if_else_stmts_.end(),
                              other->if_else_stmts_.begin(),
                              other->if_else_stmts_.end());
        GetLocation().UpdateLocation(other->GetLocation());
    }
    return Status::TL_OK;
}

Status IfElseStatement::Append(IfElseStatement* other) {
    return Append(std::shared_ptr<IfElseStatement>(other));
}

std::pair<mlir::LogicalResult, mlir::Value> WhileStatement::CodeGen(
    mlir::OpBuilder& builder,
    llvm::ScopedHashTable<mlir::StringRef, mlir::Value>& symbol_table) {
    return {mlir::LogicalResult::success(), nullptr};
}

void WhileStatement::Print(DotHelper& helper) const {
    helper.WriteNode(GetId(), GetName() + "\n" + GetLocation().ToString());
    expr_->Print(helper);
    helper.WriteEdge(GetId(), expr_->GetId(), "expr");
    if (block_) {
        block_->Print(helper);
        helper.WriteEdge(GetId(), block_->GetId(), "block");
    }
}

std::pair<mlir::LogicalResult, mlir::Value> ReturnStatement::CodeGen(
    mlir::OpBuilder& builder,
    llvm::ScopedHashTable<mlir::StringRef, mlir::Value>& symbol_table) {
    if (expr_) {
        auto val_p = expr_->CodeGen(builder, symbol_table);
        builder.create<tl::dialect::ReturnOp>(
            GetLocation().ToMLIRLocation(builder.getContext()), val_p.second);
    }
    return {mlir::LogicalResult::success(), nullptr};
}

void ReturnStatement::Print(DotHelper& helper) const {
    helper.WriteNode(GetId(), GetName() + "\n" + GetLocation().ToString());
    if (expr_) {
        expr_->Print(helper);
        helper.WriteEdge(GetId(), expr_->GetId(), "expr");
    }
}

std::pair<mlir::LogicalResult, mlir::Value> ArgumentList::CodeGen(
    mlir::OpBuilder& builder,
    llvm::ScopedHashTable<mlir::StringRef, mlir::Value>& symbol_table) {
    return {mlir::LogicalResult::success(), nullptr};
}
std::pair<mlir::SmallVector<mlir::StringRef>, mlir::SmallVector<mlir::Type>>
ArgumentList::ToArguments(mlir::OpBuilder& builder) const {
    // std::tuple<std::string, std::shared_ptr<SI64ListNode>, std::string>>
    mlir::SmallVector<mlir::StringRef> name_vec;
    mlir::SmallVector<mlir::Type> type_vec;
    for (auto& arg : args_) {
        auto& shape = std::get<1>(arg);
        type_vec.emplace_back(BuildType(
            builder, std::get<0>(arg),
            shape ? shape->ToSI64List() : mlir::ArrayRef<int64_t>(1)));
        const std::string& ident = std::get<2>(arg);
        name_vec.emplace_back(ident);
    }
    return {name_vec, type_vec};
}

Status ArgumentList::Append(const std::string& dt,
                            std::shared_ptr<SI64ListNode> shape,
                            const std::string& ident, Location loc) {
    args_.emplace_back(dt, shape, ident);
    if (shape) {
        GetLocation().UpdateLocation(shape->GetLocation());
    }
    GetLocation().UpdateLocation(loc);
    return Status::TL_OK;
}
Status ArgumentList::Append(std::shared_ptr<ArgumentList> other) {
    if (other) {
        args_.insert(args_.end(), other->args_.begin(), other->args_.end());
        GetLocation().UpdateLocation(other->GetLocation());
    }
    return Status::TL_OK;
}
void ArgumentList::Print(DotHelper& helper) const {
    helper.WriteNode(GetId(), GetName() + "\n" + GetLocation().ToString());
    //  std::tuple<std::string, std::shared_ptr<SI64ListNode>, std::string>>
    for (size_t i = 0; i < args_.size(); ++i) {
        auto& item = args_[i];
        auto& lt = std::get<1>(item);
        if (lt) {
            lt->Print(helper);
            std::stringstream label;
            label << "arg_" << i << ",";
            label << "dt:" << std::get<0>(item)
                  << ",ident:" << std::get<2>(item);
            helper.WriteEdge(GetId(), lt->GetId(), label.str());
        }
    }
}

std::pair<mlir::LogicalResult, mlir::Value> FunctionDeclaration::CodeGen(
    mlir::OpBuilder& builder,
    llvm::ScopedHashTable<mlir::StringRef, mlir::Value>& symbol_table) {
    mlir::RankedTensorType type =
        BuildType(builder, dt_,
                  (shape_ ? shape_->ToSI64List() : mlir::ArrayRef<int64_t>(1)));
    mlir::SmallVector<mlir::StringRef> name_arr;
    mlir::SmallVector<mlir::Type> type_arr;
    if (args_) {
        auto par = args_->ToArguments(builder);
        name_arr = par.first;
        type_arr = par.second;
    }

    llvm::ScopedHashTableScope<mlir::StringRef, mlir::Value> scope(
        symbol_table);
    auto func_type = builder.getFunctionType(type_arr, {type});
    auto func = builder.create<tl::dialect::FuncOp>(
        GetLocation().ToMLIRLocation(builder.getContext()), func_ident_,
        func_type);
    if (!func) {
        mlir::emitError(GetLocation().ToMLIRLocation(builder.getContext()))
            << "func decl error!";
    }
    auto& block = func.front();
    for (auto item : llvm::zip(name_arr, func.getArguments())) {
        if (symbol_table.count(std::get<0>(item))) {
            mlir::emitError(GetLocation().ToMLIRLocation(builder.getContext()))
                << std::get<0>(item) << " has already exists";
        }
        symbol_table.insert(std::get<0>(item), std::get<1>(item));
    }
    builder.setInsertionPointToEnd(&block);
    if (block_) {
        block_->CodeGen(builder, symbol_table);
    }
    return {mlir::LogicalResult::success(), nullptr};
}

void FunctionDeclaration::Print(DotHelper& helper) const {
    std::stringstream label;
    label << "data_type: " << dt_ << ", ";
    label << "func_ident: " << func_ident_;
    label << "\n" << GetLocation().ToString();
    helper.WriteNode(GetId(), label.str());

    if (shape_) {
        shape_->Print(helper);
        helper.WriteEdge(GetId(), shape_->GetId(), "shape");
    }

    if (args_) {
        args_->Print(helper);
        helper.WriteEdge(GetId(), args_->GetId(), "args");
    }

    if (block_) {
        block_->Print(helper);
        helper.WriteEdge(GetId(), block_->GetId(), "func body");
    }
}

std::pair<mlir::LogicalResult, mlir::Value> ExpressionList::CodeGen(
    mlir::OpBuilder& builder,
    llvm::ScopedHashTable<mlir::StringRef, mlir::Value>& symbol_table) {
    return {mlir::LogicalResult::success(), nullptr};
}

void ExpressionList::Print(DotHelper& helper) const {
    helper.WriteNode(GetId(), GetName() + "\n" + GetLocation().ToString());
    for (size_t i = 0; i < expr_lt_.size(); ++i) {
        auto& e = expr_lt_[i];
        e->Print(helper);
        std::string label = "expr_";
        label += std::to_string(i);
        helper.WriteEdge(GetId(), e->GetId(), label);
    }
}

Status ExpressionList::Append(std::shared_ptr<ExpressionNode> expr) {
    expr_lt_.emplace_back(expr);
    GetLocation().UpdateLocation(expr->GetLocation());
    return Status::TL_OK;
}

Status ExpressionList::Append(ExpressionNode* expr) {
    return Append(std::shared_ptr<ExpressionNode>(expr));
}

Status ExpressionList::Append(std::shared_ptr<ExpressionList> other) {
    if (other) {
        expr_lt_.insert(expr_lt_.end(), other->expr_lt_.begin(),
                        other->expr_lt_.end());
        GetLocation().UpdateLocation(other->GetLocation());
    }
    return Status::TL_OK;
}

Status ExpressionList::Append(ExpressionList* other) {
    return Append(std::shared_ptr<ExpressionList>(other));
}

std::pair<mlir::LogicalResult, mlir::Value> FunctionCall::CodeGen(
    mlir::OpBuilder& builder,
    llvm::ScopedHashTable<mlir::StringRef, mlir::Value>& symbol_table) {
    mlir::SmallVector<mlir::Value, 5> value_vec;
    for (auto arg : args_->expr_lt_) {
        auto val_p = arg->CodeGen(builder, symbol_table);
        value_vec.emplace_back(val_p.second);
    }
    auto value = builder.create<tl::dialect::GenericCallOp>(
        GetLocation().ToMLIRLocation(builder.getContext()), func_ident_,
        value_vec);

    return {mlir::LogicalResult::success(), value};
}

void FunctionCall::Print(DotHelper& helper) const {
    std::stringstream label;
    label << "name: " << GetName() << ", func_ident: " << func_ident_;
    label << "\n" << GetLocation().ToString();
    helper.WriteNode(GetId(), label.str());
    if (args_) {
        args_->Print(helper);
        helper.WriteEdge(GetId(), args_->GetId(), "args");
    }
}

std::pair<mlir::LogicalResult, mlir::Value> BreakStatement::CodeGen(
    mlir::OpBuilder& builder,
    llvm::ScopedHashTable<mlir::StringRef, mlir::Value>& symbol_table) {
    return {mlir::LogicalResult::success(), nullptr};
}

}  // namespace common
}  // namespace tl