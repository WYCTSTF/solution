cmake_minimum_required(VERSION 3.20)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_C_COMPILER "/opt/homebrew/opt/llvm/bin/clang")
set(CMAKE_CXX_COMPILER "/opt/homebrew/opt/llvm/bin/clang++")

project(sol)

include_directories(header)

add_compile_options(-DLOCAL -DDBG_MACRO_NO_WARNING)

add_compile_options(-fsanitize=address -g)
add_link_options(-fsanitize=address)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(sol ./src/sol.cpp)
