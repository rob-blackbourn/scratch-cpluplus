#include "serialization/boost/asio/buffer.hpp"
#include "serialization/native.hpp"

#include <algorithm>

std::vector<char>::const_iterator &operator>>(
    std::vector<char>::const_iterator &iter,
    boost::asio::mutable_buffer &value)
{
    size_t len;
    iter >> len;

    auto data = new unsigned char[len];
    auto begin{iter};
    iter += len;
    std::copy(begin, iter, data);

    value = boost::asio::mutable_buffer(data, len);

    return iter;
}

std::vector<char>::iterator &operator<<(
    std::vector<char>::iterator &iter,
    const boost::asio::mutable_buffer &value)
{
    iter << value.size();

    const unsigned char* begin = static_cast<const unsigned char*>(value.data());

    std::copy(begin, begin + value.size(), iter);

    iter += value.size();

    return iter;
}

size_t serialize_size(const boost::asio::mutable_buffer &value)
{
    return sizeof(size_t) + value.size();
}

std::vector<char>::const_iterator &operator>>(
    std::vector<char>::const_iterator &iter,
    boost::asio::const_buffer &value)
{
    size_t len;
    iter >> len;

    auto data = new unsigned char[len];
    auto begin{iter};
    iter += len;
    std::copy(begin, iter, data);

    value = boost::asio::const_buffer(data, len);

    return iter;
}

std::vector<char>::iterator &operator<<(
    std::vector<char>::iterator &iter,
    const boost::asio::const_buffer &value)
{
    iter << value.size();

    const unsigned char* begin = static_cast<const unsigned char*>(value.data());

    std::copy(begin, begin + value.size(), iter);

    iter += value.size();
    
    return iter;
}

size_t serialize_size(const boost::asio::const_buffer &value)
{

    return sizeof(size_t) + value.size();
}
