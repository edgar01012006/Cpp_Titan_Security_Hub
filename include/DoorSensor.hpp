#ifndef DOORSENSOR_HPP
#define DOORSENSOR_HPP

#include <string>
#include <iostream>

#include "Sensor.hpp"

template<typename T>

class DoorSensor : public Sensor<T> {
    public:
        DoorSensor(const std::string& name, const std::string& location, std::unique_ptr<Data<T>> data, bool systemArmed, Mode mode);

        void pollSensor(OutputDevices outputDevices) override;
};

template<typename T>
DoorSensor<T>::DoorSensor(const std::string& name, const std::string& location, std::unique_ptr<Data<T>> data, bool systemArmed, Mode mode)
    : Sensor<T>(name, location, std::move(data), systemArmed, mode) {}

template<typename T>
void DoorSensor<T>::pollSensor(OutputDevices outputDevices) {
    std::cout << "Reading Door Sensor... ";
    if (this->m_data->getData() == true && this->m_systemArmed) {
            std::cout << "OPEN! Triggering Alarm!" << std::endl;
            outputDevices.triggerAlarm("High", "Police");
    } else {
        std::cout << "Secure." << std::endl;
    }
}

#endif