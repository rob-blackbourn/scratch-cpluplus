#include <vector>
#include <string>

#include <boost/asio/ip/address.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

#include "messages/ForwardedMulticastData.hpp"
#include "messages/BinaryDataPacket.hpp"

using jetblack::messagebus::messages::ForwardedMulticastData;
using jetblack::messagebus::messages::Message;
using jetblack::messagebus::messages::BinaryDataPacket;

bool ShouldRoundTripSimple()
{
    std::string user = "rblackbourn";
    boost::asio::ip::address address(boost::asio::ip::make_address("192.168.0.1"));
    std::string feed = "LSE";
    std::string topic = "VOD";
    bool isImage = true;

    auto generator = boost::uuids::random_generator();
    boost::uuids::uuid header(generator());
    std::vector<char> body{'a', 'b', 'c'};
    BinaryDataPacket packet{header, std::move(body)};
    std::vector<BinaryDataPacket> data;
    data.push_back(std::move(packet));

    ForwardedMulticastData value(user, address, feed, topic, isImage, std::move(data));

    auto buf(value.to_bytes());
    std::vector<char>::const_iterator iter = buf->begin();
    auto roundTrip = std::static_pointer_cast<ForwardedMulticastData>(Message::from_bytes(iter));
    return value == *roundTrip;
}

int main()
{
    bool ok = true;

    ok = ok && ShouldRoundTripSimple();

    return ok ? 0 : 1;
}