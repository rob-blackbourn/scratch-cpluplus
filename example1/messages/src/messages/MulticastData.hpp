#ifndef __messages_MulticastData_hpp
#define __messages_MulticastData_hpp 1

#include <string>
#include <vector>

#include "messages/Message.hpp"
#include "messages/BinaryDataPacket.hpp"

namespace jetblack::messagebus::messages
{
    class MulticastData : public Message
    {
    public:
        MulticastData()
            : Message(MessageType::MulticastData)
        {
        }

        MulticastData(const std::string& feed, const std::string& topic, bool isImage, std::vector<BinaryDataPacket>&& data)
            : Message(MessageType::MulticastData), _feed(feed), _topic(topic), _isImage(isImage), _data(std::move(data))
        {
        }

        const std::string& feed() const { return _feed; }
        const std::string& topic() const { return _topic; }
        const bool isImage() const { return _isImage; }
        const std::vector<BinaryDataPacket>& data() const { return _data; }

        virtual size_t size() const;

    private:
        std::string _feed;
        std::string _topic;
        bool _isImage;
        std::vector<BinaryDataPacket> _data;
    };
}

std::vector<unsigned char>::iterator& operator << (
    std::vector<unsigned char>::iterator& iter,
    const jetblack::messagebus::messages::MulticastData& value);

std::vector<unsigned char>::const_iterator& operator >> (
    std::vector<unsigned char>::const_iterator& iter,
    jetblack::messagebus::messages::MulticastData& value);

#endif // __messages_MulticastData_hpp
