cmake_minimum_required(VERSION 3.16.0)

project(${PROJECT_NAME} LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

set(PROJECT_NAME "TL")
set(EXE_NAME "tl")
set(LIB_NAME TL)

add_compile_options(-Wall -Wno-implicit-fallthrough -Wno-unneeded-internal-declaration -Wno-unused-function -fno-rtti)

include(${PROJECT_SOURCE_DIR}/cmake/clipp.cmake)

option(LLVM_DIR "llvm cmake dir" CACHE)
find_package(LLVM REQUIRED CONFIG)

message("llvm_include:${LLVM_INCLUDE_DIRS}")

# that we wish to use
option(MLIR_DIR "llvm cmake dir" CACHE)
find_package(MLIR REQUIRED CONFIG)

list(APPEND CMAKE_MODULE_PATH "${MLIR_CMAKE_DIR}")
list(APPEND CMAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")

include(TableGen)
include(AddLLVM)
include(AddMLIR)
include(HandleLLVMOptions)

llvm_map_components_to_libnames(llvm_libs support core irreader)

include_directories(${LLVM_INCLUDE_DIRS})
include_directories(${MLIR_INCLUDE_DIRS})

separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)

link_directories(${LLVM_BUILD_LIBRARY_DIR})
