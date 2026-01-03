cmake_minimum_required(VERSION 3.20)

project(ray_tracing LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(first_image
    basics/first_image.cpp
)

