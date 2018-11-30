#ifndef __serialization_boost_uuid_hpp
#define __serialization_boost_uuid_hpp 1

#include <stdexcept>
#include <vector>

#include <boost/uuid/uuid.hpp>

#include "serialization/native.hpp"
#include "serialization/vector.hpp"

std::vector<unsigned char>::const_iterator &operator>>(
    std::vector<unsigned char>::const_iterator &iter,
    boost::uuids::uuid &value);

std::vector<unsigned char>::iterator &operator<<(
    std::vector<unsigned char>::iterator &iter,
    const boost::uuids::uuid &value);

inline size_t serialize_size(const boost::uuids::uuid &value)
{
    return value.size();
}

#endif // __serialization_boost_uuid_hpp
