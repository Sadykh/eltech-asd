cmake_minimum_required(VERSION 3.6)
project(lab_3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Node.cpp Tree.cpp Queue.h)
add_executable(lab_3 ${SOURCE_FILES})
