#ifndef __serialization_boost_uuid_hpp
#define __serialization_boost_uuid_hpp 1

#include <stdexcept>
#include <vector>

#include <boost/uuid/uuid.hpp>

std::vector<char>::const_iterator &operator>>(
    std::vector<char>::const_iterator &iter,
    boost::uuids::uuid &value);

std::vector<char>::iterator &operator<<(
    std::vector<char>::iterator &iter,
    const boost::uuids::uuid &value);

size_t serialize_size(const boost::uuids::uuid &value);

#endif // __serialization_boost_uuid_hpp
