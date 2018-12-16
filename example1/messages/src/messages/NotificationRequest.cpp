#include "messages/NotificationRequest.hpp"

#include "serialization/native.hpp"
#include "serialization/vector.hpp"
#include "serialization/string.hpp"

using jetblack::messagebus::messages::NotificationRequest;

size_t NotificationRequest::bodySize() const noexcept
{
    return serialize_size(_feed) +
           serialize_size(_isAdd);
}

std::shared_ptr<NotificationRequest> NotificationRequest::from_bytes(std::vector<char>::const_iterator &iter)
{
    std::string feed;
    iter >> feed;

    bool isAdd;
    iter >> isAdd;

    return std::make_shared<NotificationRequest>(NotificationRequest(feed, isAdd));
}

void NotificationRequest::writeBody(std::vector<char>::iterator &iter) const
{
    iter << _feed;
    iter << _isAdd;
}

std::ostream &operator<<(std::ostream &os, const NotificationRequest &value)
{
    return os
           << "feed=\"" << value.feed() << "\""
           << ",isAdd=" << value.isAdd();
}
