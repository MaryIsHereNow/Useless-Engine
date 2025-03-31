cmake_minimum_required(VERSION 3.10)
project(Playground)

set(CMAKE_CXX_STANDARD 20)

# 设置可执行文件的输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/runtime)

# 生成可执行文件
add_executable(Playground src/Playground.cpp)

# 指定 Useless-Engine 库的路径
find_library(USELESS_ENGINE_LIB Useless-Engine PATHS ${CMAKE_SOURCE_DIR}/../Useless-Engine/bin/lib)
if(NOT USELESS_ENGINE_LIB)
    message(FATAL_ERROR "Useless-Engine library not found!")
endif()

# 链接 Useless-Engine 库
target_link_libraries(Playground PRIVATE ${USELESS_ENGINE_LIB})

# 包含 Useless-Engine 的头文件目录
target_include_directories(Playground PRIVATE
        ${CMAKE_SOURCE_DIR}/../Useless-Engine/include
        ${CMAKE_SOURCE_DIR}/../Useless-Engine/src
        ${CMAKE_SOURCE_DIR}/../Useless-Engine/vendor/spdlog/include
        ${CMAKE_SOURCE_DIR}/../Useless-Engine/vendor/glfw/include
        ${CMAKE_SOURCE_DIR}/../Useless-Engine/vendor/glad/include
)

# 添加 MacOS 宏定义
target_compile_definitions(Playground PRIVATE UE_PLATFORM_MACOS)