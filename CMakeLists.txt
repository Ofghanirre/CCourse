cmake_minimum_required(VERSION 3.29)
project(CCourse C)

set(CMAKE_C_STANDARD 17)

add_executable(CCourse main.c
        clist.c
        clist.h)
