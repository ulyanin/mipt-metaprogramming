cmake_minimum_required(VERSION 3.12)
project(homework1)

set(CMAKE_CXX_STANDARD 17)

add_executable(homework1 main.cpp lib/generic_helper.cpp lib/generic_helper.h lib/users_classes.cpp lib/users_classes.h lib/common.h)