#include "messages/AuthorizationResponse.hpp"

#include "serialization/boost/uuid/uuid.hpp"
#include "serialization/native.hpp"
#include "serialization/vector.hpp"
#include "serialization/string.hpp"

#include <boost/uuid/uuid_io.hpp>

using jetblack::messagebus::messages::AuthorizationResponse;

size_t AuthorizationResponse::bodySize() const noexcept
{
    return serialize_size(_clientId) +
           serialize_size(_feed) +
           serialize_size(_topic) +
           serialize_size(_isAuthorizationRequired) +
           serialize_size(_entitlements);
}

std::shared_ptr<AuthorizationResponse> AuthorizationResponse::from_bytes(std::vector<char>::const_iterator &iter)
{
    boost::uuids::uuid clientId;
    iter >> clientId;

    std::string feed;
    iter >> feed;

    std::string topic;
    iter >> topic;

    bool isAuthorizationRequired;
    iter >> isAuthorizationRequired;

    std::vector<boost::uuids::uuid> entitlements;
    iter >> entitlements;

    return std::make_shared<AuthorizationResponse>(clientId, feed, topic, isAuthorizationRequired, entitlements);
}

void AuthorizationResponse::writeBody(std::vector<char>::iterator &iter) const
{
    iter << _clientId;
    iter << _feed;
    iter << _topic;
    iter << _isAuthorizationRequired;
    iter << _entitlements;
}

std::ostream &operator<<(std::ostream &os, const AuthorizationResponse &value)
{
    return os
           << "clientId=" << value.clientId()
           << ",feed=\"" << value.feed() << "\""
           << ",topic\"" << value.topic() << "\""
           << ",isAuthorizationRequired=" << value.isAuthorizationRequired()
           << ",entitlements.size()=" << value.entitlements().size();
}
