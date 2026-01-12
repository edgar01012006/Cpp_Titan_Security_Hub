#include "PhoneNotification.hpp"

void PhoneNotification::sendNotification(std::string notifyWho) {
    if (notifyWho == "Police") {
        std::cout << "Dialing 911..." << std::endl;
    } else if (notifyWho == "FireDept") {
        std::cout << "Dialing Fire Department..." << std::endl;
    } else if (notifyWho == "UserPhone") {
        std::cout << "Sending Push Notification to User..." << std::endl;
    }
}