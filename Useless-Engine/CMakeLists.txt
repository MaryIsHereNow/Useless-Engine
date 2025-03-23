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
include_directories(src/
        vendor/glfw/include
        vendor/spdlog/include
)

#添加宏定义
target_compile_definitions(Useless-Engine PRIVATE UE_PLATFORM_MACOS UE_BUILD_DLL)

# 设置预编译头文件
set(CMAKE_CXX_PRECOMPILE_HEADERS ON)
target_precompile_headers(Useless-Engine PRIVATE  ${CMAKE_SOURCE_DIR}/src/Useless/uepch.h)

# 设置库目录
link_directories(vendor/glfw/lib-arm64)
# 查找glfw库
find_library(GLFW_LIBRARY NAMES glfw.3 libglfw.3.dylib libglfw.3.a PATHS vendor/glfw/lib-arm64)
if(NOT GLFW_LIBRARY)
    message(FATAL_ERROR "GLFW library not found")
endif()
# 链接glfw库
target_link_libraries(Useless-Engine ${GLFW_LIBRARY})

# 查找OpenGL库
find_library(OPENGL_LIBRARY OpenGL)
if(NOT OPENGL_LIBRARY)
    message(FATAL_ERROR "OpenGL library not found")
endif()
# 链接OpenGL库
target_link_libraries(Useless-Engine ${GLFW_LIBRARY} ${OPENGL_LIBRARY})