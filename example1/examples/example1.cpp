#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <boost/asio/ip/address.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include "serialization/native.hpp"
#include "serialization/string.hpp"
#include "serialization/boost/ip/address.hpp"
#include "serialization/boost/uuid/uuid.hpp"

#include "messages/BinaryDataPacket.hpp"
#include "messages/MulticastData.hpp"

using jetblack::messagebus::messages::BinaryDataPacket;
using jetblack::messagebus::messages::MulticastData;

void test_int()
{
    int i = 123456789;
    std::vector<unsigned char> v(4);
    std::vector<unsigned char>::iterator viter(v.begin());

    viter << i;

    int j = 0;
    std::vector<unsigned char>::const_iterator vconstiter(v.begin());

    vconstiter >> j;
    std::cout << "i=" << i << ", j=" << j << std::endl;
}

void test_string()
{
    std::string s1 = "123456789";
    std::vector<unsigned char> v(sizeof(size_t) + s1.size());
    std::vector<unsigned char>::iterator viter(v.begin());

    viter << s1;

    std::string s2;
    std::vector<unsigned char>::const_iterator vconstiter(v.begin());

    vconstiter >> s2;
    std::cout << "s1=" << s1 << ", s2=" << s2 << std::endl;
}

void test_ip_address_v4()
{
    auto addr1(boost::asio::ip::make_address("127.0.0.1"));
    std::vector<unsigned char> v(sizeof(size_t) + std::tuple_size<boost::asio::ip::address_v4::bytes_type>());
    std::vector<unsigned char>::iterator viter(v.begin());

    viter << addr1;

    boost::asio::ip::address addr2;
    std::vector<unsigned char>::const_iterator vconstiter(v.begin());

    vconstiter >> addr2;
    std::cout << "addr1=" << addr1 << ", addr2=" << addr2 << std::endl;
}

void test_uuid()
{
    auto generator = boost::uuids::random_generator();
    boost::uuids::uuid source(generator());

    std::vector<unsigned char> v(serialize_size(source));
    std::vector<unsigned char>::iterator viter(v.begin());

    viter << source;

    boost::uuids::uuid destination;
    std::vector<unsigned char>::const_iterator vconstiter(v.begin());

    vconstiter >> destination;
    std::cout << "source=" << source << ", destination=" << destination << std::endl;
}

void test_BinaryDataPacket()
{
    auto generator = boost::uuids::random_generator();
    boost::uuids::uuid header(generator());
    std::vector<unsigned char> body { 'a', 'b', 'c'};

    jetblack::messagebus::messages::BinaryDataPacket source(header, std::move(body));

    std::vector<unsigned char> v(serialize_size(source));
    std::vector<unsigned char>::iterator viter(v.begin());

    viter << source;

    jetblack::messagebus::messages::BinaryDataPacket destination;
    std::vector<unsigned char>::const_iterator vconstiter(v.begin());

    vconstiter >> destination;
    std::cout << "source={" << source << "},destination={" << destination << "}" << std::endl;
}

// void test_message()
// {
//     jetblack::messagebus::messages::Message msg1(MessageType::MulticastData);

//     std::vector<unsigned char> v(sizeof(size_t) + boost::uuids::uuid::static_size());
//     std::vector<unsigned char>::iterator viter(v.begin());

//     viter << tag1;

//     boost::uuids::uuid tag2;
//     std::vector<unsigned char>::const_iterator vconstiter(v.begin());

//     vconstiter >> tag2;
//     std::cout << "tag1=" << tag1 << ", tag2=" << tag2 << std::endl;
// }

int main()
{
    test_int();
    test_string();
    test_ip_address_v4();
    test_uuid();
    test_BinaryDataPacket();

    return 0;
}