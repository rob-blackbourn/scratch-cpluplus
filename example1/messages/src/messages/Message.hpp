#ifndef __messages_Message_hpp
#define __messages_Message_hpp 1

#include <vector>
#include <memory>

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

        static std::shared_ptr<Message> from_bytes(std::vector<unsigned char>::const_iterator& source);
        std::shared_ptr<std::vector<unsigned char>> to_bytes() const;

    protected:
        size_t headerSize() const { return sizeof(unsigned char); }
        static MessageType readHeader(std::vector<unsigned char>::const_iterator& source);
        std::vector<unsigned char>::iterator& writeHeader(std::vector<unsigned char>::iterator& sink) const;
        virtual size_t bodySize() const = 0;
        virtual void writeBody(std::vector<unsigned char>::iterator& sink) const = 0;

    private:
        MessageType _type;
    };
}

#endif // __messages_Message_hpp
