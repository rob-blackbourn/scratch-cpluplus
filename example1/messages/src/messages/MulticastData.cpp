#include "messages/MulticastData.hpp"

#include "serialization/native.hpp"
#include "serialization/vector.hpp"
#include "serialization/string.hpp"

using jetblack::messagebus::messages::BinaryDataPacket;
using jetblack::messagebus::messages::Message;
using jetblack::messagebus::messages::MulticastData;

std::shared_ptr<MulticastData> from_bytes(std::vector<char>::const_iterator &iter)
{
    std::string feed;
    iter >> feed;

    std::string topic;
    iter >> topic;

    bool isImage;
    iter >> isImage;

    std::vector<BinaryDataPacket> data;
    iter >> data;

    return std::make_shared<MulticastData>(MulticastData(feed, topic, isImage, std::move(data)));
}

void MulticastData::writeBody(std::vector<char>::iterator &iter) const
{
    iter << _feed;
    iter << _topic;
    iter << _isImage;
    iter << _data;
}

size_t MulticastData::bodySize() const
{
    return serialize_size(_feed) +
           serialize_size(_topic) +
           serialize_size(_isImage) +
           serialize_size(_data);
}

std::ostream &operator<<(std::ostream &os, const MulticastData &value)
{
    return os
           << "feed=\"" << value.feed() << "\""
           << ",topic=\"" << value.topic() << "\""
           << ",isImage=" << value.isImage()
           << ",data.size()=" << value.data().size();
}