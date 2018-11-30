#include "messages/BinaryDataPacket.hpp"

#include "serialization/native.hpp"
#include "serialization/vector.hpp"
#include "serialization/boost/uuid/uuid.hpp"

using jetblack::messagebus::messages::BinaryDataPacket;

std::vector<unsigned char>::iterator& operator << (
    std::vector<unsigned char>::iterator& iter,
    const BinaryDataPacket& value)
{
    iter << value.header();
    iter << value.body();
    return iter;
}

std::vector<unsigned char>::const_iterator& operator >> (
    std::vector<unsigned char>::const_iterator& iter,
    BinaryDataPacket& value)
{
    boost::uuids::uuid header;
    iter >> header;

    std::vector<unsigned char> body;
    iter >> body;

    value = BinaryDataPacket(header, std::move(body));

    return iter;
}

size_t serialize_size(const BinaryDataPacket& value)
{
    auto b = value.body();

    return
        serialize_size(value.header()) + 
        serialize_size(b);
}