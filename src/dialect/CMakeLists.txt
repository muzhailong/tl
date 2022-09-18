set(DIALECT_OBJ mlir_obj)

set(LLVM_TARGET_DEFINITIONS
    ${CMAKE_CURRENT_SOURCE_DIR}/tl_ops.td
)

set(TMP_TARGET_DIR ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_CURRENT_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR})

mlir_tablegen(ops.hpp.inc -gen-op-decls)
mlir_tablegen(ops.cpp.inc -gen-op-defs)
mlir_tablegen(dialect.hpp.inc -gen-dialect-decls)
mlir_tablegen(dialect.cpp.inc -gen-dialect-defs)

add_public_tablegen_target(TLOpsIncGen)

set(CMAKE_CURRENT_BINARY_DIR ${TMP_TARGET_DIR})
unset(TMP_TARGET_DIR)

add_library(${DIALECT_OBJ}
    ${CMAKE_CURRENT_SOURCE_DIR}/dialect.cpp
)
add_compile_options(
)
target_link_libraries(${DIALECT_OBJ}
    ${llvm_libs}
    MLIRAnalysis
    MLIRIR
    MLIRParser
    MLIRSideEffectInterfaces
    MLIRDialectUtils
)
add_dependencies(${DIALECT_OBJ} TLOpsIncGen)

set_property(GLOBAL APPEND PROPERTY ${LIB_NAME}_DIALECT_DEPS $<TARGET_OBJECTS:${DIALECT_OBJ}>)
