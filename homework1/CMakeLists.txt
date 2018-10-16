cmake_minimum_required(VERSION 3.12)
project(homework1)

set(CMAKE_CXX_STANDARD 17)

add_executable(homework1
        main.cpp
        lib/common.h
        lib/observer.cpp
        lib/observer.h
        lib/a_user.cpp
        lib/a_user.h
        lib/b_user.cpp
        lib/b_user.h
        lib/mediator.cpp
        lib/mediator.h
        lib/proxy.cpp
        lib/proxy.h)