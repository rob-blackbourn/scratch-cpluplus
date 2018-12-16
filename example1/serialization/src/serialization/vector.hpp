#ifndef __serializatiion_vector_hpp
#define __serializatiion_vector_hpp 1

#include <vector>
#include <numeric>

#include "serialization/native.hpp"

template <typename T>
inline std::vector<char>::const_iterator &operator>>(
    std::vector<char>::const_iterator &iter,
    std::vector<T> &value)
{
    size_t len;
    iter >> len;
    value.reserve(len);
    for (int i = 0; i < len; ++i)
    {
        T element;
        iter >> element;
        value.push_back(element);
    }
    return iter;
}

template <typename T>
inline std::vector<char>::iterator &operator<<(
    std::vector<char>::iterator &iter,
    const std::vector<T> &value)
{
    iter << value.size();
    for (auto i = value.begin(); i != value.end(); ++i)
        iter << *i;
    return iter;
}

template <typename T>
inline size_t serialize_size(std::vector<T> const &value) noexcept
{
    return sizeof(size_t) +
           std::accumulate(
               value.begin(),
               value.end(),
               static_cast<size_t>(0),
               [&](auto total, auto &element) { return total + serialize_size(element); });
}

#endif // __serializatiion_vector_hpp
