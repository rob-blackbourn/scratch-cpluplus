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
        NotificationRequest() noexcept
            : Message(MessageType::NotificationRequest)
        {
        }

        NotificationRequest(
            const std::string &feed,
            bool isAdd) noexcept
            :   Message(MessageType::NotificationRequest),
                _feed(feed),
                _isAdd(isAdd)
        {
        }

        const std::string &feed() const noexcept { return _feed; }
        bool isAdd() const noexcept { return _isAdd; }

        static std::shared_ptr<NotificationRequest> from_bytes(std::vector<char>::const_iterator &iter);

    protected:
        virtual size_t bodySize() const noexcept;
        virtual void writeBody(std::vector<char>::iterator &sink) const;

    private:
        std::string _feed;
        bool _isAdd;
    };
}

std::ostream &operator<<(std::ostream &os, const jetblack::messagebus::messages::NotificationRequest &value);

#endif // __messages_NotificationRequest_hpp
