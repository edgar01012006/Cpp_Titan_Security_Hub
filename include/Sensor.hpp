#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <string>
#include <memory>

#include "ISensor.hpp"
#include "Data.hpp"
#include "OutputDevices.hpp"

template<typename T>

class Sensor : public ISensor {
    protected:
        std::string m_name;
        std::string m_location;
        std::unique_ptr<Data<T>> m_data;
        bool m_systemArmed;
        Mode m_currentMode;

    public:
        Sensor(const std::string& name, const std::string& location, std::unique_ptr<Data<T>> data, bool systemArmed, Mode mode);
        virtual ~Sensor() = default;

        virtual void pollSensor(OutputDevices outputDevices) = 0;

        void simulateSensorInput(T data) { m_data->setData(std::move(data)); }

        void setMode(Mode mode);

    private:
        std::string modeToString(Mode mode);
        
};

template<typename T>
Sensor<T>::Sensor(const std::string& name, const std::string& location, std::unique_ptr<Data<T>> data, bool systemArmed, Mode mode)
    : m_name { name }, m_location { location }, m_data { std::move(data) }, m_systemArmed { systemArmed }, m_currentMode { mode } {}

template<typename T>
void Sensor<T>::setMode(Mode mode) {
    m_currentMode = mode;
    std::cout << "[System] Mode set to: " << modeToString(mode) << std::endl;
    if (mode == Mode::AWAY) {
        m_systemArmed = true;
    } else {
        std::cout << "[Error] Unknown mode." << std::endl;
    }
}

template<typename T>
std::string Sensor<T>::modeToString(Mode mode) {
    switch(mode) {
        case Mode::AWAY: return "Away";
        case Mode::DAY: return "Day";
        case Mode::NIGHT: return "Night";
        default: break;
    }
    return "None";
}

#endif