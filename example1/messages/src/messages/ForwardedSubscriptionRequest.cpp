#include "messages/ForwardedSubscriptionRequest.hpp"

#include "serialization/native.hpp"
#include "serialization/vector.hpp"
#include "serialization/string.hpp"
#include "serialization/boost/asio/ip/address.hpp"
#include "serialization/boost/uuid/uuid.hpp"

using jetblack::messagebus::messages::ForwardedSubscriptionRequest;

size_t ForwardedSubscriptionRequest::bodySize() const noexcept
{
    size_t len = 0;
    len += serialize_size(_clientId);
    len += serialize_size(_user);
    len += serialize_size(_address);
    len += serialize_size(_feed);
    len += serialize_size(_topic);
    len += serialize_size(_isAdd);
    return len;
}

std::shared_ptr<ForwardedSubscriptionRequest> ForwardedSubscriptionRequest::from_bytes(std::vector<char>::const_iterator &iter)
{
    boost::uuids::uuid clientId;
    iter >> clientId;

    std::string user;
    iter >> user;

    std::string feed;
    iter >> feed;

    std::string topic;
    iter >> topic;

    boost::asio::ip::address address;
    iter >> address;

    bool isAdd;
    iter >> isAdd;

    return std::make_shared<ForwardedSubscriptionRequest>(ForwardedSubscriptionRequest(user, address, clientId, feed, topic, isAdd));
}

void ForwardedSubscriptionRequest::writeBody(std::vector<char>::iterator &iter) const
{
    iter << _clientId;
    iter << _user;
    iter << _feed;
    iter << _topic;
    iter << _address;
    iter << _isAdd;
}

std::ostream &operator<<(std::ostream &os, const ForwardedSubscriptionRequest &value)
{
    return os
           << "user=\"" << value.user() << "\""
           << ",address=\"" << value.address() << "\""
           << ",clientId=\"" << value.clientId() << "\""
           << ",feed=\"" << value.feed() << "\""
           << ",topic=\"" << value.topic() << "\""
           << ",isAdd=" << value.isAdd();
}
