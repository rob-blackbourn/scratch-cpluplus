#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/asio/buffer.hpp>

#include "serialization/native.hpp"
#include "serialization/string.hpp"
#include "serialization/boost/uuid/uuid.hpp"

#include "messages/BinaryDataPacket.hpp"

using jetblack::messagebus::messages::BinaryDataPacket;

void ShouldRoundTripSimple()
{
    auto generator = boost::uuids::random_generator();
    boost::uuids::uuid header(generator());
    std::vector<unsigned char> body { 'a', 'b', 'c'};
    boost::asio::const_buffer buf(boost::asio::buffer("This is not a test"));

    jetblack::messagebus::messages::BinaryDataPacket source(header, std::move(body));

    std::vector<unsigned char> v(serialize_size(source));
    std::vector<unsigned char>::iterator viter(v.begin());

    viter << source;

    jetblack::messagebus::messages::BinaryDataPacket destination;
    std::vector<unsigned char>::const_iterator vconstiter(v.begin());

    vconstiter >> destination;
    std::cout << "source={" << source << "},destination={" << destination << "}" << std::endl;
}

int main()
{
    ShouldRoundTripSimple();
}