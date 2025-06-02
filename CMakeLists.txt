cmake_minimum_required(VERSION 3.20)

if(WIN32)
  set(CMAKE_C_COMPILER "D:/Program Files/llvm-mingw-20250528-ucrt-x86_64/bin/clang.exe")
  set(CMAKE_CXX_COMPILER "D:/Program Files/llvm-mingw-20250528-ucrt-x86_64/bin/clang++.exe")
endif()

project(sol)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories("${PROJECT_SOURCE_DIR}/header")

add_compile_options(-DLOCAL -DDBG_MACRO_NO_WARNING)

add_compile_options(-fsanitize=address -g)
add_link_options(-fsanitize=address)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(sol ./src/sol.cpp)