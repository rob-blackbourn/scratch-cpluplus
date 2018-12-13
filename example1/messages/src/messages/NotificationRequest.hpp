#ifndef __messages_NotificationRequest_hpp
#define __messages_NotificationRequest_hpp 1

#include "messages/Message.hpp"

#include <string>
#include <vector>
#include <memory>
#include <iostream>

namespace jetblack::messagebus::messages
{
    class NotificationRequest : public Message
    {
    public:

        NotificationRequest()
            : Message(MessageType::NotificationRequest)
        {
        }

        NotificationRequest(const std::string& feed, bool isAdd)
            : Message(MessageType::NotificationRequest),
              _feed(feed), _isAdd(isAdd)
        {
        }

        const std::string& feed() const { return _feed; }
        bool isAdd() const { return _isAdd; }

        static std::shared_ptr<NotificationRequest> from_bytes(std::vector<unsigned char>::const_iterator& iter);

    protected:
        virtual size_t bodySize() const;
        virtual void writeBody(std::vector<unsigned char>::iterator& sink) const;

    private:
        std::string _feed;
        bool _isAdd;
    };
}

size_t serialize_size(const jetblack::messagebus::messages::NotificationRequest& value);

std::ostream& operator << (std::ostream& os, const jetblack::messagebus::messages::NotificationRequest& value);

#endif // __messages_NotificationRequest_hpp
