include_directories("/opt/boost/1.68.0/include")

add_library(
    messages
    "src/messages/MessageType.hpp"
    "src/messages/BinaryDataPacket.hpp"
    "src/messages/BinaryDataPacket.cpp"
    "src/messages/Message.hpp"
    "src/messages/Message.cpp"
    "src/messages/AuthorizationRequest.hpp"
    "src/messages/AuthorizationRequest.cpp"
    "src/messages/AuthorizationResponse.hpp"
    "src/messages/AuthorizationResponse.cpp"
    "src/messages/ForwardedMulticastData.hpp"
    "src/messages/ForwardedMulticastData.cpp"
    "src/messages/ForwardedSubscriptionRequest.cpp"
    "src/messages/ForwardedSubscriptionRequest.hpp"
    "src/messages/InteractorAdvertisement.cpp"
    "src/messages/InteractorAdvertisement.hpp"
    "src/messages/MulticastData.hpp"
    "src/messages/MulticastData.cpp"
)

target_include_directories(messages PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

target_link_libraries(messages PRIVATE serialization)