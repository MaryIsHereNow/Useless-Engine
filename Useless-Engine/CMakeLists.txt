cmake_minimum_required(VERSION 3.10)
project(Useless-Engine)

set(CMAKE_CXX_STANDARD 20)

# 设置库文件的输出目录
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/lib)

# 收集源文件
file(GLOB_RECURSE SOURCES src/*.cpp)
# 生成动态链接库
add_library(Useless-Engine SHARED ${SOURCES})

# 添加头文件目录
target_include_directories(Useless-Engine PUBLIC
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/vendor/glfw/include
        ${CMAKE_SOURCE_DIR}/vendor/spdlog/include
        ${CMAKE_SOURCE_DIR}/vendor/glad/include
)

# 添加宏定义
target_compile_definitions(Useless-Engine PRIVATE UE_PLATFORM_MACOS UE_BUILD_DLL)

# 设置预编译头文件
set(CMAKE_CXX_PRECOMPILE_HEADERS ON)
target_precompile_headers(Useless-Engine PRIVATE ${CMAKE_SOURCE_DIR}/src/Useless/uepch.h)

# 查找 glfw 库
find_library(GLFW_LIBRARY NAMES glfw.3 libglfw.3.dylib libglfw.3.a PATHS vendor/glfw/lib-arm64)
if(NOT GLFW_LIBRARY)
    message(FATAL_ERROR "GLFW library not found")
endif()

# 查找 glad 库
find_library(GLAD_LIBRARY NAMES libglad.dylib PATHS vendor/glad/build)
if(NOT GLAD_LIBRARY)
    message(FATAL_ERROR "GLFW library not found")
endif()

# 查找 OpenGL 库
find_library(OPENGL_LIBRARY OpenGL)
if(NOT OPENGL_LIBRARY)
    message(FATAL_ERROR "OpenGL library not found")
endif()

# 链接库
target_link_libraries(Useless-Engine PRIVATE ${GLFW_LIBRARY} ${OPENGL_LIBRARY} ${GLAD_LIBRARY})