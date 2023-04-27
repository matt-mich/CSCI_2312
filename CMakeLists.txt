cmake_minimum_required(VERSION 3.24)
project(DynamicArrays)

set(CMAKE_CXX_STANDARD 17)

add_executable(DynamicArrays main.cpp dynamic_array.cpp dynamic_array.h dynamic.cpp dynamic.h dynamic_list.cpp dynamic_list.h)
