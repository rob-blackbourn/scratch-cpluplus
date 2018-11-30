#ifndef __messages_AuthorizationRequest_hpp
#define __messages_AuthorizationRequest_hpp 1

#include "messages/Message.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <iostream>
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

    private:
        boost::uuids::uuid _clientId;
        boost::asio::ip::address _address;
        std::string _user;
        std::string _feed;
        std::string _topic;
    };
}

std::vector<unsigned char>::iterator& operator << (
    std::vector<unsigned char>::iterator& iter,
    const jetblack::messagebus::messages::AuthorizationRequest& value);

std::vector<unsigned char>::const_iterator& operator >> (
    std::vector<unsigned char>::const_iterator& iter,
    jetblack::messagebus::messages::AuthorizationRequest& value);

size_t serialize_size(const jetblack::messagebus::messages::AuthorizationRequest& value);

std::ostream& operator << (std::ostream& os, const jetblack::messagebus::messages::AuthorizationRequest& value);

#endif // __messages_AuthorizationRequest_hpp
