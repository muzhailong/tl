#ifndef COMMON_NODE_HPP
#define COMMON_NODE_HPP

#include <llvm/ADT/ScopedHashTable.h>
#include <mlir/IR/Attributes.h>
#include <mlir/IR/Builders.h>
#include <mlir/IR/BuiltinOps.h>
#include <mlir/IR/MLIRContext.h>
#include <mlir/IR/Types.h>
#include <mlir/IR/Value.h>
#include <mlir/IR/Verifier.h>

#include <cassert>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

#include "common/dot.hpp"
#include "common/id.hpp"
#include "common/location.hpp"
#include "common/status.hpp"
#include "common/token.hpp"
#include "common/utils.hpp"
#include "dialect/dialect.hpp"

namespace tl {
namespace common {

using OP_KIND = int64_t;

class Node : public Id {
public:
    Node(const std::string& name, const Location& loc)
        : name_(name), loc_(loc) {}

    virtual ~Node() = default;

    virtual std::pair<mlir::LogicalResult, mlir::Value> CodeGen(
        mlir::OpBuilder& builder,
        llvm::ScopedHashTable<mlir::StringRef, mlir::Value>&) = 0;

    virtual void Print(DotHelper&) const = 0;

    std::string GetName() const { return name_; }
    Location& GetLocation() { return loc_; }
    Location GetLocation() const { return loc_; }

private:
    const std::string name_;
    Location loc_;
};

template <typename Tp>
class LiteralNode : public Node {
public:
    LiteralNode(const std::string& name, const Location& loc, Tp value)
        : Node(name, loc), value_(value) {}

    virtual std::pair<mlir::LogicalResult, mlir::Value> CodeGen(
        mlir::OpBuilder& builder,
        llvm::ScopedHashTable<mlir::StringRef, mlir::Value>&) override {
        if constexpr (std::is_same_v<Tp, int64_t>) {
            auto op = builder.create<tl::dialect::ConstantOp>(
                GetLocation().ToMLIRLocation(builder.getContext()), value_);
            return {mlir::LogicalResult::success(), op};
        }

        return {mlir::LogicalResult::success(), nullptr};
    }

    void Print(DotHelper& helper) const override {
        std::stringstream label;
        label << "name:" << GetName() << ", value=";
        label << value_;
        label << "\n" << GetLocation().ToString();
        helper.WriteNode(GetId(), label.str());
    }

private:
    Tp value_;
};

using SI64Node = LiteralNode<int64_t>;
using FP64Node = LiteralNode<double>;
using StrNode = LiteralNode<std::string>;

class FunctionDeclaration;

class ModuleNode : public Node {
public:
    ModuleNode(const std::string& name, const Location& loc)
        : Node(name, loc) {}

    Status Append(FunctionDeclaration* func);
    virtual std::pair<mlir::LogicalResult, mlir::Value> CodeGen(
        mlir::OpBuilder& builder,
        llvm::ScopedHashTable<mlir::StringRef, mlir::Value>&) override;
    virtual void Print(DotHelper& helper) const override;

    std::optional<mlir::ModuleOp> GetModule() { return the_module_; }

private:
    std::vector<std::shared_ptr<FunctionDeclaration>> funcs_;
    std::optional<mlir::ModuleOp> the_module_;
};

class ExpressionNode : public Node {
public:
    ExpressionNode(const std::string& name, const Location& loc,
                   std::shared_ptr<Node> lhs, OP_KIND op,
                   std::shared_ptr<Node> rhs)
        : Node(name, loc), lhs_(lhs), rhs_(rhs), op_(op) {}

    virtual std::pair<mlir::LogicalResult, mlir::Value> CodeGen(
        mlir::OpBuilder& builder,
        llvm::ScopedHashTable<mlir::StringRef, mlir::Value>&) override;
    virtual void Print(DotHelper& helper) const override;

private:
    std::shared_ptr<Node> lhs_;
    std::shared_ptr<Node> rhs_;
    OP_KIND op_;
};

class Block : public Node {
public:
    using SizeType = size_t;
    Block(const std::string& name, const Location& loc) : Node(name, loc) {}

    Status Append(std::shared_ptr<Node> node);
    Status Append(Node* node);
    SizeType size() const { return nodes_.size(); }

    std::pair<mlir::LogicalResult, mlir::Value> CodeGen(
        mlir::OpBuilder& builder,
        llvm::ScopedHashTable<mlir::StringRef, mlir::Value>&) override;
    void Print(DotHelper& helper) const override;

private:
    std::vector<std::shared_ptr<Node>> nodes_;
};

template <typename Tp>
class ListNode : public Node {
public:
    using ElementType = Tp;
    ListNode(const std::string& name, const Location& loc) : Node(name, loc) {}

    std::pair<mlir::LogicalResult, mlir::Value> CodeGen(
        mlir::OpBuilder& builder,
        llvm::ScopedHashTable<mlir::StringRef, mlir::Value>&) override {
        return {mlir::LogicalResult::success(), nullptr};
    }

    mlir::ArrayRef<int64_t> ToSI64List() { return value_; }

    mlir::ArrayRef<double> ToFP64List() { return value_; }

    mlir::ArrayRef<std::string> ToStrList() { return value_; }

    void Print(DotHelper& helper) const override {
        std::stringstream ss;
        ss << "name: " << GetName();
        if (!value_.empty()) {
            ss << ", list: " << ToStr();
        }
        ss << "\n" << GetLocation().ToString();
        helper.WriteNode(GetId(), ss.str());
    }

    Status Append(Tp d, Location loc) {
        value_.push_back(d);
        GetLocation().UpdateLocation(loc);
        return Status::TL_OK;
    }
    std::string ToStr() const { return Vec2Str<Tp>(value_); }

private:
    std::vector<Tp> value_;
};

using SI64ListNode = ListNode<int64_t>;
using FP64ListNode = ListNode<double>;
using STRListNode = ListNode<std::string>;

/*
    ui8 [12,22] abc{};
*/

class IdentifierNode : public Node {
public:
    IdentifierNode(const std::string& name, const Location& loc,
                   const std::string& ident)
        : Node(name, loc), ident_(ident) {}
    std::pair<mlir::LogicalResult, mlir::Value> CodeGen(
        mlir::OpBuilder& builder,
        llvm::ScopedHashTable<mlir::StringRef, mlir::Value>&) override;
    void Print(DotHelper& helper) const override;
    std::string GetIdent() const { return ident_; }

private:
    const std::string ident_;
};

class VarDeclarationNode : public Node {
public:
    VarDeclarationNode(const std::string& name, const Location& loc,
                       const std::string& var_dt,
                       std::shared_ptr<SI64ListNode> var_shape,
                       const std::string& var_ident,
                       std::shared_ptr<Node> var_inti_lt,
                       std::shared_ptr<ExpressionNode> expr_node)
        : Node(name, loc),
          var_dt_(var_dt),
          var_shape_(var_shape),
          var_ident_(var_ident),
          var_inti_lt_(var_inti_lt),
          expr_node_(expr_node) {}

    std::pair<mlir::LogicalResult, mlir::Value> CodeGen(
        mlir::OpBuilder& builder,
        llvm::ScopedHashTable<mlir::StringRef, mlir::Value>&) override;
    void Print(DotHelper& helper) const override;

private:
    const std::string var_dt_;
    std::shared_ptr<SI64ListNode> var_shape_;
    const std::string var_ident_;
    std::shared_ptr<Node> var_inti_lt_;
    std::shared_ptr<ExpressionNode> expr_node_;
};

class AssignStatement : public Node {
public:
    AssignStatement(const std::string& name, const Location& loc,
                    const std::string& ident,
                    std::shared_ptr<ExpressionNode> value)
        : Node(name, loc), ident_(ident), value_(value) {}

    std::pair<mlir::LogicalResult, mlir::Value> CodeGen(
        mlir::OpBuilder& builder,
        llvm::ScopedHashTable<mlir::StringRef, mlir::Value>&) override;
    void Print(DotHelper& helper) const override;

private:
    const std::string ident_;
    std::shared_ptr<ExpressionNode> value_;
};

class SliceList : public Node {
public:
    enum class Position { TO_END, TO_BEGIN };

    SliceList(const std::string& name, const Location& loc) : Node(name, loc) {}

    Status Append(int64_t lo, int64_t hi, Location);
    Status Append(int64_t idx, Position pos, Location);
    Status Append(Position pos, int64_t idx, Location);
    Status Append(Position pos1, Position pos2, Location);
    Status Append(int64_t idx, Location);
    Status Append(SliceList* left, SliceList* right);

    std::pair<mlir::LogicalResult, mlir::Value> CodeGen(
        mlir::OpBuilder& builder,
        llvm::ScopedHashTable<mlir::StringRef, mlir::Value>&) override;
    void Print(DotHelper& helper) const override;

private:
    std::vector<std::pair<std::optional<int64_t>, std::optional<int64_t>>>
        idxs_;
};

class SliceExpression : public Node {
public:
    SliceExpression(const std::string& name, const Location& loc,
                    const std::string& ident,
                    std::shared_ptr<SliceList> slice_lt)
        : Node(name, loc), ident_(ident), slice_lt_(slice_lt) {}

    std::pair<mlir::LogicalResult, mlir::Value> CodeGen(
        mlir::OpBuilder& builder,
        llvm::ScopedHashTable<mlir::StringRef, mlir::Value>&) override;
    void Print(DotHelper& helper) const override;

private:
    const std::string ident_;
    std::shared_ptr<SliceList> slice_lt_;
};

class IfElseStatement : public Node {
public:
    IfElseStatement(const std::string& name, const Location& loc)
        : Node(name, loc) {}

    std::pair<mlir::LogicalResult, mlir::Value> CodeGen(
        mlir::OpBuilder& builder,
        llvm::ScopedHashTable<mlir::StringRef, mlir::Value>&) override;

    void Print(DotHelper& helper) const override;

    Status Append(std::shared_ptr<ExpressionNode> en,
                  std::shared_ptr<Block> block);
    Status Append(ExpressionNode* en, Block* block);
    Status Append(const std::shared_ptr<IfElseStatement>& other);
    Status Append(IfElseStatement* other);

private:
    std::vector<
        std::pair<std::shared_ptr<ExpressionNode>, std::shared_ptr<Block>>>
        if_else_stmts_;
};

class WhileStatement : public Node {
public:
    WhileStatement(const std::string& name, const Location& loc,
                   std::shared_ptr<ExpressionNode> expr,
                   std::shared_ptr<Block> block)
        : Node(name, loc), expr_(expr), block_(block) {}

    std::pair<mlir::LogicalResult, mlir::Value> CodeGen(
        mlir::OpBuilder& builder,
        llvm::ScopedHashTable<mlir::StringRef, mlir::Value>&) override;
    void Print(DotHelper& helper) const override;

private:
    std::shared_ptr<ExpressionNode> expr_;
    std::shared_ptr<Block> block_;
};

class ReturnStatement : public Node {
public:
    ReturnStatement(const std::string& name, const Location& loc,
                    std::shared_ptr<ExpressionNode> expr)
        : Node(name, loc), expr_(expr) {}

    std::pair<mlir::LogicalResult, mlir::Value> CodeGen(
        mlir::OpBuilder& builder,
        llvm::ScopedHashTable<mlir::StringRef, mlir::Value>&) override;
    void Print(DotHelper& helper) const override;

private:
    std::shared_ptr<ExpressionNode> expr_;
};

class ArgumentList : public Node {
public:
    ArgumentList(const std::string& name, const Location& loc)
        : Node(name, loc) {}
    std::pair<mlir::LogicalResult, mlir::Value> CodeGen(
        mlir::OpBuilder& builder,
        llvm::ScopedHashTable<mlir::StringRef, mlir::Value>&) override;
    std::pair<mlir::SmallVector<mlir::StringRef>, mlir::SmallVector<mlir::Type>>
    ToArguments(mlir::OpBuilder& builder) const;

    Status Append(const std::string& dt, std::shared_ptr<SI64ListNode> shape,
                  const std::string& ident, Location loc);
    Status Append(std::shared_ptr<ArgumentList> other);

    void Print(DotHelper& helper) const override;

private:
    std::vector<
        std::tuple<std::string, std::shared_ptr<SI64ListNode>, std::string>>
        args_;
};

// si64[32,22] func(){}
class FunctionDeclaration : public Node {
public:
    FunctionDeclaration(const std::string& name, const Location& loc,
                        const std::string& dt,
                        std::shared_ptr<SI64ListNode> shape,
                        const std::string& func_ident,
                        std::shared_ptr<ArgumentList> args,
                        std::shared_ptr<Block> block)
        : Node(name, loc),
          dt_(dt),
          shape_(shape),
          func_ident_(func_ident),
          args_(args),
          block_(block) {}

    std::pair<mlir::LogicalResult, mlir::Value> CodeGen(
        mlir::OpBuilder& builder,
        llvm::ScopedHashTable<mlir::StringRef, mlir::Value>&) override;
    void Print(DotHelper& helper) const override;

private:
    const std::string dt_;
    std::shared_ptr<SI64ListNode> shape_;
    const std::string func_ident_;
    std::shared_ptr<ArgumentList> args_;
    std::shared_ptr<Block> block_;
};

class ExpressionList : public Node {
public:
    ExpressionList(const std::string& name, const Location& loc)
        : Node(name, loc) {}

    std::pair<mlir::LogicalResult, mlir::Value> CodeGen(
        mlir::OpBuilder& builder,
        llvm::ScopedHashTable<mlir::StringRef, mlir::Value>&) override;
    void Print(DotHelper& helper) const override;

    Status Append(std::shared_ptr<ExpressionNode> expr);
    Status Append(ExpressionNode* expr);
    Status Append(std::shared_ptr<ExpressionList> other);
    Status Append(ExpressionList* other);

private:
    friend class FunctionCall;

    std::vector<std::shared_ptr<ExpressionNode>> expr_lt_;
};

class FunctionCall : public Node {
public:
    FunctionCall(const std::string& name, const Location& loc,
                 const std::string& func_ident,
                 std::shared_ptr<ExpressionList> args)
        : Node(name, loc), func_ident_(func_ident), args_(args) {}

    std::pair<mlir::LogicalResult, mlir::Value> CodeGen(
        mlir::OpBuilder& builder,
        llvm::ScopedHashTable<mlir::StringRef, mlir::Value>&) override;
    void Print(DotHelper& helper) const override;

private:
    const std::string func_ident_;
    std::shared_ptr<ExpressionList> args_;
};

class BreakStatement : public Node {
public:
    BreakStatement(const std::string& name, const Location& loc)
        : Node(name, loc) {}

    std::pair<mlir::LogicalResult, mlir::Value> CodeGen(
        mlir::OpBuilder& builder,
        llvm::ScopedHashTable<mlir::StringRef, mlir::Value>&) override;

    void Print(DotHelper& helper) const override {
        helper.WriteNode(GetId(), GetName());
    }
};

}  // namespace common
}  // namespace tl

#endif
