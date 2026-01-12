#ifndef MOTIONDETECTOR_HPP
#define MOTIONDETECTOR_HPP

#include <string>
#include <iostream>

#include "Sensor.hpp"
#include "DoorSensor.hpp"

template<typename T>

class MotionDetector : public Sensor<T> {
    public:
        MotionDetector(const std::string& name, const std::string& location, std::unique_ptr<Data<T>> data, bool systemArmed, Mode mode);

        void pollSensor(OutputDevices outputDevices) override;

};

template<typename T>
MotionDetector<T>::MotionDetector(const std::string& name, const std::string& location, std::unique_ptr<Data<T>> data, bool systemArmed, Mode mode)
    : Sensor<T>(name, location, std::move(data), systemArmed, mode) {}

template<typename T>
void MotionDetector<T>::pollSensor(OutputDevices outputDevices) {
    std::cout << "Reading Motion Detector... ";
                
    if (this->m_data->getData() == true && this->m_currentMode == Mode::AWAY) {
        std::cout << "MOTION DETECTED!" << std::endl;
        outputDevices.triggerAlarm("Medium", "UserPhone");
    } else {
        std::cout << "No Motion." << std::endl;
    }
}

#endif