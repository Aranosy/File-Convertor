cmake_minimum_required(VERSION 3.13)  # CMake version check
project(File-Converter)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

include_directories(${PROJECT_SOURCE_DIR}/include/utils)
include_directories(${PROJECT_SOURCE_DIR}/include/generators)

add_executable(File-Converter main.cpp)