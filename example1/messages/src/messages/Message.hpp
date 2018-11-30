#ifndef __messages_Message_hpp
#define __messages_Message_hpp 1

#include <vector>

#include "messages/MessageType.hpp"

namespace jetblack::messagebus::messages
{
    class Message
    {
    public:
        Message()
        {
        }

        Message(MessageType type)
            : _type(type)
        {
        }

        MessageType type() const { return _type; }

        virtual size_t size() const = 0;

        // static Message read(std::vector<unsigned char>::const_iterator& source);
        // static MessageType readHeader(std::vector<unsigned char>::const_iterator& source);

    private:
        MessageType _type;
    };

    std::vector<unsigned char>::iterator& operator << (
        std::vector<unsigned char>::iterator& iter,
        const Message& message);

    std::vector<unsigned char>::const_iterator& operator >> (
        std::vector<unsigned char>::const_iterator& iter,
        Message& message);
}

#endif // __messages_Message_hpp
