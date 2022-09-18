#ifndef MLIR_DIALECT_DIALECT_HPP
#define MLIR_DIALECT_DIALECT_HPP

#include "mlir/IR/Dialect.h"
#include "mlir/IR/FunctionInterfaces.h"
#include "mlir/IR/SymbolTable.h"
#include "mlir/Interfaces/CallInterfaces.h"
#include "mlir/Interfaces/SideEffectInterfaces.h"

using mlir::ArrayRef;
using mlir::DenseElementsAttr;
using mlir::FunctionType;
using mlir::NamedAttribute;
using mlir::StringRef;
using mlir::Type;
using mlir::Value;

/// Include the auto-generated header file containing the declaration of the toy
/// dialect.
#include "dialect/dialect.hpp.inc"

/// Include the auto-generated header file containing the declarations of the
/// toy operations.
#define GET_OP_CLASSES
#include "dialect/ops.hpp.inc"

#endif
