#ifndef __serialization_string_hpp
#define __serialization_string_hpp 1

#include <vector>
#include <string>

#include "serialization/native.hpp"

inline
std::vector<unsigned char>::const_iterator &operator>>(
    std::vector<unsigned char>::const_iterator &iter,
    std::string &value)
{
    size_t len;
    iter >> len;
    value.reserve(len);
    value.assign(iter, iter + len);
    return iter;
}

inline
std::vector<unsigned char>::iterator &operator<<(
    std::vector<unsigned char>::iterator &iter,
    const std::string &value)
{
    iter << value.size();
    std::copy(value.data(), value.data() + value.size(), iter);
    iter += value.size();
    return iter;
}

size_t serialize_size(const std::string& value);

#endif // __serialization_string_hpp
