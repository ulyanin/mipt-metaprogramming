# cmake_minimum_required(VERSION <specify CMake version here>)
project(linear_hierarchy)
cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)

include_directories(typelist)
add_subdirectory(typelist)

add_executable(linear_hierarchy main.cpp lib/generate_linear_hierarchy.cpp lib/generate_linear_hierarchy.h ut.h fibonacci_hierarchy.h ut.cpp lib/fibonaccy.h lib/generate_scatter_hierarchy.cpp lib/generate_scatter_hierarchy.h lib/generate_fibonaccy_hierarchy.cpp lib/generate_fibonaccy_hierarchy.h)