#include "messages/MulticastData.hpp"

#include "serialization/native.hpp"
#include "serialization/vector.hpp"
#include "serialization/string.hpp"

using jetblack::messagebus::messages::BinaryDataPacket;
using jetblack::messagebus::messages::MulticastData;

size_t serialize_size(const MulticastData& value)
{
    return 
        serialize_size(value.feed()) + 
        serialize_size(value.topic()) + 
        serialize_size(value.isImage()) +
        serialize_size(value.data());
}

std::vector<unsigned char>::iterator& operator << (
    std::vector<unsigned char>::iterator& iter,
    const MulticastData& value)
{
    iter << value.feed();
    iter << value.topic();
    iter << value.isImage();
    iter << value.data().size();
    for (auto item = value.data().begin(); item != value.data().end(); ++item)
    {
        iter << *item;
    }

    return iter;    
}

std::vector<unsigned char>::const_iterator& operator >> (
    std::vector<unsigned char>::const_iterator& iter,
    MulticastData& value)
{
    std::string feed;
    iter >> feed;

    std::string topic;
    iter >> topic;

    bool isImage;
    iter >> isImage;

    size_t len;
    iter >> len;

    std::vector<BinaryDataPacket> data(len);
    for (size_t i = 0; i < len; ++i)
    {
        BinaryDataPacket item;
        iter >> item;
        data.push_back(std::move(item));
    }

    value = MulticastData(feed, topic, isImage, std::move(data));

    return iter;
}
