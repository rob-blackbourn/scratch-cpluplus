#include <vector>
#include <string>

#include "messages/SubscriptionRequest.hpp"

using jetblack::messagebus::messages::SubscriptionRequest;
using jetblack::messagebus::messages::Message;

bool ShouldRoundTripSimple()
{
    std::string feed = "LSE";
    std::string topic = "VOD";
    bool isAdd = true;

    SubscriptionRequest value(feed, topic, isAdd);

    auto buf(value.to_bytes());
    std::vector<char>::const_iterator iter = buf->begin();
    auto roundTrip = std::static_pointer_cast<SubscriptionRequest>(Message::from_bytes(iter));
    return value == *roundTrip;
}

int main()
{
    bool ok = true;

    ok = ok && ShouldRoundTripSimple();

    return ok ? 0 : 1;
}