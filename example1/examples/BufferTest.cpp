#include <iostream>
#include <vector>
#include <string>
#include <boost/asio/buffer.hpp>

#include "serialization/native.hpp"
#include "serialization/string.hpp"
#include "serialization/boost/asio/buffer.hpp"

void ShouldRoundTrip()
{
    std::string s0{"This is not a test"};
    boost::asio::mutable_buffer source(const_cast<char *>(s0.data()), s0.size());

    std::vector<char> v(serialize_size(source));
    std::vector<char>::iterator viter(v.begin());

    viter << source;

    boost::asio::mutable_buffer destination;
    std::vector<char>::const_iterator vconstiter(v.begin());

    vconstiter >> destination;
    std::string s1(static_cast<const char *>(destination.data()), destination.size());
    std::cout << "source={" << s0 << "},destination={" << s1 << "}" << std::endl;
}

void ShouldRoundTripConst()
{
    boost::asio::const_buffer source(boost::asio::buffer("This is not a test"));

    std::vector<char> v(serialize_size(source));
    std::vector<char>::iterator viter(v.begin());

    viter << source;

    boost::asio::const_buffer destination;
    std::vector<char>::const_iterator vconstiter(v.begin());

    vconstiter >> destination;
    std::cout << "source={" << static_cast<const unsigned char *>(source.data()) << "},destination={" << static_cast<const unsigned char *>(destination.data()) << "}" << std::endl;
}

int main()
{
    ShouldRoundTrip();
    ShouldRoundTripConst();
}