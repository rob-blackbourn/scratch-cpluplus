#ifndef __messages_UnitcastData_hpp
#define __messages_UnitcastData_hpp 1

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include <boost/uuid/uuid.hpp>

#include "messages/Message.hpp"
#include "messages/BinaryDataPacket.hpp"

namespace jetblack::messagebus::messages
{
    class UnicastData : public Message
    {
    public:
        UnicastData() noexcept
            :   Message(MessageType::UnicastData)
        {
        }

        UnicastData(
            const boost::uuids::uuid& clientId,
            const std::string& feed,
            const std::string& topic,
            bool isImage,
            std::vector<BinaryDataPacket>&& data) noexcept
            :   Message(MessageType::UnicastData), 
                _clientId(clientId),
                _feed(feed),
                _topic(topic),
                _isImage(isImage),
                _data(data)
        {
        }

        const boost::uuids::uuid& clientId() const noexcept { return _clientId; }
        const std::string& feed() const noexcept { return _feed; }
        const std::string& topic() const noexcept { return _topic; }
        const bool isImage() const noexcept { return _isImage; }
        const std::vector<BinaryDataPacket>& data() const noexcept { return _data; }

        static std::shared_ptr<UnicastData> from_bytes(std::vector<char>::const_iterator& iter);

    protected:
        virtual size_t bodySize() const noexcept;
        virtual void writeBody(std::vector<char>::iterator& sink) const;

    private:
        boost::uuids::uuid _clientId;
        std::string _feed;
        std::string _topic;
        bool _isImage;
        std::vector<BinaryDataPacket> _data;
    };
}

std::ostream& operator << (std::ostream& os, const jetblack::messagebus::messages::UnicastData& value);

#endif // __messages_UnicastData_hpp
