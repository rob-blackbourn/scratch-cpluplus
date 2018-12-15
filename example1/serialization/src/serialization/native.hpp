#ifndef __serialization_native_hpp
#define __serialization_native_hpp 1

#include <vector>

/*
 * bool
 */

inline size_t serialize_size(bool value)
{
    return sizeof(unsigned char);
}

inline std::vector<char>::const_iterator &operator>>(
    std::vector<char>::const_iterator &iter,
    bool &value)
{
    value = *iter++ != 0;
    return iter;
}

inline std::vector<char>::iterator &operator<<(
    std::vector<char>::iterator &iter,
    bool value)
{
    *iter++ = value ? 1 : 0;
    return iter;
}

/*
 * unsigned char
 */

inline size_t serialize_size(unsigned char value)
{
    return sizeof(unsigned char);
}

inline std::vector<char>::const_iterator &operator>>(
    std::vector<char>::const_iterator &iter,
    unsigned char &value)
{
    value = static_cast<unsigned char>(*iter++);
    return iter;
}

inline std::vector<char>::iterator &operator<<(
    std::vector<char>::iterator &iter,
    unsigned char value)
{
    *iter++ = static_cast<char>(value);
    return iter;
}

/*
 * char
 */

inline size_t serialize_size(char value)
{
    return sizeof(char);
}

inline std::vector<char>::const_iterator &operator>>(
    std::vector<char>::const_iterator &iter,
    char &value)
{
    value = *iter++;
    return iter;
}

inline std::vector<char>::iterator &operator<<(
    std::vector<char>::iterator &iter,
    char value)
{
    *iter++ = value;
    return iter;
}

/*
 * unsigned int
 */

inline size_t serialize_size(unsigned int value)
{
    return sizeof(char) * 4;
}

inline std::vector<char>::const_iterator &operator>>(
    std::vector<char>::const_iterator &iter,
    unsigned int &value)
{
    value =
        (static_cast<int>(*iter++) << 24) +
        (static_cast<int>(*iter++) << 16) +
        (static_cast<int>(*iter++) << 8) +
        (static_cast<int>(*iter++) << 0);
    return iter;
}

inline std::vector<char>::iterator &operator<<(
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

inline size_t serialize_size(int value)
{
    return serialize_size(static_cast<unsigned int>(value));
}

inline std::vector<char>::const_iterator &operator>>(
    std::vector<char>::const_iterator &iter,
    int &value)
{
    unsigned int i;
    iter >> i;
    value = static_cast<int>(i);
    return iter;
}

inline std::vector<char>::iterator &operator<<(
    std::vector<char>::iterator &iter,
    int value)
{
    iter << static_cast<unsigned int>(value);
    return iter;
}

/*
 * size_t
 */

inline size_t serialize_size(size_t value)
{
    return sizeof(char) * 8;
}

inline std::vector<char>::const_iterator &operator>>(
    std::vector<char>::const_iterator &iter,
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

inline std::vector<char>::iterator &operator<<(
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

#endif // __serialization_native_hpp
