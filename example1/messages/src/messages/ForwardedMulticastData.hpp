#ifndef __messages_ForwardedMulticastData_hpp
#define __messages_ForwardedMulticastData_hpp 1

#include "messages/Message.hpp"
#include "messages/BinaryDataPacket.hpp"

#include <string>
#include <vector>
#include <memory>
#include <iostream>

#include <boost/asio/ip/address.hpp>

namespace jetblack::messagebus::messages
{
class ForwardedMulticastData : public Message
{
  public:
    ForwardedMulticastData()
        : Message(MessageType::ForwardedMulticastData)
    {
    }

    ForwardedMulticastData(const std::string &user, const boost::asio::ip::address &address, const std::string &feed, const std::string &topic, bool isImage, const std::vector<BinaryDataPacket> &data)
        : Message(MessageType::ForwardedMulticastData),
          _user(user), _feed(feed), _topic(topic), _isImage(isImage), _data(data)
    {
    }

    const std::string &user() const { return _user; }
    const boost::asio::ip::address &address() const { return _address; }
    const std::string &feed() const { return _feed; }
    const std::string &topic() const { return _topic; }
    bool isImage() const { return _isImage; }
    const std::vector<BinaryDataPacket> data() const { return _data; }

    static std::shared_ptr<ForwardedMulticastData> from_bytes(std::vector<char>::const_iterator &iter);

  protected:
    virtual size_t bodySize() const;
    virtual void writeBody(std::vector<char>::iterator &sink) const;

  private:
    std::string _user;
    boost::asio::ip::address _address;
    std::string _feed;
    std::string _topic;
    bool _isImage;
    std::vector<BinaryDataPacket> _data;
};
} // namespace jetblack::messagebus::messages

size_t serialize_size(const jetblack::messagebus::messages::ForwardedMulticastData &value);

std::ostream &operator<<(std::ostream &os, const jetblack::messagebus::messages::ForwardedMulticastData &value);

#endif // __messages_ForwardedMulticastData_hpp
