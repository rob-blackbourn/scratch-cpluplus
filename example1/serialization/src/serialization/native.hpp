#ifndef __Serialization_Native_h
#define __Serialization_Native_h

#include <vector>

std::vector<unsigned char>::const_iterator &operator>>(
    std::vector<unsigned char>::const_iterator &iter,
    unsigned char &value)
{
    value = *iter++;
    return iter;
}

std::vector<unsigned char>::iterator &operator<<(
    std::vector<unsigned char>::iterator &iter,
    unsigned char value)
{
    *iter++ = value;
    return iter;
}

std::vector<unsigned char>::const_iterator &operator>>(
    std::vector<unsigned char>::const_iterator &iter,
    int &value)
{
    value =
        (static_cast<int>(*iter++) << 24) +
        (static_cast<int>(*iter++) << 16) +
        (static_cast<int>(*iter++) << 8) +
        (static_cast<int>(*iter++) << 0);
    return iter;
}

std::vector<unsigned char>::iterator &operator<<(
    std::vector<unsigned char>::iterator &iter,
    int value)
{
    *iter++ = static_cast<unsigned char>((value >> 24) & 0xFF);
    *iter++ = static_cast<unsigned char>((value >> 16) & 0xFF);
    *iter++ = static_cast<unsigned char>((value >> 8) & 0xFF);
    *iter++ = static_cast<unsigned char>((value >> 0) & 0xFF);

    return iter;
}

std::vector<unsigned char>::const_iterator &operator>>(
    std::vector<unsigned char>::const_iterator &iter,
    size_t &value)
{
    value =
        (static_cast<size_t>(*iter++) << 56) +
        (static_cast<size_t>(*iter++) << 48) +
        (static_cast<size_t>(*iter++) << 40) +
        (static_cast<size_t>(*iter++) << 32) +
        (static_cast<size_t>(*iter++) << 24) +
        (static_cast<size_t>(*iter++) << 16) +
        (static_cast<size_t>(*iter++) << 8) +
        (static_cast<size_t>(*iter++) << 0);
    return iter;
}

std::vector<unsigned char>::iterator &operator<<(
    std::vector<unsigned char>::iterator &iter,
    size_t value)
{
    *iter++ = static_cast<unsigned char>((value >> 56) & 0xFF);
    *iter++ = static_cast<unsigned char>((value >> 48) & 0xFF);
    *iter++ = static_cast<unsigned char>((value >> 40) & 0xFF);
    *iter++ = static_cast<unsigned char>((value >> 32) & 0xFF);
    *iter++ = static_cast<unsigned char>((value >> 24) & 0xFF);
    *iter++ = static_cast<unsigned char>((value >> 16) & 0xFF);
    *iter++ = static_cast<unsigned char>((value >> 8) & 0xFF);
    *iter++ = static_cast<unsigned char>((value >> 0) & 0xFF);

    return iter;
}

#endif // __Serialization_Native_h
