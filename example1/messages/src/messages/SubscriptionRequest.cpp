#include "messages/SubscriptionRequest.hpp"

#include "serialization/native.hpp"
#include "serialization/vector.hpp"
#include "serialization/string.hpp"

using jetblack::messagebus::messages::SubscriptionRequest;

// TODO: Is this redundent?
size_t serialize_size(const SubscriptionRequest& value)
{
    return 
        serialize_size(value.feed()) + 
        serialize_size(value.topic()) + 
        serialize_size(value.isAdd());
}

size_t SubscriptionRequest::bodySize() const
{
    return
        serialize_size(_feed) + 
        serialize_size(_topic) + 
        serialize_size(_isAdd);
}

std::shared_ptr<SubscriptionRequest> from_bytes(std::vector<unsigned char>::const_iterator& iter)
{
    std::string feed;
    iter >> feed;

    std::string topic;
    iter >> topic;

    bool isAdd;
    iter >> isAdd;

    return std::make_shared<SubscriptionRequest>(SubscriptionRequest(feed, topic, isAdd));
}

void SubscriptionRequest::writeBody(std::vector<unsigned char>::iterator& iter) const
{
    iter << _feed;
    iter << _topic;
    iter << _isAdd;
}

std::ostream& operator << (std::ostream& os, const SubscriptionRequest& value)
{
    return os
        << "feed=\"" << value.feed() << "\""
        << ",topic=\"" << value.topic() << "\""
        << ",isAdd=" << value.isAdd() ;
}
