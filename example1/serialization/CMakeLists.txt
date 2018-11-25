include_directories("/opt/boost/1.68.0/include")

add_library(
    serialization
    "src/serialization/native.hpp"
    "src/serialization/native.cpp"
    "src/serialization/string.hpp"
    "src/serialization/string.cpp"
    "src/serialization/boost/ip/address.hpp"
    "src/serialization/boost/ip/address.cpp"
)

target_include_directories(serialization PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")