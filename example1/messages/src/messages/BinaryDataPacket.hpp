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

        BinaryDataPacket() noexcept
        {
        }

        BinaryDataPacket(
            const boost::uuids::uuid& header_,
            std::vector<char>&& body_) noexcept
            :   _header(header_),
                _body(std::move(body_))
        {
        }

        BinaryDataPacket(BinaryDataPacket&& other) noexcept
            : _header(other._header), _body(std::move(other._body))
        {
        }

        BinaryDataPacket& operator =(BinaryDataPacket&& other) noexcept
        {
            if (this == &other) return *this;

            _header = other._header;
            _body = std::move(other._body);
            return *this;
        }

        const boost::uuids::uuid& header() const noexcept { return _header; }
        const std::vector<char>& body() const noexcept { return _body; }

    private:
        boost::uuids::uuid _header;
        std::vector<char> _body;
    };
}

size_t serialize_size(const jetblack::messagebus::messages::BinaryDataPacket& value) noexcept;

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
    const jetblack::messagebus::messages::BinaryDataPacket& rhs) noexcept;

bool operator == (
    const std::vector<jetblack::messagebus::messages::BinaryDataPacket>& lhs,
    const std::vector<jetblack::messagebus::messages::BinaryDataPacket>& rhs) noexcept;

#endif // __messages_BinaryDataPacket_hpp
