#include "messages/UnicastData.hpp"

#include "serialization/native.hpp"
#include "serialization/vector.hpp"
#include "serialization/string.hpp"
#include "serialization/boost/uuid/uuid.hpp"

#include <boost/uuid/uuid_io.hpp>

using jetblack::messagebus::messages::BinaryDataPacket;
using jetblack::messagebus::messages::Message;
using jetblack::messagebus::messages::UnicastData;

std::shared_ptr<UnicastData> from_bytes(std::vector<char>::const_iterator &iter)
{
    boost::uuids::uuid clientId;
    iter >> clientId;

    std::string feed;
    iter >> feed;

    std::string topic;
    iter >> topic;

    bool isImage;
    iter >> isImage;

    std::vector<BinaryDataPacket> data;
    iter >> data;

    return std::make_shared<UnicastData>(UnicastData(clientId, feed, topic, isImage, std::move(data)));
}

void UnicastData::writeBody(std::vector<char>::iterator &iter) const
{
    iter << _clientId;
    iter << _feed;
    iter << _topic;
    iter << _isImage;
    iter << _data;
}

size_t UnicastData::bodySize() const
{
    return serialize_size(_clientId) +
           serialize_size(_feed) +
           serialize_size(_topic) +
           serialize_size(_isImage) +
           serialize_size(_data);
}

std::ostream &operator<<(std::ostream &os, const UnicastData &value)
{
    return os
           << "clientId=\"" << value.clientId() << "\""
           << ", feed=\"" << value.feed() << "\""
           << ",topic=\"" << value.topic() << "\""
           << ",isImage=" << value.isImage()
           << ",data.size()=" << value.data().size();
}