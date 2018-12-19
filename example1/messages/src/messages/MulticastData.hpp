#ifndef __messages_MulticastData_hpp
#define __messages_MulticastData_hpp 1

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "messages/Message.hpp"
#include "messages/BinaryDataPacket.hpp"

namespace jetblack::messagebus::messages
{
  class MulticastData : public Message
  {
    public:
        MulticastData() noexcept
            :   Message(MessageType::MulticastData)
        {
        }

        MulticastData(
            const std::string &feed,
            const std::string &topic,
            bool isImage,
            std::vector<BinaryDataPacket> &&data) noexcept
            :   Message(MessageType::MulticastData),
                _feed(feed),
                _topic(topic),
                _isImage(isImage),
                _data(std::move(data))
        {
        }

        const std::string &feed() const noexcept { return _feed; }
        const std::string &topic() const noexcept { return _topic; }
        const bool isImage() const noexcept { return _isImage; }
        const std::vector<BinaryDataPacket> &data() const noexcept { return _data; }

        static std::shared_ptr<MulticastData> from_bytes(std::vector<char>::const_iterator &iter);

        friend bool operator == (const MulticastData& lhs, const MulticastData& rhs) noexcept
        {
            return lhs._feed == rhs._feed &&
                lhs._topic == rhs._topic &&
                lhs._isImage == rhs._isImage &&
                lhs._data == rhs._data;
        }

        friend bool operator != (const MulticastData& lhs, const MulticastData& rhs) noexcept
        {
            return !(lhs == rhs);
        }
        
    protected:
        virtual size_t bodySize() const noexcept;
        virtual void writeBody(std::vector<char>::iterator &sink) const;

    private:
        std::string _feed;
        std::string _topic;
        bool _isImage;
        std::vector<BinaryDataPacket> _data;
  };
}

std::ostream &operator<<(std::ostream &os, const jetblack::messagebus::messages::MulticastData &value);

#endif // __messages_MulticastData_hpp
