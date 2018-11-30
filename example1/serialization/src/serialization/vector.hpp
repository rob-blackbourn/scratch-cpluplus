#ifndef __serializatiion_vector_hpp
#define __serializatiion_vector_hpp 1

#include <vector>
#include <numeric>

#include "serialization/native.hpp"

inline
std::vector<unsigned char>::const_iterator &operator>>(
    std::vector<unsigned char>::const_iterator &iter,
    std::vector<unsigned char> &value)
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
    const std::vector<unsigned char> &value)
{
    iter << value.size();
    std::copy(value.data(), value.data() + value.size(), iter);
    iter += value.size();
    return iter;
}

template<typename T>
inline
size_t serialize_size(std::vector<T> const& value)
{
    return sizeof(size_t) + 
        std::accumulate(
            value.begin(),
            value.end(),
            static_cast<size_t>(0),
            [&](auto total, auto& element) { return total + serialize_size(element); });
}

#endif // __serializatiion_vector_hpp
