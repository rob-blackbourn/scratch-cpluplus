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
        Message() noexcept
        {
        }

        Message(MessageType type) noexcept
            : _type(type)
        {
        }

        MessageType type() const noexcept { return _type; }

        static std::shared_ptr<Message> from_bytes(std::vector<char>::const_iterator &source);
        std::shared_ptr<std::vector<char>> to_bytes() const;

    protected:
        size_t headerSize() const noexcept { return sizeof(unsigned char); }
        static MessageType readHeader(std::vector<char>::const_iterator &source);
        std::vector<char>::iterator &writeHeader(std::vector<char>::iterator &sink) const;
        virtual size_t bodySize() const noexcept = 0;
        virtual void writeBody(std::vector<char>::iterator &sink) const = 0;

    private:
        MessageType _type;
    };
}

#endif // __messages_Message_hpp
