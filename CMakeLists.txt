cmake_minimum_required(VERSION 3.21)
project(cpp_tasks)

set(CMAKE_CXX_STANDARD 23)

add_executable(cpp_tasks
        relocate.cpp)
add_executable(cpp_tasks main.cpp)
add_executable(recursion recursion.cpp)
add_executable(sorts sorts.cpp)
add_executable(boris_cat boris_cat.cpp)
add_executable(tiling tiling.cpp)
add_executable(compress compress.cpp)
