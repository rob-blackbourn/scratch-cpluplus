#ifndef __messages_MulticastData_hpp
#define __messages_MulticastData_hpp 1

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "messages/Message.hpp"
#include "messages/BinaryDataPacket.hpp"

namespace jetblack::messagebus::messages
{
  class MulticastData : public Message
  {
    public:
      MulticastData()
          : Message(MessageType::MulticastData)
      {
      }

      MulticastData(const std::string &feed, const std::string &topic, bool isImage, std::vector<BinaryDataPacket> &&data)
          : Message(MessageType::MulticastData), _feed(feed), _topic(topic), _isImage(isImage), _data(std::move(data))
      {
      }

      const std::string &feed() const { return _feed; }
      const std::string &topic() const { return _topic; }
      const bool isImage() const { return _isImage; }
      const std::vector<BinaryDataPacket> &data() const { return _data; }

      static std::shared_ptr<MulticastData> from_bytes(std::vector<char>::const_iterator &iter);

    protected:
      virtual size_t bodySize() const;
      virtual void writeBody(std::vector<char>::iterator &sink) const;

    private:
      std::string _feed;
      std::string _topic;
      bool _isImage;
      std::vector<BinaryDataPacket> _data;
  };
}

std::ostream &operator<<(std::ostream &os, const jetblack::messagebus::messages::MulticastData &value);

#endif // __messages_MulticastData_hpp
