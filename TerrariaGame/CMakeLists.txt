# 设置 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.16)

# 项目名称和使用的语言
project(TerrariaGame LANGUAGES CXX)

# 设置 C++ 标准为 C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Build Raylib as static library" FORCE)
# 递归收集 src 及其子目录下所有 cpp 源文件
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")



add_subdirectory(thirdparty/raylib-6.0)
add_subdirectory(thirdparty/imgui)
add_subdirectory(thirdparty/rlImGui)
# 指定可执行文件目标，源文件为 main.cpp 及 src 下的全部 cpp
add_executable(${PROJECT_NAME} main.cpp ${PROJECT_SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE raylib_static imgui_static rlImGui)
