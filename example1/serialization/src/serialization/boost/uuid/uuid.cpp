#include "serialization/boost/uuid/uuid.hpp"
#include "serialization/array.hpp"

#include <stdexcept>
#include <vector>

#include <boost/uuid/uuid.hpp>

#include "serialization/native.hpp"
#include "serialization/vector.hpp"

size_t serialize_size(const boost::uuids::uuid &value) noexcept
{
    return value.size();
}

std::vector<char>::const_iterator &operator>>(
    std::vector<char>::const_iterator &iter,
    boost::uuids::uuid &value)
{
    auto start = iter;
    iter += value.size();
    std::copy(start, iter, value.begin());
    return iter;
}

std::vector<char>::iterator &operator<<(
    std::vector<char>::iterator &iter,
    const boost::uuids::uuid &value)
{
    std::copy(value.begin(), value.end(), iter);
    iter += value.size();
    return iter;
}