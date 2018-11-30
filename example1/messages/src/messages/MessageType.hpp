#ifndef __messages_MessageType_hpp
#define __messages_MessageType_hpp 1

namespace jetblack::messagebus::messages
{
    enum class MessageType
    {
        InteractorAdvertisement,
        MulticastData,
        UnicastData,
        ForwardedMulticastData,
        ForwardedUnicastData,
        ForwardedSubscriptionRequest,
        NotificationRequest,
        SubscriptionRequest,
        AuthorizationRequest,
        AuthorizationResponse
    };
}

#endif // __messages_MessageType_hpp
