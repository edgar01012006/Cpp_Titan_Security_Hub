#include "TitanSecurityHub.hpp"
#include "OutputDevices.hpp"

int main() {
    TitanSecurityHub hub;
    OutputDevices outputs;

    // 1. Arm the system
    hub.setMode(Mode::AWAY);

    // 2. Simulate a Fire (Heat Sensor is at index 2)
    hub.simulateAnalogSensorInput<int>(2, 65); 

    // 3. Simulate an Intruder (Door Sensor is at index 0)
    hub.simulateAnalogSensorInput<bool>(0, true);

    // 4. Check the results
    hub.pollSensors(outputs);
    hub.generateReport();

    return 0;
}