# Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(KaloAlgebra VERSION 1.0 LANGUAGES CXX)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add include directory
include_directories(include)

# Add the source files and create a library
add_library(KaloAlgebra
    src/matrix.cpp
    src/vector.cpp
    src/utils.cpp
)

# Option to toggle between building main or tests
option(BUILD_MAIN "Build the main program" ON)
option(BUILD_TESTS "Build the unit tests" OFF)

# Add the main executable if BUILD_MAIN is ON
if(BUILD_MAIN)
    add_executable(main main.cpp)
    target_link_libraries(main KaloAlgebra)
endif()

# Add the tests directory if BUILD_TESTS is ON
if(BUILD_TESTS)
    add_subdirectory(tests)
endif()
