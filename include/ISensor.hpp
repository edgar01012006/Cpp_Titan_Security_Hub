#ifndef ISENSOR_HPP
#define ISENSOR_HPP

#include "OutputDevices.hpp"

enum Mode {
    DAY, 
    NIGHT,
    AWAY
};

class ISensor {
    public:
        virtual ~ISensor() = default;

        virtual void pollSensor(OutputDevices outputDevices) = 0;

        virtual void setMode(Mode mode) = 0;

};

#endif