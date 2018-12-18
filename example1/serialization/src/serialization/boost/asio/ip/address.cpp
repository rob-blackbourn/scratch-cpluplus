#include "address.hpp"

#include "serialization/string.hpp"

#include <string>

size_t serialize_size(const boost::asio::ip::address &value) noexcept
{
    return serialize_size(value.to_string());
}

std::vector<char>::const_iterator &operator>>(
    std::vector<char>::const_iterator &iter,
    boost::asio::ip::address &value)
{
    std::string s;
    iter >> s;
    value = boost::asio::ip::make_address(s);
    return iter;
}

std::vector<char>::iterator &operator<<(
    std::vector<char>::iterator &iter,
    const boost::asio::ip::address &value)
{
    iter << value.to_string();
    return iter;
}
