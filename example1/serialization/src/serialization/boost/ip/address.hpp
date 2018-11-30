#ifndef __serialization_boost_ip_address_hpp
#define __serialization_boost_ip_address_hpp 1

#include <vector>
#include <stdexcept>
#include <boost/asio/ip/address.hpp>

#include "serialization/native.hpp"
#include "serialization/array.hpp"
#include "serialization/vector.hpp"

inline
std::vector<unsigned char>::const_iterator &operator>>(
    std::vector<unsigned char>::const_iterator &iter,
    boost::asio::ip::address_v4 &value)
{
    std::vector<unsigned char> bytes;
    iter >> bytes;
    if (bytes.size() != std::tuple_size<boost::asio::ip::address_v4::bytes_type>())
        throw std::out_of_range("Invalid size");

    boost::asio::ip::address_v4::bytes_type bytes_v4;
    std::copy(bytes.begin(), bytes.end(), bytes_v4.begin());
    boost::asio::ip::address_v4 addr_v4(bytes_v4);
    value = addr_v4;

    return iter;
}

inline
std::vector<unsigned char>::iterator &operator<<(
    std::vector<unsigned char>::iterator &iter,
    const boost::asio::ip::address_v4 &value)
{
    iter << value.to_bytes();
    return iter;
}

inline
std::vector<unsigned char>::const_iterator &operator>>(
    std::vector<unsigned char>::const_iterator &iter,
    boost::asio::ip::address_v6 &value)
{
    std::vector<unsigned char> bytes;
    iter >> bytes;
    if (bytes.size() != std::tuple_size<boost::asio::ip::address_v6::bytes_type>())
        throw std::out_of_range("Invalid size");

    boost::asio::ip::address_v6::bytes_type bytes_v6;
    std::copy(bytes.begin(), bytes.end(), bytes_v6.begin());
    boost::asio::ip::address_v6 addr_v6(bytes_v6);
    value = addr_v6;

    return iter;
}

inline
std::vector<unsigned char>::iterator &operator<<(
    std::vector<unsigned char>::iterator &iter,
    const boost::asio::ip::address_v6 &value)
{
    iter << value.to_bytes();
    return iter;
}

inline
std::vector<unsigned char>::const_iterator &operator>>(
    std::vector<unsigned char>::const_iterator &iter,
    boost::asio::ip::address &value)
{
    std::vector<unsigned char> bytes;
    iter >> bytes;

    if (bytes.size() == std::tuple_size<boost::asio::ip::address_v4::bytes_type>())
    {
        boost::asio::ip::address_v4::bytes_type bytes_v4;
        std::copy(bytes.begin(), bytes.end(), bytes_v4.begin());
        boost::asio::ip::address_v4 addr_v4(bytes_v4);
        boost::asio::ip::address addr(addr_v4);
        value = addr;
    }
    else if (bytes.size() == std::tuple_size<boost::asio::ip::address_v6::bytes_type>())
    {
        boost::asio::ip::address_v6::bytes_type bytes_v6;
        std::copy(bytes.begin(), bytes.end(), bytes_v6.begin());
        boost::asio::ip::address_v6 addr_v6(bytes_v6);
        boost::asio::ip::address addr(addr_v6);
        value = addr;
    }
    else
    {
        throw std::domain_error("Unknown address type");
    }

    return iter;
}

inline
std::vector<unsigned char>::iterator &operator<<(
    std::vector<unsigned char>::iterator &iter,
    const boost::asio::ip::address &value)
{
    if (value.is_v4())
    {
        auto bytes = value.to_v4().to_bytes();
        std::vector<unsigned char> buf(bytes.size());
        std::copy(bytes.begin(), bytes.end(), buf.begin());
        iter << buf;
    }
    else
    {
        auto bytes = value.to_v6().to_bytes();
        std::vector<unsigned char> buf(bytes.size());
        std::copy(bytes.begin(), bytes.end(), buf.begin());
        iter << buf;
    }

    return iter;
}

inline size_t serialize_size(const boost::asio::ip::address &value)
{
    return sizeof(size_t) + (value.is_v4() ? value.to_v4().to_bytes().size() : sizeof(size_t) + value.to_v6().to_bytes().size());
}

#endif // __serialization_boost_ip_address_hpp
