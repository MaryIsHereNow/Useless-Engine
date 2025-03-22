cmake_minimum_required(VERSION 3.10)
project(Useless-Engine)

set(CMAKE_CXX_STANDARD 11)

# 设置库文件的输出目录
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/lib)

# 收集源文件
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

# 收集所有.cpp文件
file(GLOB_RECURSE SOURCES "src/*.cpp")
# 生成动态链接库
add_library(Useless-Engine SHARED ${SOURCES})

# 添加头文件目录
include_directories(vendor/spdlog/include)

#添加宏定义
target_compile_definitions(Useless-Engine PRIVATE UE_PLATFORM_MACOS UE_BUILD_DLL)