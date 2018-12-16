#ifndef __messages_SubscriptionRequest_hpp
#define __messages_SubscriptionRequest_hpp 1

#include "messages/Message.hpp"

#include <string>
#include <vector>
#include <memory>
#include <iostream>

namespace jetblack::messagebus::messages
{
    class SubscriptionRequest : public Message
    {
    public:
        SubscriptionRequest() noexcept
            : Message(MessageType::SubscriptionRequest)
        {
        }

        SubscriptionRequest(
            const std::string &feed,
            const std::string &topic,
            bool isAdd) noexcept
            :   Message(MessageType::SubscriptionRequest),
                _feed(feed),
                _topic(topic),
                _isAdd(isAdd)
        {
        }

        const std::string &feed() const noexcept { return _feed; }
        const std::string &topic() const noexcept { return _topic; }
        bool isAdd() const noexcept { return _isAdd; }

        static std::shared_ptr<SubscriptionRequest> from_bytes(std::vector<char>::const_iterator &iter);

    protected:
        virtual size_t bodySize() const noexcept;
        virtual void writeBody(std::vector<char>::iterator &sink) const;

    private:
        std::string _feed;
        std::string _topic;
        bool _isAdd;
    };
}

std::ostream &operator<<(std::ostream &os, const jetblack::messagebus::messages::SubscriptionRequest &value);

#endif // __messages_SubscriptionRequest_hpp
