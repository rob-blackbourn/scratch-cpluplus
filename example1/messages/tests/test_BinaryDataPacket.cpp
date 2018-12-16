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
#include "test_serialize.hpp"

using jetblack::messagebus::messages::BinaryDataPacket;

bool ShouldRoundTripSimple()
{
    auto generator = boost::uuids::random_generator();
    boost::uuids::uuid header(generator());
    std::vector<char> body{'a', 'b', 'c'};

    jetblack::messagebus::messages::BinaryDataPacket value{header, std::move(body)};
    return test_serialize(value);
}

int main()
{
    bool ok = true;

    ok = ok && ShouldRoundTripSimple();

    return ok ? 0 : 1;
}