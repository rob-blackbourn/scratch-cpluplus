#include "messages/ForwardedSubscriptionRequest.hpp"

#include "serialization/native.hpp"
#include "serialization/vector.hpp"
#include "serialization/string.hpp"
#include "serialization/boost/ip/address.hpp"
#include "serialization/boost/uuid/uuid.hpp"

using jetblack::messagebus::messages::ForwardedSubscriptionRequest;

// TODO: Is this redundent?
size_t serialize_size(const ForwardedSubscriptionRequest& value)
{
    return 
        serialize_size(value.user()) + 
        serialize_size(value.address()) + 
        serialize_size(value.feed()) + 
        serialize_size(value.topic()) +
        serialize_size(value.isAdd());
}

size_t ForwardedSubscriptionRequest::bodySize() const
{
    return 
        serialize_size(_user) + 
        serialize_size(_address) + 
        serialize_size(_feed) + 
        serialize_size(_topic) + 
        serialize_size(_isAdd);
}

std::shared_ptr<ForwardedSubscriptionRequest> from_bytes(std::vector<unsigned char>::const_iterator& iter)
{
    std::string user;
    iter >> user;

    boost::asio::ip::address address;
    iter >> address;

    boost::uuids::uuid clientId;
    iter >> clientId;

    std::string feed;
    iter >> feed;

    std::string topic;
    iter >> topic;

    bool isAdd;
    iter >> isAdd;

    return std::make_shared<ForwardedSubscriptionRequest>(ForwardedSubscriptionRequest(user, address, clientId, feed, topic, isAdd));
}

void ForwardedSubscriptionRequest::writeBody(std::vector<unsigned char>::iterator& iter) const
{
    iter << _user;
    iter << _address;
    iter << _clientId;
    iter << _feed;
    iter << _topic;
    iter << _isAdd;
}

std::ostream& operator << (std::ostream& os, const ForwardedSubscriptionRequest& value)
{
    return os
        << "user=\"" << value.user() << "\""
        << ",address=\"" << value.address() << "\""
        << ",clientId=\"" << value.clientId() << "\""
        << ",feed=\"" << value.feed() << "\""
        << ",topic=\"" << value.topic() << "\""
        << ",isAdd=" << value.isAdd() ;
}
