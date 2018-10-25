cmake_minimum_required(VERSION 3.12)
project(typelist)

set(CMAKE_CXX_STANDARD 17)

add_executable(typelist main.cpp lib/typelist.cpp lib/typelist.h lib/typelist_printer.cpp lib/typelist_printer.h)