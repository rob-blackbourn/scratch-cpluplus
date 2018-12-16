#ifndef __messages_AuthorizationRequest_hpp
#define __messages_AuthorizationRequest_hpp 1

#include "messages/Message.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include <boost/uuid/uuid.hpp>
#include <boost/asio/ip/address.hpp>

namespace jetblack::messagebus::messages
{
    class AuthorizationRequest : public Message
    {
    public:

        AuthorizationRequest()
            : Message(MessageType::AuthorizationRequest)
        {
        }

        AuthorizationRequest(
            const boost::uuids::uuid& clientId,
            const boost::asio::ip::address& address,
            const std::string& user,
            const std::string& feed,
            const std::string& topic
        ) : Message(MessageType::AuthorizationRequest),
            _clientId(clientId),
            _address(address),
            _user(user),
            _feed(feed),
            _topic(topic)
        {
        }

        const boost::uuids::uuid& clientId() const { return _clientId; }
        const boost::asio::ip::address& address() const { return _address; }
        const std::string& user() const { return _user; }
        const std::string& feed() const { return _feed; }
        const std::string& topic() const { return _topic; }

        static std::shared_ptr<AuthorizationRequest> from_bytes(std::vector<char>::const_iterator& iter);

    protected:
        virtual size_t bodySize() const;
        virtual void writeBody(std::vector<char>::iterator& sink) const;

    private:
        boost::uuids::uuid _clientId;
        boost::asio::ip::address _address;
        std::string _user;
        std::string _feed;
        std::string _topic;
    };
}

std::ostream& operator << (std::ostream& os, const jetblack::messagebus::messages::AuthorizationRequest& value);

#endif // __messages_AuthorizationRequest_hpp
