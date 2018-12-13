#include "messages/InteractorAdvertisement.hpp"

#include "serialization/native.hpp"
#include "serialization/vector.hpp"
#include "serialization/string.hpp"
#include "serialization/boost/ip/address.hpp"

using jetblack::messagebus::messages::InteractorAdvertisement;

// TODO: Is this redundent?
size_t serialize_size(const InteractorAdvertisement& value)
{
    return 
        serialize_size(value.user()) + 
        serialize_size(value.address()) + 
        serialize_size(value.isJoining());
}

size_t InteractorAdvertisement::bodySize() const
{
    return 
        serialize_size(_user) + 
        serialize_size(_address) + 
        serialize_size(_isJoining);
}

std::shared_ptr<InteractorAdvertisement> from_bytes(std::vector<unsigned char>::const_iterator& iter)
{
    std::string user;
    iter >> user;

    boost::asio::ip::address address;
    iter >> address;

    bool isJoining;
    iter >> isJoining;

    return std::make_shared<InteractorAdvertisement>(InteractorAdvertisement(user, address, isJoining));
}

void InteractorAdvertisement::writeBody(std::vector<unsigned char>::iterator& iter) const
{
    iter << _user;
    iter << _address;
    iter << _isJoining;
}

std::ostream& operator << (std::ostream& os, const InteractorAdvertisement& value)
{
    return os
        << "user=\"" << value.user() << "\""
        << ",address=\"" << value.address() << "\""
        << ",isJoining=" << value.isJoining() ;
}
