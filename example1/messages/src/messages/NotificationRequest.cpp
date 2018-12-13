#include "messages/NotificationRequest.hpp"

#include "serialization/native.hpp"
#include "serialization/vector.hpp"
#include "serialization/string.hpp"

using jetblack::messagebus::messages::NotificationRequest;

// TODO: Is this redundent?
size_t serialize_size(const NotificationRequest& value)
{
    return 
        serialize_size(value.feed()) + 
        serialize_size(value.isAdd());
}

size_t NotificationRequest::bodySize() const
{
    return
        serialize_size(_feed) + 
        serialize_size(_isAdd);
}

std::shared_ptr<NotificationRequest> from_bytes(std::vector<unsigned char>::const_iterator& iter)
{
    std::string feed;
    iter >> feed;

    bool isAdd;
    iter >> isAdd;

    return std::make_shared<NotificationRequest>(NotificationRequest(feed, isAdd));
}

void NotificationRequest::writeBody(std::vector<unsigned char>::iterator& iter) const
{
    iter << _feed;
    iter << _isAdd;
}

std::ostream& operator << (std::ostream& os, const NotificationRequest& value)
{
    return os
        << "feed=\"" << value.feed() << "\""
        << ",isAdd=" << value.isAdd() ;
}
