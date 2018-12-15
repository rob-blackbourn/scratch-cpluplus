#include <vector>
#include <boost/asio/ip/address.hpp>

#include "serialization/boost/asio/ip/address.hpp"

#include "../../../test_value.hpp"

bool test_ip_address_v4(const char* value)
{
    return test_value(boost::asio::ip::make_address(value));
}

int main()
{
    bool ok = true;

    ok = ok && test_ip_address_v4("0.0.0.0");
    ok = ok && test_ip_address_v4("127.0.0.1");
    ok = ok && test_ip_address_v4("255.255.255.255");
    ok = ok && test_ip_address_v4("192.168.0.1");
    ok = ok && test_ip_address_v4("10.0.0.1");

    return ok ? 0 : 1;
}