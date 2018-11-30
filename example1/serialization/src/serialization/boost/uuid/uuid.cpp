#include "serialization/boost/uuid/uuid.hpp"
#include "serialization/array.hpp"

#include <stdexcept>
#include <vector>

#include <boost/uuid/uuid.hpp>

#include "serialization/native.hpp"
#include "serialization/vector.hpp"

std::vector<unsigned char>::const_iterator &operator>>(
    std::vector<unsigned char>::const_iterator &iter,
    boost::uuids::uuid &value)
{
    std::array<uint8_t, sizeof(value.data)> bytes;
    iter >> bytes;
    std::copy(bytes.begin(), bytes.end(), value.data);

    return iter;
}

std::vector<unsigned char>::iterator &operator<<(
    std::vector<unsigned char>::iterator &iter,
    const boost::uuids::uuid &value)
{
    size_t len = sizeof(value.data);
    std::copy(value.data, value.data + len, iter);
    iter += len;
    return iter;
}