cmake_minimum_required(VERSION 3.13)
project(example1 VERSION 1.0.0)

include(CTest)

add_subdirectory(serialization)
add_subdirectory(messages)
add_subdirectory(examples)

