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

        BinaryDataPacket(const boost::uuids::uuid& header, const std::vector<unsigned char>&& body)
            : _header(header), _body(std::move(body))
        {
        }

        BinaryDataPacket(BinaryDataPacket&& other)
            : _header(other._header), _body(std::move(other._body))
        {
        }

        BinaryDataPacket& operator =(BinaryDataPacket&& other)
        {
            _header = other._header;
            _body = std::move(other._body);
            return *this;
        }

        size_t size() const
        {
            return _header.size() + sizeof(size_t) + _body.size();
        }

        const boost::uuids::uuid& header() const { return _header; }
        const std::vector<unsigned char>& body() const { return _body; }

    private:
        boost::uuids::uuid _header;
        std::vector<unsigned char> _body;
    };
}

size_t serialize_size(const jetblack::messagebus::messages::BinaryDataPacket& value);

std::vector<unsigned char>::iterator& operator << (
    std::vector<unsigned char>::iterator& iter,
    const jetblack::messagebus::messages::BinaryDataPacket& value);

std::vector<unsigned char>::const_iterator& operator >> (
    std::vector<unsigned char>::const_iterator& iter,
    jetblack::messagebus::messages::BinaryDataPacket& value);

std::ostream& operator << (
    std::ostream& os,
    const jetblack::messagebus::messages::BinaryDataPacket& value);

#endif // __messages_BinaryDataPacket_hpp
