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

#include "messages/InteractorAdvertisement.hpp"

using jetblack::messagebus::messages::InteractorAdvertisement;
using jetblack::messagebus::messages::Message;

bool ShouldRoundTripSimple()
{
    auto generator = boost::uuids::random_generator();

    std::string user = "rblackbourn";
    boost::asio::ip::address addr(boost::asio::ip::make_address("192.168.0.1"));
    bool isJoining = false;

    InteractorAdvertisement value(user, addr, isJoining);

    auto buf(value.to_bytes());
    std::vector<char>::const_iterator iter = buf->begin();
    auto roundTrip = std::static_pointer_cast<InteractorAdvertisement>(Message::from_bytes(iter));
    return value == *roundTrip;
}

int main()
{
    bool ok = true;

    ok = ok && ShouldRoundTripSimple();

    return ok ? 0 : 1;
}