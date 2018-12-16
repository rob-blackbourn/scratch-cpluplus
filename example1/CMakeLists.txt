cmake_minimum_required(VERSION 3.13)
project(example1 VERSION 1.0.0)

include(CTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(serialization)
add_subdirectory(messages)
add_subdirectory(examples)

