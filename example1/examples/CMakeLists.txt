include_directories("/opt/boost/1.68.0/include")
link_directories("/opt/boost/1.68.0/lib")
link_libraries(boost_system)

add_executable(BufferTest BufferTest.cpp)
target_link_libraries(BufferTest PRIVATE serialization)

add_executable(example1 example1.cpp)
target_link_libraries(example1 PRIVATE serialization)
target_link_libraries(example1 PRIVATE messages)

add_executable(example2 example2.cpp)
target_link_libraries(example2 PRIVATE serialization)
target_link_libraries(example2 PRIVATE messages)

add_executable(BinaryDataPacketTest BinaryDataPacketTest.cpp)
target_link_libraries(BinaryDataPacketTest PRIVATE serialization)
target_link_libraries(BinaryDataPacketTest PRIVATE messages)
