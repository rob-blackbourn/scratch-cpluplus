#include <vector>
#include <string>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

#include "messages/UnicastData.hpp"
#include "messages/BinaryDataPacket.hpp"

using jetblack::messagebus::messages::UnicastData;
using jetblack::messagebus::messages::Message;
using jetblack::messagebus::messages::BinaryDataPacket;

bool ShouldRoundTripSimple()
{
    auto generator = boost::uuids::random_generator();

    boost::uuids::uuid clientId(generator());
    std::string feed = "LSE";
    std::string topic = "VOD";
    bool isImage = true;

    boost::uuids::uuid header(generator());
    std::vector<char> body{'a', 'b', 'c'};
    BinaryDataPacket packet{header, std::move(body)};
    std::vector<BinaryDataPacket> data;
    data.push_back(std::move(packet));

    UnicastData value(clientId, feed, topic, isImage, std::move(data));

    auto buf(value.to_bytes());
    std::vector<char>::const_iterator iter = buf->begin();
    auto roundTrip = std::static_pointer_cast<UnicastData>(Message::from_bytes(iter));
    return value == *roundTrip;
}

int main()
{
    bool ok = true;

    ok = ok && ShouldRoundTripSimple();

    return ok ? 0 : 1;
}