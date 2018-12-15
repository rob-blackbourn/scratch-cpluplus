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

std::vector<char>::iterator& Message::writeHeader(std::vector<char>::iterator& sink) const
{
    unsigned char byte = static_cast<unsigned char>(type());
    sink << byte;
    return sink;
}

std::shared_ptr<Message> Message::from_bytes(std::vector<char>::const_iterator& source)
{
    MessageType type = readHeader(source);

        switch (type)
    {
        case MessageType::AuthorizationRequest:
            return AuthorizationRequest::from_bytes(source);

        case MessageType::AuthorizationResponse:
            return AuthorizationResponse::from_bytes(source);

        case MessageType::ForwardedMulticastData:
            return ForwardedMulticastData::from_bytes(source);

        case MessageType::ForwardedSubscriptionRequest:
            return ForwardedSubscriptionRequest::from_bytes(source);

        case MessageType::InteractorAdvertisement:
            return InteractorAdvertisement::from_bytes(source);

        case MessageType::MulticastData:
            return MulticastData::from_bytes(source);

        case MessageType::NotificationRequest:
            return NotificationRequest::from_bytes(source);

        case MessageType::SubscriptionRequest:
            return SubscriptionRequest::from_bytes(source);

        case MessageType::UnicastData:
            return UnicastData::from_bytes(source);

        default:
            throw "oh dear";

    }
}

std::shared_ptr<std::vector<char>> Message::to_bytes() const
{
    size_t size = headerSize() + bodySize();
    std::shared_ptr<std::vector<char>> sink = std::make_shared<std::vector<char>>(size);

    auto iter = sink->begin();

    writeHeader(iter);
    writeBody(iter);

    return sink;
}