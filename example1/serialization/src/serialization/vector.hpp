#ifndef __serializatiion_vector_hpp
#define __serializatiion_vector_hpp

#include <vector>

#include "serialization/native.hpp"

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

std::vector<unsigned char>::iterator &operator<<(
    std::vector<unsigned char>::iterator &iter,
    const std::vector<unsigned char> &value)
{
    iter << value.size();
    std::copy(value.data(), value.data() + value.size(), iter);
    iter += value.size();
    return iter;
}


#endif // __serializatiion_vector_hpp
