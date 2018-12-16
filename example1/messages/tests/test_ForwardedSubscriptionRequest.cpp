#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/asio/buffer.hpp>
#include <boost/asio/ip/address.hpp>

#include "serialization/native.hpp"
#include "serialization/string.hpp"
#include "serialization/boost/uuid/uuid.hpp"

#include "messages/ForwardedSubscriptionRequest.hpp"

using jetblack::messagebus::messages::ForwardedSubscriptionRequest;
using jetblack::messagebus::messages::Message;

bool ShouldRoundTripSimple()
{
    auto generator = boost::uuids::random_generator();

    std::string user = "rblackbourn";
    boost::uuids::uuid clientId(generator());
    boost::asio::ip::address addr(boost::asio::ip::make_address("192.168.0.1"));
    std::string feed = "LSE";
    std::string topic = "VOD";
    bool isAdd = true;

    ForwardedSubscriptionRequest value(user, addr, clientId, feed, topic, isAdd);

    auto buf(value.to_bytes());
    std::vector<char>::const_iterator iter = buf->begin();
    auto roundTrip = std::static_pointer_cast<ForwardedSubscriptionRequest>(Message::from_bytes(iter));
    return value == *roundTrip;
}

int main()
{
    bool ok = true;

    ok = ok && ShouldRoundTripSimple();

    return ok ? 0 : 1;
}