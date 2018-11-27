#ifndef __serialization_boost_uuid_hpp
#define __serialization_boost_uuid_hpp

#include <stdexcept>
#include <vector>

#include <boost/uuid/uuid.hpp>

#include "serialization/native.hpp"
#include "serialization/vector.hpp"

std::vector<unsigned char>::const_iterator &operator>>(
    std::vector<unsigned char>::const_iterator &iter,
    boost::uuids::uuid &value)
{
    std::vector<unsigned char> bytes;
    iter >> bytes;
    if (bytes.size() != boost::uuids::uuid::static_size())
        throw std::out_of_range("Invalid size for uuid");
    
    std::copy(bytes.begin(), bytes.end(), value.data);

    return iter;
}

std::vector<unsigned char>::iterator &operator<<(
    std::vector<unsigned char>::iterator &iter,
    const boost::uuids::uuid &value)
{
    iter << value.size();
    std::copy(value.begin(), value.end(), iter);
    iter += value.size();
    return iter;
}

#endif // __serialization_boost_uuid_hpp
