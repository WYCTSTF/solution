cmake_minimum_required(VERSION 3.5)

project(sol)

set(CMAKE_C_COMPILER /Users/syh/llvm18.1.8/bin/clang)
set(CMAKE_CXX_COMPILER /Users/syh/llvm18.1.8/bin/clang++)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(/Users/syh/solution/header)

add_compile_options(-DLOCAL -DDBG_MACRO_NO_WARNING)

add_compile_options(-fsanitize=address -g)
add_link_options(-fsanitize=address)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(sol ./src/sol.cpp)
