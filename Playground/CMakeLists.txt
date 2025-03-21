cmake_minimum_required(VERSION 3.10)
project(Playground)

set(CMAKE_CXX_STANDARD 11)

# 设置可执行文件的输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/runtime)

# 生成可执行文件
add_executable(Playground src/Playground.cpp)

# 指定 Useless-Engine 库的路径
find_library(USELESS_ENGINE_LIB Useless-Engine PATHS ${CMAKE_SOURCE_DIR}/../Useless-Engine/)

# 检查是否找到 Useless-Engine 库
if(USELESS_ENGINE_LIB)
    # 包含 Useless-Engine 的头文件目录，将目标名称改为 Playground
    target_include_directories(Playground PUBLIC ${CMAKE_SOURCE_DIR}/../Useless-Engine)
    # 链接 Useless-Engine 库
    target_link_libraries(Playground ${USELESS_ENGINE_LIB})
else()
    message(FATAL_ERROR "Useless-Engine library not found!")
endif()

#添加宏定义
target_compile_definitions(Playground PRIVATE UE_PLATFORM_MACOS)


# 添加全局头文件搜索路径
include_directories(
        ${CMAKE_SOURCE_DIR}/../Useless-Engine/src/
)
