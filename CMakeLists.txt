cmake_minimum_required(VERSION 3.5)

# if you want to use on mac
# set(VCPKG_TARGET_TRIPLET arm64-osx)
# set(VCPKG_TARGET_TRIPLET "x64-linux") vcpkg path
# include(~/vcpkg/scripts/buildsystems/vcpkg.cmake)

project(sol)

set(CMAKE_CXX_COMPILER /home/syh/clang+llvm-18.1.8-aarch64-linux-gnu/bin/clang++)
# set(CMAKE_CXX_COMPILER /usr/bin/clang++) set(CMAKE_CXX_COMPILER
# /usr/local/bin/icc)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(/home/syh/solution/header)
# include_directories(/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include)

add_compile_options(-DLOCAL -DDBG_MACRO_NO_WARNING)
# add_compile_options(-fno-elide-constructors)

add_compile_options(-fsanitize=address -g)
add_link_options(-fsanitize=address)

# set(SHELL /opt/homebrew/bin/bash)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(sol ./src/sol.cpp)

# find_path(DBG_MACRO_INCLUDE_DIRS "dbg.h") target_include_directories(sol
# PRIVATE ${DBG_MACRO_INCLUDE_DIRS})
