include_directories("/opt/boost/1.68.0/include")
link_directories("/opt/boost/1.68.0/lib")
link_libraries(boost_system)

add_executable(NativeTest native_test.cpp test_value.hpp)
target_link_libraries(NativeTest PRIVATE serialization)

add_test(Native NativeTest)

add_executable(StringTest string_test.cpp test_value.hpp)
target_link_libraries(StringTest PRIVATE serialization)

add_test(StringTest NativeTest)

add_executable(BoostUuid boost/uuid/uuid_test.cpp test_value.hpp)
target_link_libraries(BoostUuid PRIVATE serialization)

add_test(BoostUuid BoostUuid)

add_executable(BoostAsioIp boost/asio/ip/ip_test.cpp test_value.hpp)
target_link_libraries(BoostAsioIp PRIVATE serialization)

add_test(BoostAsioIp BoostAsioIp)
