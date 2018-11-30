#include "messages/Message.hpp"
#include "messages/AuthorizationRequest.hpp"
#include "messages/MulticastData.hpp"

#include "serialization/native.hpp"

using jetblack::messagebus::messages::MessageType;
using jetblack::messagebus::messages::Message;
using jetblack::messagebus::messages::MulticastData;
using jetblack::messagebus::messages::AuthorizationRequest;

std::vector<unsigned char>::const_iterator& operator >> (
    std::vector<unsigned char>::const_iterator& iter,
    jetblack::messagebus::messages::Message& value)
{
    unsigned char byte;
    iter >> byte;
    auto type = static_cast<MessageType>(byte);

    switch (type)
    {
        case MessageType::AuthorizationRequest:
        {
            AuthorizationRequest msg;
            iter >> msg;
            break;
        }

        case MessageType::MulticastData:
        {
            MulticastData msg;
            iter >> msg;
            break;
        }

        default:
            break;;

    }

    return iter;
}
