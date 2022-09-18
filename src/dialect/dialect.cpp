// clang-format off
#include "dialect/dialect.hpp"

#include "mlir/IR/Builders.h"
#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/FunctionImplementation.h"
#include "mlir/IR/OpImplementation.h"
#include "mlir/Support/LogicalResult.h"
#include "mlir/IR/Diagnostics.h"

#include "dialect/dialect.cpp.inc"
// clang-format on

#define GET_OP_CLASSES
#include "dialect/ops.cpp.inc"

namespace tl {
namespace dialect {

void TLDialect::initialize() {
    addOperations<
#define GET_OP_LIST
#include "dialect/ops.cpp.inc"
        >();
}

//===----------------------------------------------------------------------===//
// ConstantOp
//===----------------------------------------------------------------------===//

void ConstantOp::build(mlir::OpBuilder& builder, mlir::OperationState& state,
                       double value) {
    auto dataType = mlir::RankedTensorType::get({}, builder.getF64Type());
    auto dataAttribute = mlir::DenseElementsAttr::get(dataType, value);
    build(builder, state, dataType, dataAttribute);
}

mlir::LogicalResult ConstantOp::verify() {
    auto resultType = getResult().getType().dyn_cast<mlir::RankedTensorType>();
    if (!resultType) {
        return mlir::success();
    }
    auto attrType = value().getType().cast<mlir::TensorType>();
    if (attrType.getRank() != resultType.getRank()) {
        return mlir::emitError(getLoc()) << "return type must match the one of "
                                            "the attached value attribute";
    }

    for (int64_t dim = 0; dim < attrType.getRank(); ++dim) {
        if (attrType.getShape()[dim] != resultType.getShape()[dim]) {
            return mlir::emitError(getLoc())
                   << "result type shape mismatchs its attribute at dimension";
        }
    }
    return mlir::success();
}

//===----------------------------------------------------------------------===//
// AddOp
//===----------------------------------------------------------------------===//
void AddOp::build(mlir::OpBuilder& builder, mlir::OperationState& state,
                  mlir::Value lhs, mlir::Value rhs) {
    state.addTypes(mlir::UnrankedTensorType::get(builder.getF64Type()));
    state.addOperands({lhs, rhs});
}

//===----------------------------------------------------------------------===//
// GenericCallOp
//===----------------------------------------------------------------------===//
void GenericCallOp::build(mlir::OpBuilder& builder, mlir::OperationState& state,
                          mlir::StringRef callee,
                          mlir::ArrayRef<mlir::Value> arguments) {
    state.addTypes(mlir::UnrankedTensorType::get(builder.getF64Type()));
    state.addOperands(arguments);
    state.addAttribute("callee",
                       mlir::SymbolRefAttr::get(builder.getContext(), callee));
}

//===----------------------------------------------------------------------===//
// FuncOp
//===----------------------------------------------------------------------===//
void FuncOp::build(mlir::OpBuilder& builder, mlir::OperationState& state,
                   llvm::StringRef name, mlir::FunctionType type,
                   llvm::ArrayRef<mlir::NamedAttribute> attrs) {
    buildWithEntryBlock(builder, state, name, type, attrs, type.getInputs());
}

//===----------------------------------------------------------------------===//
// MulOp
//===----------------------------------------------------------------------===//
void MulOp::build(mlir::OpBuilder& builder, mlir::OperationState& state,
                  mlir::Value lhs, mlir::Value rhs) {
    state.addOperands({lhs, rhs});
    state.addTypes(mlir::UnrankedTensorType::get(builder.getF64Type()));
}

//===----------------------------------------------------------------------===//
// PintOp
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// ReturnOp
//===----------------------------------------------------------------------===//
mlir::LogicalResult ReturnOp::verify() {
    auto function = mlir::cast<FuncOp>(getOperation()->getParentOp());
    if (getNumOperands() > 1) {
        return mlir::emitError(getLoc()) << "expects at most 1 return operand";
    }

    const auto& results = function.function_type().getResults();
    if (getNumOperands() != results.size()) {
        return mlir::emitError(getLoc())
               << "function argument and return number mismatch";
    }
    if (!hasOperand()) {
        return mlir::success();
    }

    auto inputType = *operand_type_begin();
    auto resultType = results.front();
    if (inputType == resultType || inputType.isa<mlir::UnrankedTensorType>() ||
        resultType.isa<mlir::UnrankedTensorType>()) {
        return mlir::success();
    }
    return mlir::emitError(getLoc()) << "type mismatch";
}

//===----------------------------------------------------------------------===//
// TransposeOp
//===----------------------------------------------------------------------===//
void TransposeOp::build(mlir::OpBuilder& builder, mlir::OperationState& state,
                        mlir::Value value) {
    state.addTypes(mlir::UnrankedTensorType::get(builder.getF64Type()));
    state.addOperands(value);
}

mlir::LogicalResult TransposeOp::verify() {
    auto inputType = getOperand().getType().dyn_cast<mlir::RankedTensorType>();
    auto resultType = getType().dyn_cast<mlir::RankedTensorType>();
    if (!inputType || !resultType) {
        return mlir::success();
    }
    auto inputShape = inputType.getShape();
    if (!std::equal(inputShape.begin(), inputShape.end(),
                    resultType.getShape().rbegin())) {
        return mlir::emitError(getLoc()) << "type mismatch";
    }
    return mlir::success();
}

}  // namespace dialect
}  // namespace tl