#ifndef __messages_InteractorAdvertisement_hpp
#define __messages_InteractorAdvertisement_hpp 1

#include "messages/Message.hpp"

#include <string>
#include <vector>
#include <memory>
#include <iostream>

#include <boost/asio/ip/address.hpp>

namespace jetblack::messagebus::messages
{
    class InteractorAdvertisement : public Message
    {
    public:
        InteractorAdvertisement()
            : Message(MessageType::InteractorAdvertisement)
        {
        }

        InteractorAdvertisement(const std::string& user, const boost::asio::ip::address& address, bool isJoining)
            : Message(MessageType::InteractorAdvertisement),
              _user(user), _address(address), _isJoining(isJoining)
        {
        }

        const std::string& user() const { return _user; }
        const boost::asio::ip::address& address() const { return _address; }
        bool isJoining() const { return _isJoining; }
        
        static std::shared_ptr<InteractorAdvertisement> from_bytes(std::vector<char>::const_iterator& iter);

    protected:
        virtual size_t bodySize() const;
        virtual void writeBody(std::vector<char>::iterator& sink) const;

    private:
        std::string _user;
        boost::asio::ip::address _address;
        bool _isJoining;
    };
}

std::ostream& operator << (std::ostream& os, const jetblack::messagebus::messages::InteractorAdvertisement& value);

#endif // __messages_InteractorAdvertisement_hpp
