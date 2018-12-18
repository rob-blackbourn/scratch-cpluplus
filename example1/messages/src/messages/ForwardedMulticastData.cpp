#include "messages/ForwardedMulticastData.hpp"

#include "serialization/native.hpp"
#include "serialization/vector.hpp"
#include "serialization/string.hpp"
#include "serialization/boost/asio/ip/address.hpp"

using jetblack::messagebus::messages::ForwardedMulticastData;
using jetblack::messagebus::messages::BinaryDataPacket;

size_t ForwardedMulticastData::bodySize() const noexcept
{
    return 
        serialize_size(_user) + 
        serialize_size(_address) + 
        serialize_size(_feed) + 
        serialize_size(_topic) + 
        serialize_size(_isImage) +
        serialize_size(_data);
}

std::shared_ptr<ForwardedMulticastData> ForwardedMulticastData::from_bytes(std::vector<char>::const_iterator& iter)
{
    std::string user;
    iter >> user;

    boost::asio::ip::address address;
    iter >> address;

    std::string feed;
    iter >> feed;

    std::string topic;
    iter >> topic;

    bool isImage;
    iter >> isImage;

    std::vector<BinaryDataPacket> data;
    iter >> data;

    return std::make_shared<ForwardedMulticastData>(ForwardedMulticastData(user, address, feed, topic, isImage, std::move(data)));
}

void ForwardedMulticastData::writeBody(std::vector<char>::iterator& iter) const
{
    iter << _user;
    iter << _address;
    iter << _feed;
    iter << _topic;
    iter << _isImage;
    iter << _data;
}

std::ostream& operator << (std::ostream& os, const ForwardedMulticastData& value)
{
    return os
        << "user=\"" << value.user() << "\""
        << ",address=\"" << value.address().to_string() << "\""
        << ",feed=\"" << value.feed() << "\""
        << ",topic=\"" << value.topic() << "\""
        << ",isImage=" << value.isImage() 
        << ",data.size()=" << value.data().size();
}

bool operator==(
    const jetblack::messagebus::messages::ForwardedMulticastData &lhs,
    const jetblack::messagebus::messages::ForwardedMulticastData &rhs) noexcept
{
    return lhs.user() == rhs.user() &&
        lhs.address() == rhs.address() &&
        lhs.feed() == rhs.feed() &&
        lhs.topic() == rhs.topic() &&
        lhs.isImage() == rhs.isImage() &&
        lhs.data() == rhs.data();
}
