#ifndef __messages_BinaryDataPacket_hpp
#define __messages_BinaryDataPacket_hpp 1

#include <vector>
#include <iostream>
#include <boost/uuid/uuid.hpp>

namespace jetblack::messagebus::messages
{
    class BinaryDataPacket
    {
    public:

        BinaryDataPacket()
        {
        }

        BinaryDataPacket(const boost::uuids::uuid& header_, const std::vector<char>& body_)
            : _header(header_), _body(body_)
        {
        }

        BinaryDataPacket(const boost::uuids::uuid& header_, std::vector<char>&& body_)
            : _header(header_), _body(body_)
        {
        }

        BinaryDataPacket(const BinaryDataPacket& other)
            : _header(other._header), _body(other._body)
        {
        }

        BinaryDataPacket(BinaryDataPacket&& other)
            : _header(other._header), _body(std::move(other._body))
        {
        }

        BinaryDataPacket& operator =(const BinaryDataPacket& other)
        {
            if (this == &other) return *this;

            _header = other._header;
            _body = std::move(other._body);
            return *this;
        }

        BinaryDataPacket& operator =(BinaryDataPacket&& other)
        {
            if (this == &other) return *this;

            _header = other._header;
            _body = std::move(other._body);
            return *this;
        }

        const boost::uuids::uuid& header() const { return _header; }
        const std::vector<char>& body() const { return _body; }

    private:
        boost::uuids::uuid _header;
        std::vector<char> _body;
    };
}

size_t serialize_size(const jetblack::messagebus::messages::BinaryDataPacket& value);

std::vector<char>::iterator& operator << (
    std::vector<char>::iterator& iter,
    const jetblack::messagebus::messages::BinaryDataPacket& value);

std::vector<char>::const_iterator& operator >> (
    std::vector<char>::const_iterator& iter,
    jetblack::messagebus::messages::BinaryDataPacket& value);

std::ostream& operator << (
    std::ostream& os,
    const jetblack::messagebus::messages::BinaryDataPacket& value);

bool operator == (
    const jetblack::messagebus::messages::BinaryDataPacket& lhs,
    const jetblack::messagebus::messages::BinaryDataPacket& rhs);

#endif // __messages_BinaryDataPacket_hpp
