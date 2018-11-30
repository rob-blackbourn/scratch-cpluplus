#include "messages/Message.hpp"

#include "serialization/native.hpp"

namespace jetblack::messagebus::messages
{
    // Message Message::read(std::vector<unsigned char>::const_iterator& source)
    // {
    //     MessageType type = readHeader(source);
    //     return Message(type);
    // }

    // MessageType readHeader(std::vector<unsigned char>::const_iterator& source)
    // {
    //     unsigned char byte;
    //     byte >> source;
    //     return static_cast<MessageType>(byte);
    // }

    std::vector<unsigned char>::iterator& operator << (
        std::vector<unsigned char>::iterator& iter, 
        const Message& message)
    {
        return iter;
    }

    std::vector<unsigned char>::const_iterator& operator >> (
        std::vector<unsigned char>::const_iterator& iter,
        Message& message)
        {
            return iter;
        }

}