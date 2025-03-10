cmake_minimum_required(VERSION 3.29)
project(C_DOT_TREE_VISUALIZER C)

set(CMAKE_C_STANDARD 23)

include_directories(${CMAKE_SOURCE_DIR}/inc)

add_executable(C_DOT_TREE_VISUALIZER src/examples/unary_tree_example.c
        src/examples/binary_tree_example.c
        src/examples/ternary_tree_example.c
        src/examples/binary_tree_only_data_example.c
        src/tree_display.c
        inc/tree_display.h
        inc/examples/tree_examples.h
        src/main.c)
