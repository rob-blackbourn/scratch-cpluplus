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
        AuthorizationResponse()
            : Message(MessageType::AuthorizationResponse)
        {
        }

        AuthorizationResponse(
            const boost::uuids::uuid& clientId,
            const std::string& feed,
            const std::string& topic,
            bool isAuthorizationRequired,
            const std::vector<boost::uuids::uuid>& entitlements
        ) : Message(MessageType::AuthorizationResponse),
          _clientId(clientId),
          _feed(feed),
          _topic(topic),
          _isAuthorizationRequired(isAuthorizationRequired),
          _entitlements(entitlements)
        {
        }

        const boost::uuids::uuid& clientId() const { return _clientId; }
        const std::string& feed() const { return _feed; }
        const std::string& topic() const { return _topic; }
        bool isAuthorizationRequired() const { return _isAuthorizationRequired; }
        const std::vector<boost::uuids::uuid>& entitlements() const { return _entitlements; }

        static std::shared_ptr<AuthorizationResponse> from_bytes(std::vector<unsigned char>::const_iterator& iter);

    protected:
        virtual size_t bodySize() const;
        virtual void writeBody(std::vector<unsigned char>::iterator& sink) const;

    private:
        boost::uuids::uuid _clientId;
        std::string _feed;
        std::string _topic;
        bool _isAuthorizationRequired;
        std::vector<boost::uuids::uuid> _entitlements;
    };
}

#endif // __messages_AuthorizationResponse_hpp
