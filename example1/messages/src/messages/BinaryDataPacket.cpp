#include "messages/BinaryDataPacket.hpp"

#include "serialization/native.hpp"
#include "serialization/vector.hpp"
#include "serialization/boost/uuid/uuid.hpp"

#include <boost/uuid/uuid_io.hpp>

using jetblack::messagebus::messages::BinaryDataPacket;

std::vector<char>::iterator& operator << (
    std::vector<char>::iterator& iter,
    const BinaryDataPacket& value)
{
    iter << value.header();
    iter << value.body();
    return iter;
}

std::vector<char>::const_iterator& operator >> (
    std::vector<char>::const_iterator& iter,
    BinaryDataPacket& value)
{
    boost::uuids::uuid header;
    iter >> header;

    std::vector<char> body;
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

std::ostream& operator << (std::ostream& os, const BinaryDataPacket& value)
{
    return os << "header=" << value.header() << ",body.size()=" << value.body().size();
}
