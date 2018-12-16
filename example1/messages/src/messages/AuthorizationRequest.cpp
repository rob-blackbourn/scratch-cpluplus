#include "messages/AuthorizationRequest.hpp"

#include "serialization/native.hpp"
#include "serialization/vector.hpp"
#include "serialization/string.hpp"
#include "serialization/boost/uuid/uuid.hpp"
#include "serialization/boost/asio/ip/address.hpp"

#include <boost/uuid/uuid_io.hpp>

using jetblack::messagebus::messages::AuthorizationRequest;

size_t AuthorizationRequest::bodySize() const noexcept
{
    return serialize_size(_clientId) +
           serialize_size(_address) +
           serialize_size(_user) +
           serialize_size(_feed) +
           serialize_size(_topic);
}

std::shared_ptr<AuthorizationRequest> AuthorizationRequest::from_bytes(std::vector<char>::const_iterator &iter)
{
    boost::uuids::uuid clientId;
    iter >> clientId;

    boost::asio::ip::address address;
    iter >> address;

    std::string user;
    iter >> user;

    std::string feed;
    iter >> feed;

    std::string topic;
    iter >> topic;

    return std::make_shared<AuthorizationRequest>(clientId, address, user, feed, topic);
}

void AuthorizationRequest::writeBody(std::vector<char>::iterator &iter) const
{
    iter << _clientId;
    iter << _address;
    iter << _user;
    iter << _feed;
    iter << _topic;
}

std::ostream &operator<<(std::ostream &os, const AuthorizationRequest &value)
{
    return os
           << "clientId=" << value.clientId()
           << ",adddress=" << value.address()
           << ",user=\"" << value.user() << "\""
           << ",feed=\"" << value.feed() << "\""
           << ",topic\"" << value.topic() << "\"";
}
