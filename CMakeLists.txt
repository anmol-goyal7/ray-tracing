cmake_minimum_required(VERSION 3.10)
project(RayTracer VERSION 1.0 LANGUAGES CXX)

# Enforce C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Export compile_commands.json for clangd/Neovim
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# List of targets
set(TARGETS raytracer firstimage)

# Sources
set(RAYTRACER_SOURCES src/main.cpp)
set(FIRSTIMAGE_SOURCES examples/firstimage.cpp)

# Define executables
add_executable(raytracer ${RAYTRACER_SOURCES})
add_executable(firstimage ${FIRSTIMAGE_SOURCES})

# Include directories and flags for all targets
foreach(target ${TARGETS})
    target_include_directories(${target} PRIVATE include)
    if(MSVC)
        target_compile_options(${target} PRIVATE /W4)
    else()
        target_compile_options(${target} PRIVATE -Wall -Wextra -Wpedantic)
    endif()
endforeach()
