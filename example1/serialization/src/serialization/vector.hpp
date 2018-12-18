#ifndef __serializatiion_vector_hpp
#define __serializatiion_vector_hpp 1

#include <vector>
#include <numeric>
#include <stdexcept>

#include "serialization/native.hpp"

template <typename T>
inline std::vector<char>::const_iterator &operator>>(
    std::vector<char>::const_iterator &iter,
    std::vector<T> &value)
{
    size_t len;
    iter >> len;

    value.resize(len);
    for (int i = 0; i < len; ++i)
    {
        T element;
        iter >> element;
        value[i] = std::move(element);
    }

    return iter;
}

template <>
inline std::vector<char>::const_iterator &operator>>(
    std::vector<char>::const_iterator &iter,
    std::vector<char> &value)
{
    size_t len;
    iter >> len;

    value.resize(len);
    auto start = iter;
    iter += len;
    std::copy(start, iter, value.begin());

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
    size_t len = 0;
    len += sizeof(size_t);
    len += std::accumulate(
               value.begin(),
               value.end(),
               static_cast<size_t>(0),
               [&](auto total, auto &element) { return total + serialize_size(element); });
    return len;
}

#endif // __serializatiion_vector_hpp
