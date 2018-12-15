#ifndef __serialization_boost_buffer_hpp
#define __serialization_boost_buffer_hpp 1

#include <vector>

#include <boost/asio/buffer.hpp>

std::vector<char>::const_iterator &operator>>(
    std::vector<char>::const_iterator &iter,
    boost::asio::mutable_buffer &value);

std::vector<char>::iterator &operator<<(
    std::vector<char>::iterator &iter,
    const boost::asio::mutable_buffer &value);

size_t serialize_size(const boost::asio::mutable_buffer &value);

std::vector<char>::const_iterator &operator>>(
    std::vector<char>::const_iterator &iter,
    boost::asio::const_buffer &value);

std::vector<char>::iterator &operator<<(
    std::vector<char>::iterator &iter,
    const boost::asio::const_buffer &value);

size_t serialize_size(const boost::asio::const_buffer &value);

#endif // __serialization_boost_buffer_hpp
