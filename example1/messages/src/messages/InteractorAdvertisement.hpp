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
        InteractorAdvertisement() noexcept
            : Message(MessageType::InteractorAdvertisement)
        {
        }

        InteractorAdvertisement(
            const std::string& user,
            const boost::asio::ip::address& address,
            bool isJoining) noexcept
            :   Message(MessageType::InteractorAdvertisement),
                _user(user),
                _address(address),
                _isJoining(isJoining)
        {
        }

        const std::string& user() const noexcept { return _user; }
        const boost::asio::ip::address& address() const noexcept { return _address; }
        bool isJoining() const noexcept { return _isJoining; }
        
        static std::shared_ptr<InteractorAdvertisement> from_bytes(std::vector<char>::const_iterator& iter);

        friend bool operator == (const InteractorAdvertisement& lhs, const InteractorAdvertisement& rhs)
        {
            return lhs._user == rhs._user &&
                lhs._address == rhs._address &&
                lhs._isJoining == rhs._isJoining;
        }

        friend bool operator != (const InteractorAdvertisement& lhs, const InteractorAdvertisement& rhs)
        {
            return !(lhs == rhs);
        }
        
    protected:
        virtual size_t bodySize() const noexcept;
        virtual void writeBody(std::vector<char>::iterator& sink) const;

    private:
        std::string _user;
        boost::asio::ip::address _address;
        bool _isJoining;
    };
}

std::ostream& operator << (std::ostream& os, const jetblack::messagebus::messages::InteractorAdvertisement& value);

#endif // __messages_InteractorAdvertisement_hpp
