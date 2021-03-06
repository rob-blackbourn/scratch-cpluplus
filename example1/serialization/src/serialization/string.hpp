#ifndef __serialization_string_hpp
#define __serialization_string_hpp 1

#include <vector>
#include <string>

#include "serialization/native.hpp"

inline std::vector<char>::const_iterator &operator>>(
    std::vector<char>::const_iterator &iter,
    std::string &value)
{
    size_t len;
    iter >> len;
    auto begin = iter;
    iter += len;
    value.resize(len);
    std::copy(begin, iter, value.begin());
    return iter;
}

inline std::vector<char>::iterator &operator<<(
    std::vector<char>::iterator &iter,
    const std::string &value)
{
    iter << value.size();
    std::copy(value.begin(), value.end(), iter);
    iter += value.size();
    return iter;
}

size_t serialize_size(const std::string &value) noexcept;

#endif // __serialization_string_hpp
