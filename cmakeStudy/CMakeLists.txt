# 设置 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.16)

# 项目名称和使用的语言
project(cmakeStudyDemo LANGUAGES CXX)

# 设置 C++ 标准为 C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 指定可执行文件目标，源文件为 main.cpp
add_executable(cmakeStudyDemo main.cpp)
