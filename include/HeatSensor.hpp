#ifndef HEATSENSOR_HPP
#define HEATSENSOR_HPP

#include <string>
#include <iostream>

#include "Sensor.hpp"

template<typename T>

class HeatSensor : public Sensor<T> {
    public:
        HeatSensor(const std::string& name, const std::string& location, std::unique_ptr<Data<T>> data, bool systemArmed, Mode mode);

        void pollSensor(OutputDevices outputDevices) override;
};

template<typename T>
HeatSensor<T>::HeatSensor(const std::string& name, const std::string& location, std::unique_ptr<Data<T>> data, bool systemArmed, Mode mode)
    : Sensor<T>(name, location, std::move(data), systemArmed, mode) {}

template<typename T>
void HeatSensor<T>::pollSensor(OutputDevices outputDevices) {
    std::cout << "Reading Heat Sensor... Temp: " << this->m_data->getData() << "C. ";
    if (this->m_data->getData() > 50) {
        std::cout << "DANGER! FIRE!" << std::endl;
        outputDevices.triggerAlarm("Critical", "FireDept");
    } else {
        std::cout << "Normal." << std::endl;
    }
}

#endif