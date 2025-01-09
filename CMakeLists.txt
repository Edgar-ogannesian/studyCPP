cmake_minimum_required(VERSION 3.28)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)


add_executable(
        twoSum twoSum.cpp
)

add_executable(
        merge_sort merge_sort.cpp
)

add_executable(
        binSearch binSearch.cpp
)

add_executable(
        one one.cpp
)