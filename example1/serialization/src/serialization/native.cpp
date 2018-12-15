#include "serialization/native.hpp"

#include <cstring>

/*
 * bool
 */

size_t serialize_size(bool value)
{
    return sizeof(unsigned char);
}

std::vector<char>::const_iterator &operator>>(
    std::vector<char>::const_iterator &iter,
    bool &value)
{
    value = *iter++ != 0;
    return iter;
}

std::vector<char>::iterator &operator<<(
    std::vector<char>::iterator &iter,
    bool value)
{
    *iter++ = value ? 1 : 0;
    return iter;
}

/*
 * unsigned char
 */

size_t serialize_size(unsigned char value)
{
    return sizeof(unsigned char);
}

std::vector<char>::const_iterator &operator>>(
    std::vector<char>::const_iterator &iter,
    unsigned char &value)
{
    value = static_cast<unsigned char>(*iter++);
    return iter;
}

std::vector<char>::iterator &operator<<(
    std::vector<char>::iterator &iter,
    unsigned char value)
{
    *iter++ = static_cast<char>(value);
    return iter;
}

/*
 * char
 */

size_t serialize_size(char value)
{
    return sizeof(char);
}

std::vector<char>::const_iterator &operator>>(
    std::vector<char>::const_iterator &iter,
    char &value)
{
    value = *iter++;
    return iter;
}

std::vector<char>::iterator &operator<<(
    std::vector<char>::iterator &iter,
    char value)
{
    *iter++ = value;
    return iter;
}

/*
 * unsigned int
 */

size_t serialize_size(unsigned int value)
{
    return sizeof(char) * 4;
}

std::vector<char>::const_iterator &operator>>(
    std::vector<char>::const_iterator &iter,
    unsigned int &value)
{
    value =
        ((static_cast<unsigned long>(static_cast<unsigned char>(*iter++))) << 24) |
        ((static_cast<unsigned long>(static_cast<unsigned char>(*iter++))) << 16) |
        ((static_cast<unsigned long>(static_cast<unsigned char>(*iter++))) << 8) |
        ((static_cast<unsigned long>(static_cast<unsigned char>(*iter++))) << 0);
    return iter;
}

std::vector<char>::iterator &operator<<(
    std::vector<char>::iterator &iter,
    unsigned int value)
{
    *iter++ = static_cast<char>((value >> 24) & 0xFF);
    *iter++ = static_cast<char>((value >> 16) & 0xFF);
    *iter++ = static_cast<char>((value >> 8) & 0xFF);
    *iter++ = static_cast<char>((value >> 0) & 0xFF);

    return iter;
}

/*
 * int
 */

size_t serialize_size(int value)
{
    return serialize_size(static_cast<unsigned int>(value));
}

std::vector<char>::const_iterator &operator>>(
    std::vector<char>::const_iterator &iter,
    int &value)
{
    unsigned int i;
    iter >> i;
    value = static_cast<int>(i);
    return iter;
}

std::vector<char>::iterator &operator<<(
    std::vector<char>::iterator &iter,
    int value)
{
    iter << static_cast<unsigned int>(value);
    return iter;
}

/*
 * size_t
 */

size_t serialize_size(size_t value)
{
    return sizeof(char) * 8;
}

std::vector<char>::const_iterator &operator>>(
    std::vector<char>::const_iterator &iter,
    size_t &value)
{
    value =
        (static_cast<size_t>(static_cast<unsigned char>(*iter++)) << 56) |
        (static_cast<size_t>(static_cast<unsigned char>(*iter++)) << 48) |
        (static_cast<size_t>(static_cast<unsigned char>(*iter++)) << 40) |
        (static_cast<size_t>(static_cast<unsigned char>(*iter++)) << 32) |
        (static_cast<size_t>(static_cast<unsigned char>(*iter++)) << 24) |
        (static_cast<size_t>(static_cast<unsigned char>(*iter++)) << 16) |
        (static_cast<size_t>(static_cast<unsigned char>(*iter++)) << 8) |
        (static_cast<size_t>(static_cast<unsigned char>(*iter++)) << 0);
    return iter;
}

std::vector<char>::iterator &operator<<(
    std::vector<char>::iterator &iter,
    size_t value)
{
    *iter++ = static_cast<char>((value >> 56) & 0xFF);
    *iter++ = static_cast<char>((value >> 48) & 0xFF);
    *iter++ = static_cast<char>((value >> 40) & 0xFF);
    *iter++ = static_cast<char>((value >> 32) & 0xFF);
    *iter++ = static_cast<char>((value >> 24) & 0xFF);
    *iter++ = static_cast<char>((value >> 16) & 0xFF);
    *iter++ = static_cast<char>((value >> 8) & 0xFF);
    *iter++ = static_cast<char>((value >> 0) & 0xFF);

    return iter;
}

// char*

size_t serialize_size(const char* value)
{
    return sizeof(size_t) + strlen(value);
}

std::vector<char>::const_iterator &operator>>(
    std::vector<char>::const_iterator &iter,
    char*& value)
{
    size_t len;
    iter >> len;

    auto start = iter;
    iter += len;
    value = new char[len];
    std::copy(start, iter, value);
    return iter;
}

std::vector<char>::iterator &operator<<(
    std::vector<char>::iterator &iter,
    const char* value)
{
    size_t len = strlen(value) + 1;
    iter << len;

    std::copy(value, value + len, iter);
    iter += len;
    return iter;
}
