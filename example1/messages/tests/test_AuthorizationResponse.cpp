#include <vector>
#include <string>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

#include "messages/AuthorizationResponse.hpp"

using jetblack::messagebus::messages::AuthorizationResponse;
using jetblack::messagebus::messages::Message;

bool ShouldRoundTripSimple()
{
    auto generator = boost::uuids::random_generator();

    boost::uuids::uuid clientId(generator());
    std::string feed = "LSE";
    std::string topic = "VOD";
    bool isAuthorizationRequired = true;
    std::vector<boost::uuids::uuid> entitlements;
    entitlements.push_back(generator());
    entitlements.push_back(generator());

    AuthorizationResponse value(clientId, feed, topic, isAuthorizationRequired, entitlements);

    auto buf(value.to_bytes());
    std::vector<char>::const_iterator iter = buf->begin();
    auto roundTrip = std::static_pointer_cast<AuthorizationResponse>(Message::from_bytes(iter));
    return value == *roundTrip;
}

int main()
{
    bool ok = true;

    ok = ok && ShouldRoundTripSimple();

    return ok ? 0 : 1;
}