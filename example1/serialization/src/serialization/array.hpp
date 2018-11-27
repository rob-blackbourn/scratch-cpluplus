#ifndef __serializatiion_array_hpp
#define __serializatiion_array_hpp

#include <vector>
#include <array>

#include "serialization/native.hpp"

template<std::size_t N>
std::vector<unsigned char>::const_iterator &operator>>(
    std::vector<unsigned char>::const_iterator &iter,
    std::array<unsigned char, N> &value)
{
    size_t len;
    iter >> len;
    value.reserve(len);
    value.assign(iter, iter + len);
    return iter;
}

template<std::size_t N>
std::vector<unsigned char>::iterator &operator<<(
    std::vector<unsigned char>::iterator &iter,
    const std::array<unsigned char, N> &value)
{
    iter << value.size();
    std::copy(value.data(), value.data() + value.size(), iter);
    iter += value.size();
    return iter;
}


#endif // __serializatiion_array_hpp
