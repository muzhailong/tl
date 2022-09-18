set(MAIN_OBJ main_obj)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lex)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/syntax)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/common)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/dialect)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lex)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/syntax)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/common)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/dialect)

get_property(SYNTAX_DEPS GLOBAL PROPERTY ${LIB_NAME}_SYNTAX_DEPS)
get_property(LEX_DEPS GLOBAL PROPERTY ${LIB_NAME}_LEX_DEPS)
get_property(COMMON_DEPS GLOBAL PROPERTY ${LIB_NAME}_COMMON_DEPS)
get_property(DIALECT_DEPS GLOBAL PROPERTY ${LIB_NAME}_DIALECT_DEPS)

add_executable(${EXE_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${SYNTAX_DEPS}
    ${LEX_DEPS}
    ${COMMON_DEPS}
    ${DIALECT_DEPS}
)
target_link_libraries(${EXE_NAME}
    ${llvm_libs}
    MLIRAnalysis
    MLIRIR
    MLIRDialect
    MLIRParser
    MLIRSideEffectInterfaces
    MLIRDialectUtils
)
