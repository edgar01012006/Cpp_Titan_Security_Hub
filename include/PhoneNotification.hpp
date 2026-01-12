#ifndef PHONENOTIFICATION_HPP
#define PHONENOTIFICATION_HPP

#include <string>
#include <iostream>

class PhoneNotification {
    public:
        virtual void sendNotification(std::string notifyWho);
        
        virtual ~PhoneNotification() = default;
};

#endif