include_directories("/opt/boost/1.68.0/include")
link_directories("/opt/boost/1.68.0/lib")
link_libraries(boost_system)

add_executable(example1 example1.cpp)

target_link_libraries(example1 PRIVATE serialization)
