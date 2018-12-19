#include <vector>
#include <string>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

#include "messages/MulticastData.hpp"
#include "messages/BinaryDataPacket.hpp"

using jetblack::messagebus::messages::MulticastData;
using jetblack::messagebus::messages::Message;
using jetblack::messagebus::messages::BinaryDataPacket;

bool ShouldRoundTripSimple()
{
    std::string feed = "LSE";
    std::string topic = "VOD";
    bool isImage = true;

    auto generator = boost::uuids::random_generator();
    boost::uuids::uuid header(generator());
    std::vector<char> body{'a', 'b', 'c'};
    BinaryDataPacket packet{header, std::move(body)};
    std::vector<BinaryDataPacket> data;
    data.push_back(std::move(packet));

    MulticastData value(feed, topic, isImage, std::move(data));

    auto buf(value.to_bytes());
    std::vector<char>::const_iterator iter = buf->begin();
    auto roundTrip = std::static_pointer_cast<MulticastData>(Message::from_bytes(iter));
    return value == *roundTrip;
}

int main()
{
    bool ok = true;

    ok = ok && ShouldRoundTripSimple();

    return ok ? 0 : 1;
}