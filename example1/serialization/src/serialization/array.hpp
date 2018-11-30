#ifndef __serialization_array_hpp
#define __serialization_array_hpp 1

#include <vector>
#include <array>

#include "serialization/native.hpp"

template<std::size_t N>
inline
std::vector<unsigned char>::const_iterator &operator>>(
    std::vector<unsigned char>::const_iterator &iter,
    std::array<unsigned char, N> &value)
{
    auto start = iter;
    iter += N;
    std::copy(start, iter, value.begin());
    return iter;
}

template<std::size_t N>
inline
std::vector<unsigned char>::iterator &operator<<(
    std::vector<unsigned char>::iterator &iter,
    const std::array<unsigned char, N> &value)
{
    std::copy(value.begin(), value.end(), iter);
    iter += N;
    return iter;
}


#endif // __serialization_array_hpp
