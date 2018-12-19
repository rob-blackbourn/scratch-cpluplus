#include <vector>
#include <string>

#include "messages/NotificationRequest.hpp"

using jetblack::messagebus::messages::NotificationRequest;
using jetblack::messagebus::messages::Message;

bool ShouldRoundTripSimple()
{
    std::string feed = "LSE";
    bool isAdd = true;

    NotificationRequest value(feed, isAdd);

    auto buf(value.to_bytes());
    std::vector<char>::const_iterator iter = buf->begin();
    auto roundTrip = std::static_pointer_cast<NotificationRequest>(Message::from_bytes(iter));
    return value == *roundTrip;
}

int main()
{
    bool ok = true;

    ok = ok && ShouldRoundTripSimple();

    return ok ? 0 : 1;
}