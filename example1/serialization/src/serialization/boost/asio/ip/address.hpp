#ifndef __serialization_boost_ip_address_hpp
#define __serialization_boost_ip_address_hpp 1

#include <vector>
#include <stdexcept>
#include <boost/asio/ip/address.hpp>

#include "serialization/native.hpp"
#include "serialization/array.hpp"
#include "serialization/vector.hpp"

std::vector<char>::const_iterator &operator>>(
    std::vector<char>::const_iterator &iter,
    boost::asio::ip::address_v4 &value);

std::vector<char>::iterator &operator<<(
    std::vector<char>::iterator &iter,
    const boost::asio::ip::address_v4 &value);

std::vector<char>::const_iterator &operator>>(
    std::vector<char>::const_iterator &iter,
    boost::asio::ip::address_v6 &value);

std::vector<char>::iterator &operator<<(
    std::vector<char>::iterator &iter,
    const boost::asio::ip::address_v6 &value);

std::vector<char>::const_iterator &operator>>(
    std::vector<char>::const_iterator &iter,
    boost::asio::ip::address &value);

std::vector<char>::iterator &operator<<(
    std::vector<char>::iterator &iter,
    const boost::asio::ip::address &value);

size_t serialize_size(const boost::asio::ip::address &value);

#endif // __serialization_boost_ip_address_hpp
