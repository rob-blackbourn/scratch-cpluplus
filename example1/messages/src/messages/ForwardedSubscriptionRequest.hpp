#ifndef __messages_ForwardedSubscriptionRequest_hpp
#define __messages_ForwardedSubscriptionRequest_hpp 1

#include "messages/Message.hpp"

#include <string>
#include <vector>
#include <memory>
#include <iostream>

#include <boost/asio/ip/address.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace jetblack::messagebus::messages
{
    class ForwardedSubscriptionRequest : public Message
    {
    public:
        ForwardedSubscriptionRequest()
            : Message(MessageType::ForwardedSubscriptionRequest)
        {
        }

        ForwardedSubscriptionRequest(const std::string &user, const boost::asio::ip::address &address, const boost::uuids::uuid &clientId, const std::string &feed, const std::string &topic, bool isAdd)
            : Message(MessageType::ForwardedSubscriptionRequest),
            _user(user), _address(address), _clientId(clientId), _feed(feed), _topic(topic), _isAdd(isAdd)
        {
        }

        const std::string &user() const { return _user; }
        const boost::asio::ip::address &address() const { return _address; }
        const boost::uuids::uuid &clientId() const { return _clientId; }
        const std::string &feed() const { return _feed; }
        const std::string &topic() const { return _topic; }
        bool isAdd() const { return _isAdd; }

        static std::shared_ptr<ForwardedSubscriptionRequest> from_bytes(std::vector<char>::const_iterator &iter);

    protected:
        virtual size_t bodySize() const;
        virtual void writeBody(std::vector<char>::iterator &sink) const;

    private:
        std::string _user;
        boost::asio::ip::address _address;
        boost::uuids::uuid _clientId;
        std::string _feed;
        std::string _topic;
        bool _isAdd;
    };
}

std::ostream &operator<<(std::ostream &os, const jetblack::messagebus::messages::ForwardedSubscriptionRequest &value);

#endif // __messages_ForwardedSubscriptionRequest_hpp
