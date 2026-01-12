#include "OutputDevices.hpp"

void OutputDevices::triggerAlarm(std::string severity, std::string notifyWho) {
    m_siren.makeSound(severity);
    m_phoneNotification.sendNotification(notifyWho);
    m_logFiles.logging(severity, notifyWho);
}