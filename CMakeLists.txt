cmake_minimum_required(VERSION 3.28)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        main main.cpp
)
add_executable(
        inmemmory inmemmory.cpp
)
add_executable(
        myKeyValueStore myKeyValueStore.cpp
)