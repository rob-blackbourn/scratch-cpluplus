include_directories("/opt/boost/1.68.0/include")

add_library(
    serialization
    "src/serialization/native.hpp"
    "src/serialization/native.cpp"
    "src/serialization/string.hpp"
    "src/serialization/string.cpp"
    "src/serialization/array.hpp"
    "src/serialization/array.cpp"
    "src/serialization/vector.hpp"
    "src/serialization/vector.cpp"
    "src/serialization/boost/ip/address.hpp"
    "src/serialization/boost/ip/address.cpp"
    "src/serialization/boost/uuid/uuid.hpp"
    "src/serialization/boost/uuid/uuid.cpp"
)

target_include_directories(serialization PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")