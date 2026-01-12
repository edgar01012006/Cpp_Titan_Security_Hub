#ifndef TITANSECURITYHUB_HPP
#define TITANSECURITYHUB_HPP

#include <vector>
#include <string>
#include <memory>
#include <iostream>

#include "ISensor.hpp"
#include "Sensor.hpp"
#include "DoorSensor.hpp"
#include "MotionDetector.hpp"
#include "HeatSensor.hpp"
#include "OutputDevices.hpp"
#include "Data.hpp"
#include "Analog.hpp"
#include "Binary.hpp"

class TitanSecurityHub {
    private:
        std::vector<std::unique_ptr<ISensor>> m_sensors;
        // every sensor will have its own systemArmed and currentMode
        // while its not ideal it will do the job for now

    public:
        TitanSecurityHub();

        void setMode(Mode mode);

        void pollSensors(OutputDevices outputDevices);

        template<typename T>
        void simulateAnalogSensorInput(size_t index, T value);

        void generateReport();

};

TitanSecurityHub::TitanSecurityHub() {
    m_sensors.emplace_back(std::make_unique<DoorSensor<bool>>("Front Door", "Entry", std::make_unique<Binary>(false), false, Mode::DAY));
    m_sensors.emplace_back(std::make_unique<MotionDetector<bool>>("Living Room Motion", "Living Room", std::make_unique<Binary>(false), false, Mode::DAY));
    m_sensors.emplace_back(std::make_unique<HeatSensor<int>>("Kitchen Heat", "Kitchen", std::make_unique<Analog>(25), false, Mode::DAY));
}

void TitanSecurityHub::setMode(Mode mode) {
    for (size_t i = 0; i < m_sensors.size(); ++i) {
        m_sensors[i]->setMode(mode);
    }
}

void TitanSecurityHub::pollSensors(OutputDevices outputDevices) {
    std::cout << "\n--- Polling Sensors ---" << std::endl;
    for (size_t i = 0; i < m_sensors.size(); ++i) {
        m_sensors[i]->pollSensor(outputDevices);
    }
}

template<typename T>
void TitanSecurityHub::simulateAnalogSensorInput(size_t index, T value) {
    if (index < m_sensors.size()) {
        auto* sensor = dynamic_cast<Sensor<T>*>(m_sensors[index].get()); // used AI here didn't know the syntax(and some other template related stuff)
        if (sensor) {
            sensor->simulateSensorInput(value);
        }
    }
}

void TitanSecurityHub::generateReport() {
    std::cout << "\nGenerating System Report..." << std::endl;
    std::cout << "Sensors Online: " << m_sensors.size() << std::endl;
}

#endif