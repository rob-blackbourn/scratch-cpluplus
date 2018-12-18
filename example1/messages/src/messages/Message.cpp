#include "messages/Message.hpp"
#include "messages/AuthorizationRequest.hpp"
#include "messages/AuthorizationResponse.hpp"
#include "messages/ForwardedMulticastData.hpp"
#include "messages/ForwardedSubscriptionRequest.hpp"
#include "messages/InteractorAdvertisement.hpp"
#include "messages/MulticastData.hpp"
#include "messages/NotificationRequest.hpp"
#include "messages/SubscriptionRequest.hpp"
#include "messages/UnicastData.hpp"

#include "serialization/native.hpp"

using jetblack::messagebus::messages::MessageType;
using jetblack::messagebus::messages::Message;
using jetblack::messagebus::messages::MulticastData;
using jetblack::messagebus::messages::AuthorizationRequest;
using jetblack::messagebus::messages::AuthorizationResponse;
using jetblack::messagebus::messages::ForwardedMulticastData;
using jetblack::messagebus::messages::ForwardedSubscriptionRequest;
using jetblack::messagebus::messages::InteractorAdvertisement;
using jetblack::messagebus::messages::NotificationRequest;
using jetblack::messagebus::messages::SubscriptionRequest;
using jetblack::messagebus::messages::UnicastData;

MessageType Message::readHeader(std::vector<char>::const_iterator& iter)
{
    unsigned char byte;
    iter >> byte;
    return static_cast<MessageType>(byte);
}

std::vector<char>::iterator& Message::writeHeader(std::vector<char>::iterator& iter) const
{
    unsigned char byte = static_cast<unsigned char>(type());
    iter << byte;
    return iter;
}

std::shared_ptr<Message> Message::from_bytes(std::vector<char>::const_iterator& iter)
{
    MessageType type = readHeader(iter);

    switch (type)
    {
        case MessageType::AuthorizationRequest:
            return AuthorizationRequest::from_bytes(iter);

        case MessageType::AuthorizationResponse:
            return AuthorizationResponse::from_bytes(iter);

        case MessageType::ForwardedMulticastData:
            return ForwardedMulticastData::from_bytes(iter);

        case MessageType::ForwardedSubscriptionRequest:
            return ForwardedSubscriptionRequest::from_bytes(iter);

        case MessageType::InteractorAdvertisement:
            return InteractorAdvertisement::from_bytes(iter);

        case MessageType::MulticastData:
            return MulticastData::from_bytes(iter);

        case MessageType::NotificationRequest:
            return NotificationRequest::from_bytes(iter);

        case MessageType::SubscriptionRequest:
            return SubscriptionRequest::from_bytes(iter);

        case MessageType::UnicastData:
            return UnicastData::from_bytes(iter);

        default:
            throw "oh dear";

    }
}

std::shared_ptr<std::vector<char>> Message::to_bytes() const
{
    size_t len = headerSize() + bodySize();
    std::shared_ptr<std::vector<char>> sink = std::make_shared<std::vector<char>>(std::vector<char>(len));

    auto iter = sink->begin();

    writeHeader(iter);
    writeBody(iter);

    return sink;
}