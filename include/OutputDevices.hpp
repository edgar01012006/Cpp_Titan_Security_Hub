#ifndef OUTPUTDEVICES_HPP
#define OUTPUTDEVICES_HPP

#include <string>

#include "Siren.hpp"
#include "PhoneNotification.hpp"
#include "LogFiles.hpp"

class OutputDevices {
    private:
        Siren m_siren;
        PhoneNotification m_phoneNotification;
        LogFiles m_logFiles;

    public:
        void triggerAlarm(std::string severity, std::string notifyWho);
};

#endif