#ifndef __messages_AuthorizationResponse_hpp
#define __messages_AuthorizationResponse_hpp 1

#include "messages/Message.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include <boost/uuid/uuid.hpp>

namespace jetblack::messagebus::messages
{
    class AuthorizationResponse : public Message
    {
    public:
        AuthorizationResponse() noexcept
            : Message(MessageType::AuthorizationResponse)
        {
        }

        AuthorizationResponse(
            const boost::uuids::uuid &clientId,
            const std::string &feed,
            const std::string &topic,
            bool isAuthorizationRequired,
            const std::vector<boost::uuids::uuid> &entitlements) noexcept
            :   Message(MessageType::AuthorizationResponse),
                _clientId(clientId),
                _feed(feed),
                _topic(topic),
                _isAuthorizationRequired(isAuthorizationRequired),
                _entitlements(entitlements)
        {
        }

        const boost::uuids::uuid &clientId() const noexcept { return _clientId; }
        const std::string &feed() const noexcept { return _feed; }
        const std::string &topic() const noexcept { return _topic; }
        bool isAuthorizationRequired() const noexcept { return _isAuthorizationRequired; }
        const std::vector<boost::uuids::uuid> &entitlements() const noexcept { return _entitlements; }

        static std::shared_ptr<AuthorizationResponse> from_bytes(std::vector<char>::const_iterator &iter);

        friend bool operator == (const AuthorizationResponse& lhs, const AuthorizationResponse& rhs)
        {
            return lhs._clientId == rhs._clientId &&
                lhs._feed == rhs._feed &&
                lhs._topic == rhs._topic &&
                lhs._isAuthorizationRequired == rhs._isAuthorizationRequired &&
                lhs._entitlements == rhs._entitlements;
        }

        friend bool operator != (const AuthorizationResponse& lhs, const AuthorizationResponse& rhs)
        {
            return !(lhs == rhs);
        }

    protected:
        virtual size_t bodySize() const noexcept;
        virtual void writeBody(std::vector<char>::iterator &sink) const;

    private:
        boost::uuids::uuid _clientId;
        std::string _feed;
        std::string _topic;
        bool _isAuthorizationRequired;
        std::vector<boost::uuids::uuid> _entitlements;
    };
}

std::ostream& operator << (std::ostream& os, const jetblack::messagebus::messages::AuthorizationResponse& value);

#endif // __messages_AuthorizationResponse_hpp
