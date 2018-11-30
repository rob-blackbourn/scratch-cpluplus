#include "messages/AuthorizationRequest.hpp"

#include "serialization/native.hpp"
#include "serialization/vector.hpp"
#include "serialization/string.hpp"
#include "serialization/boost/uuid/uuid.hpp"
#include "serialization/boost/ip/address.hpp"

#include <boost/uuid/uuid_io.hpp>

using jetblack::messagebus::messages::AuthorizationRequest;

size_t serialize_size(const AuthorizationRequest& value)
{
    return 
        serialize_size(value.clientId()) + 
        serialize_size(value.address()) + 
        serialize_size(value.user()) + 
        serialize_size(value.feed()) + 
        serialize_size(value.topic());
}
std::vector<unsigned char>::iterator& operator << (
    std::vector<unsigned char>::iterator& iter,
    const AuthorizationRequest& value)
{
    iter << value.clientId();
    iter << value.address();
    iter << value.user();
    iter << value.feed();
    iter << value.topic();
    return iter;    
}

std::vector<unsigned char>::const_iterator& operator >> (
    std::vector<unsigned char>::const_iterator& iter,
    AuthorizationRequest& value)
{
    boost::uuids::uuid clientId;
    iter >> clientId;

    boost::asio::ip::address address;
    iter >> address;
    
    std::string user;
    iter >> user;
    
    std::string feed;
    iter >> feed;

    std::string topic;
    iter >> topic;

    value = AuthorizationRequest(clientId, address, user, feed, topic);

    return iter;
}

std::ostream& operator << (std::ostream& os, const AuthorizationRequest& value)
{
    return os
        << "clientId=" << value.clientId()
        << ",adddress=" << value.address()
        << ",user=\"" << value.user() << "\""
        << ",feed=\"" << value.feed() << "\""
        << ",topic\"" << value.topic() << "\"";
}
