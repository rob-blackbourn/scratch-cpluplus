#ifndef __messages_SubscriptionRequest_hpp
#define __messages_SubscriptionRequest_hpp 1

#include "messages/Message.hpp"

#include <string>
#include <vector>
#include <memory>
#include <iostream>

namespace jetblack::messagebus::messages
{
class SubscriptionRequest : public Message
{
  public:
    SubscriptionRequest()
        : Message(MessageType::SubscriptionRequest)
    {
    }

    SubscriptionRequest(const std::string &feed, const std::string &topic, bool isAdd)
        : Message(MessageType::SubscriptionRequest),
          _feed(feed), _topic(topic), _isAdd(isAdd)
    {
    }

    const std::string &feed() const { return _feed; }
    const std::string &topic() const { return _topic; }
    bool isAdd() const { return _isAdd; }

    static std::shared_ptr<SubscriptionRequest> from_bytes(std::vector<char>::const_iterator &iter);

  protected:
    virtual size_t bodySize() const;
    virtual void writeBody(std::vector<char>::iterator &sink) const;

  private:
    std::string _feed;
    std::string _topic;
    bool _isAdd;
};
} // namespace jetblack::messagebus::messages

size_t serialize_size(const jetblack::messagebus::messages::SubscriptionRequest &value);

std::ostream &operator<<(std::ostream &os, const jetblack::messagebus::messages::SubscriptionRequest &value);

#endif // __messages_SubscriptionRequest_hpp
