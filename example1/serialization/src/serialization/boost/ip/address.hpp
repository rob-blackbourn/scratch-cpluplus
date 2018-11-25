#ifndef __serialization_boost_ip_address_hpp
#define __serialization_boost_ip_address_hpp

#include <vector>
#include <boost/asio/ip/address.hpp>

#include "serialization/native.hpp"

std::vector<unsigned char>::const_iterator &operator>>(
    std::vector<unsigned char>::const_iterator &iter,
    boost::asio::ip::address_v4 &value)
{
    unsigned long l;
    iter >> l;
    value = boost::asio::ip::address_v4(l);
    return iter;
}

std::vector<unsigned char>::iterator &operator<<(
    std::vector<unsigned char>::iterator &iter,
    const boost::asio::ip::address_v4 &value)
{
    iter << value.to_ulong();
    return iter;
}

std::vector<unsigned char>::const_iterator &operator>>(
    std::vector<unsigned char>::const_iterator &iter,
    boost::asio::ip::address_v6 &value)
{
    boost::asio::ip::address_v6::bytes_type buf;
    auto start = iter;
    iter += buf.size();
    std::copy(start, iter, buf.begin());
    value = boost::asio::ip::address_v6(buf);
    return iter;
}

std::vector<unsigned char>::iterator &operator<<(
    std::vector<unsigned char>::iterator &iter,
    const boost::asio::ip::address_v6 &value)
{
    auto buf(value.to_bytes());
    std::copy(buf.begin(), buf.end(), iter);
    iter += buf.size();
    return iter;
}

std::vector<unsigned char>::const_iterator &operator>>(
    std::vector<unsigned char>::const_iterator &iter,
    boost::asio::ip::address &value)
{
    size_t b = *iter++;

    if (b == 4)
    {
        auto addr(value.to_v4());
        return iter >> addr;
        value = addr;
    }
    else
    {
        auto addr(value.to_v6());
        return iter >> addr;
        value = addr;
    }
}

std::vector<unsigned char>::iterator &operator<<(
    std::vector<unsigned char>::iterator &iter,
    const boost::asio::ip::address &value)
{
    if (value.is_v4())
    {
        *iter++ = 4;
        iter << value.to_v4();
    }
    else
    {
        *iter++ = 6;
        iter << value.to_v6();
    }

    return iter;
}

#endif // __serialization_boost_ip_address_hpp
