cmake_minimum_required(VERSION 3.10)
project(RayTracer VERSION 1.0 LANGUAGES CXX)

# Enforce C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Export compile_commands.json for clangd/Neovim
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Define the executable and its source files
add_executable(raytracer 
    src/main.cpp
)

# Include directories
target_include_directories(raytracer PRIVATE include)

# Compiler-specific warnings for better development
if(MSVC)
    target_compile_options(raytracer PRIVATE /W4)
else()
    target_compile_options(raytracer PRIVATE -Wall -Wextra -Wpedantic)
endif()

