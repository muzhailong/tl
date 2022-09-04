#ifndef COMMON_NODE_HPP
#define COMMON_NODE_HPP

#include <llvm/IR/Value.h>

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
#include "common/status.hpp"
#include "common/token.hpp"
#include "common/utils.hpp"

namespace tl {
namespace common {

using OP_KIND = int64_t;

class CodeGenContext;

class Node : public Id {
public:
    Node(const std::string& name) : name_(name) {}

    virtual ~Node() = default;

    virtual std::shared_ptr<llvm::Value> CodeGen(CodeGenContext& context) = 0;

    virtual void Print(DotHelper&) const = 0;

    std::string GetName() const { return name_; }

private:
    const std::string name_;
};

template <typename Tp>
class LiteralNode : public Node {
public:
    LiteralNode(const std::string& name, Tp value)
        : Node(name), value_(value) {}
    LiteralNode(Tp value) : LiteralNode("literal_node", value) {}

    std::shared_ptr<llvm::Value> CodeGen(CodeGenContext&) override {
        return nullptr;
    }

    void Print(DotHelper& helper) const override {
        std::stringstream label;
        label << "name:" << GetName() << ", value=";
        label << value_;
        helper.WriteNode(GetId(), label.str());
    }

private:
    Tp value_;
};

using SI64Node = LiteralNode<int64_t>;
using FP64Node = LiteralNode<double>;
using StrNode = LiteralNode<std::string>;

class IdentifierNode : public Node {
public:
    IdentifierNode(const std::string& name, const std::string& ident)
        : Node(name), ident_(ident) {}
    IdentifierNode(const std::string& ident)
        : IdentifierNode("ident_node", ident) {}

    std::shared_ptr<llvm::Value> CodeGen(CodeGenContext&) override {
        return nullptr;
    }

    void Print(DotHelper& helper) const override {
        std::string label = "";
        label += "name:";
        label += GetName();
        label += ", ident=";
        label += ident_;
        helper.WriteNode(GetId(), label);
    }

private:
    const std::string ident_;
};

class ExpressionNode : public Node {
public:
    ExpressionNode(const std::string& name, std::shared_ptr<Node> lhs,
                   OP_KIND op, std::shared_ptr<Node> rhs)
        : Node(name), lhs_(lhs), rhs_(rhs), op_(op) {}
    ExpressionNode(std::shared_ptr<Node> lhs, OP_KIND op,
                   std::shared_ptr<Node> rhs)
        : ExpressionNode("expression_node", lhs, op, rhs) {}
    ExpressionNode(Node* lhs, OP_KIND op, Node* rhs)
        : ExpressionNode(std::shared_ptr<Node>(lhs), op,
                         std::shared_ptr<Node>(rhs)) {}

    std::shared_ptr<llvm::Value> CodeGen(CodeGenContext&) override {
        return nullptr;
    }

    void Print(DotHelper& helper) const override {
        std::stringstream ss;
        ss << "name: " << GetName();
        if (op_ > 0 && lhs_ && rhs_) {
            ss << ", op: " << TokenId2Str(op_);
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

private:
    std::shared_ptr<Node> lhs_;
    std::shared_ptr<Node> rhs_;
    OP_KIND op_;
};

class Block : public Node {
public:
    using SizeType = size_t;
    Block(const std::string& name) : Node(name) {}
    Block() : Block("block") {}

    Status AppendNode(std::shared_ptr<Node> node) {
        nodes_.emplace_back(node);
        return Status::TL_OK;
    }

    Status AppendNode(Node* node) {
        return AppendNode(std::shared_ptr<Node>(node));
    }

    SizeType size() const { return nodes_.size(); }

    std::shared_ptr<llvm::Value> CodeGen(CodeGenContext&) override {
        return nullptr;
    }

    void Print(DotHelper& helper) const override {
        helper.WriteNode(GetId(), GetName());
        for (auto& node : nodes_) {
            node->Print(helper);
            helper.WriteEdge(GetId(), node->GetId(), "sub_node");
        }
    }

private:
    std::vector<std::shared_ptr<Node>> nodes_;
};

template <typename Tp>
class ListNode : public Node {
public:
    using ElementType = Tp;
    ListNode(const std::string& name) : Node(name) {}
    ListNode() : ListNode("list_node") {}

    std::shared_ptr<llvm::Value> CodeGen(CodeGenContext&) override {
        return nullptr;
    }

    void Print(DotHelper& helper) const override {
        std::stringstream ss;
        ss << "name: " << GetName();
        if (!value_.empty()) {
            ss << ", list: " << ToStr();
        }
        helper.WriteNode(GetId(), ss.str());
    }

    Status Append(Tp d) {
        value_.push_back(d);
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

class VarDeclarationNode : public Node {
public:
    VarDeclarationNode(const std::string& name, const std::string& var_dt,
                       std::shared_ptr<SI64ListNode> var_shape,
                       const std::string& var_ident,
                       std::shared_ptr<Node> var_inti_lt,
                       std::shared_ptr<ExpressionNode> expr_node)
        : Node(name),
          var_dt_(var_dt),
          var_shape_(var_shape),
          var_ident_(var_ident),
          var_inti_lt_(var_inti_lt),
          expr_node_(expr_node) {}

    VarDeclarationNode(const std::string& var_dt, SI64ListNode* var_shape,
                       const std::string& var_ident, Node* var_inti_lt)
        : VarDeclarationNode(
              "var_decl_node", var_dt, std::shared_ptr<SI64ListNode>(var_shape),
              var_ident, std::shared_ptr<Node>(var_inti_lt), nullptr) {}

    VarDeclarationNode(const std::string& var_dt, SI64ListNode* var_shape,
                       const std::string& var_ident, ExpressionNode* expr_node)
        : VarDeclarationNode(
              "var_decl_node", var_dt, std::shared_ptr<SI64ListNode>(var_shape),
              var_ident, nullptr, std::shared_ptr<ExpressionNode>(expr_node)) {}

    std::shared_ptr<llvm::Value> CodeGen(CodeGenContext&) override {
        return nullptr;
    }

    void Print(DotHelper& helper) const override {
        std::stringstream label;
        label << "dt: " << var_dt_ << ", ";
        label << "ident: " << var_ident_;
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

private:
    const std::string var_dt_;
    std::shared_ptr<SI64ListNode> var_shape_;
    const std::string var_ident_;
    std::shared_ptr<Node> var_inti_lt_;
    std::shared_ptr<ExpressionNode> expr_node_;
};

class AssignStatement : public Node {
public:
    AssignStatement(const std::string& name, const std::string& ident,
                    std::shared_ptr<ExpressionNode> value)
        : Node(name), ident_(ident), value_(value) {}

    AssignStatement(const std::string& ident,
                    std::shared_ptr<ExpressionNode> value)
        : AssignStatement("assign_statement", ident, value) {}

    AssignStatement(const std::string& ident, ExpressionNode* value)
        : AssignStatement(ident, std::shared_ptr<ExpressionNode>(value)) {}

    std::shared_ptr<llvm::Value> CodeGen(CodeGenContext&) override {
        return nullptr;
    }

    void Print(DotHelper& helper) const override {
        std::string label = "ident: ";
        label += ident_;
        helper.WriteNode(GetId(), label);
        value_->Print(helper);
        helper.WriteEdge(GetId(), value_->GetId(), "value");
    }

private:
    const std::string ident_;
    std::shared_ptr<ExpressionNode> value_;
};

class SliceList : public Node {
public:
    enum class Position { TO_END, TO_BEGIN };

    SliceList() : Node("slice_list") {}

    Status AppendIndex(int64_t lo, int64_t hi) {
        assert(lo < hi && "lo must be less hi");
        idxs_.emplace_back(std::make_optional(lo), std::make_optional(hi));
        return Status::TL_OK;
    }

    Status AppendIndex(int64_t idx, Position pos) {
        assert(pos == Position::TO_END && "pos must be TO_END");
        idxs_.emplace_back(std::make_optional(idx), std::nullopt);
        return Status::TL_OK;
    }

    Status AppendIndex(Position pos, int64_t idx) {
        assert(pos == Position::TO_BEGIN && "pos must be TO_BEGIN");
        idxs_.emplace_back(std::nullopt, std::make_optional(idx));
        return Status::TL_OK;
    }

    Status AppendIndex(Position pos1, Position pos2) {
        assert(pos1 == Position::TO_BEGIN && pos2 == Position::TO_END &&
               "pos1 must be TO_BEGIN and pos2 must be TO_END");
        idxs_.emplace_back(std::nullopt, std::nullopt);
        return Status::TL_OK;
    }

    Status AppendIndex(int64_t idx) { return AppendIndex(idx, idx + 1); }

    Status AppendIndex(SliceList* left, SliceList* right) {
        if (left) {
            idxs_.insert(idxs_.end(), left->idxs_.begin(), left->idxs_.end());
        }

        if (right) {
            idxs_.insert(idxs_.end(), right->idxs_.begin(), right->idxs_.end());
        }

        return Status::TL_OK;
    }

    std::shared_ptr<llvm::Value> CodeGen(CodeGenContext&) override {
        return nullptr;
    }

    void Print(DotHelper& helper) const override {
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
        helper.WriteNode(GetId(), label.str());
    }

private:
    std::vector<std::pair<std::optional<int64_t>, std::optional<int64_t>>>
        idxs_;
};

class SliceExpression : public Node {
public:
    SliceExpression(const std::string& name, const std::string& ident,
                    std::shared_ptr<SliceList> slice_lt)
        : Node(name), ident_(ident), slice_lt_(slice_lt) {}

    SliceExpression(const std::string& ident,
                    std::shared_ptr<SliceList> slice_lt)
        : SliceExpression("slice_expr", ident, slice_lt) {}

    SliceExpression(const std::string& ident, SliceList* slice_lt)
        : SliceExpression(ident, std::shared_ptr<SliceList>(slice_lt)) {}

    std::shared_ptr<llvm::Value> CodeGen(CodeGenContext&) override {
        return nullptr;
    }

    void Print(DotHelper& helper) const override {
        std::stringstream label;
        label << "name: " << GetName() << ", ";
        label << "ident: " << ident_;
        helper.WriteNode(GetId(), label.str());
        slice_lt_->Print(helper);
        helper.WriteEdge(GetId(), slice_lt_->GetId(), "slice_lt");
    }

private:
    const std::string ident_;
    std::shared_ptr<SliceList> slice_lt_;
};

class IfElseStatement : public Node {
public:
    IfElseStatement(const std::string& name) : Node(name) {}
    IfElseStatement() : IfElseStatement("if_else_stmt") {}

    std::shared_ptr<llvm::Value> CodeGen(CodeGenContext&) override {
        return nullptr;
    }

    void Print(DotHelper& helper) const override {
        helper.WriteNode(GetId(), GetName());
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

    Status AppendIfElse(std::shared_ptr<ExpressionNode> en,
                        std::shared_ptr<Block> block) {
        if_else_stmts_.emplace_back(en, block);
        return Status::TL_OK;
    }

    Status AppendIfElse(ExpressionNode* en, Block* block) {
        return AppendIfElse(std::shared_ptr<ExpressionNode>(en),
                            std::shared_ptr<Block>(block));
    }

    Status AppendIfElse(const std::shared_ptr<IfElseStatement>& other) {
        if (other) {
            if_else_stmts_.insert(if_else_stmts_.end(),
                                  other->if_else_stmts_.begin(),
                                  other->if_else_stmts_.end());
        }
        return Status::TL_OK;
    }

    Status AppendIfElse(IfElseStatement* other) {
        return AppendIfElse(std::shared_ptr<IfElseStatement>(other));
    }

private:
    std::vector<
        std::pair<std::shared_ptr<ExpressionNode>, std::shared_ptr<Block>>>
        if_else_stmts_;
};

}  // namespace common
}  // namespace tl

#endif
