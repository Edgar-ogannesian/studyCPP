cmake_minimum_required(VERSION 3.28)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        test test.cpp
)

add_executable(
        Array    Array.cpp
)
add_executable(
        heap heap.cpp
)

add_executable(
        sharedPointer sharedPointer.cpp
)