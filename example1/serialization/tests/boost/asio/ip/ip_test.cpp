// #include <string>
#include <vector>
#include <boost/asio/ip/address.hpp>

#include "serialization/native.hpp"
#include "serialization/string.hpp"
#include "serialization/boost/asio/ip/address.hpp"

bool test_ip_address_v4(const char* addr)
{
    auto source(boost::asio::ip::make_address(addr));
    std::vector<char> v(sizeof(size_t) + std::tuple_size<boost::asio::ip::address_v4::bytes_type>());
    std::vector<char>::iterator viter(v.begin());

    viter << source;

    boost::asio::ip::address dest;
    std::vector<char>::const_iterator vconstiter(v.begin());

    vconstiter >> dest;

    return source == dest;
}

int main()
{
    bool ok = true;

    ok = ok && test_ip_address_v4("127.0.0.1");

    return ok ? 0 : 1;
}