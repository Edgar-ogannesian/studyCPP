cmake_minimum_required(VERSION 3.28)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

add_executable(
        9.8 9.8.cpp
)

add_executable(
        twoSum twoSum.cpp
)

add_executable(
        heap heap.cpp
)

add_executable(
        merge_sort merge_sort.cpp
)

add_executable(
        11.1 11.1.cpp
)

add_executable(
        test test.cpp
)

add_executable(
        binSearch binSearch.cpp
)

add_executable(
        11.2.1 11.2.1.cpp
)

add_executable(
        11.2.3 11.2.3.cpp
)

add_executable(
        11.3 11.3.cpp
)

add_executable(
        11.3.1 11.3.1.cpp
)
add_executable(
        11.3.2 11.3.2.cpp
)

add_executable(
        11.3.4 11.3.4.cpp
)

add_executable(
        11.3.5 11.3.5.cpp
)

add_executable(
        one one.cpp
)