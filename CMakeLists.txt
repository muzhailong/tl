cmake_minimum_required(VERSION 3.16.0)

project(${PROJECT_NAME} LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

set(PROJECT_NAME "TL")
set(EXE_NAME "tl")
set(LIB_NAME TL)

option(LLVM_DIR "llvm cmake dir"  CACHE)

find_package(LLVM REQUIRED CONFIG)

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

# that we wish to use
llvm_map_components_to_libnames(llvm_libs support core irreader)


include_directories(${LLVM_DIR}/include)
link_directories(${LLVM_DIR}/lib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)