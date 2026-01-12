# 🛡️ Titan Security Hub

## 1. Project Overview

The **Titan Security Hub** is a robust, modular C++ security management system designed to monitor various household sensors.  
It leverages **Modern C++17** and follows **SOLID principles** to ensure the system is extensible and maintainable.

The project demonstrates advanced concepts such as **Interface Segregation**, **Template Inheritance**, and **Dynamic Type Casting** to handle diverse data types (Binary vs. Analog) within a single unified hub.

---

## 2. Features

### Modular Sensor System
- **Door Sensor**: Monitors entry points using binary data (Open / Closed).
- **Motion Detector**: Monitors movement based on system modes (Day / Night / Away).
- **Heat Sensor**: Tracks temperature fluctuations using analog data and triggers fire alarms.

### Advanced Logic
- **Interface-Based Design**: The hub uses an `ISensor` interface, allowing it to manage different sensor types without knowing their concrete implementations.
- **Type-Safe Simulation**: Uses `dynamic_cast` to safely inject test data into sensors at runtime.
- **Automated Logging**: All security events are timestamped and logged to an external file for auditing.

---

## 3. Project Structure

```text
titan-security-hub/
├── include/                     # Header files (.hpp)
│   ├── ISensor.hpp              # Abstract sensor interface
│   ├── Sensor.hpp               # Base template class for all sensors
│   ├── Data.hpp                 # Template for sensor data wrapping
│   ├── Analog.hpp
│   ├── Binary.hpp
│   ├── DoorSensor.hpp
│   ├── MotionDetector.hpp
│   ├── HeatSensor.hpp
│   ├── TitanSecurityHub.hpp     # Central system controller
│   ├── OutputDevices.hpp        # Alarm / notification coordinator
│   ├── Siren.hpp
│   ├── LogFiles.hpp
│   └── PhoneNotification.hpp
├── src/                         # Implementation files (.cpp)
│   ├── OutputDevices.cpp
│   ├── Siren.cpp
│   ├── LogFiles.cpp
│   ├── PhoneNotification.cpp
│   └── main.cpp
├── Makefile                     # Cross-platform build script (Win/Linux)
└── README.md                    # Project documentation
```

### Key Components
- **ISensor**: Defines the contract for all sensors (polling, mode handling).
- **Sensor<T>**: Template-based abstraction handling data storage and simulation logic.
- **TitanSecurityHub**: Manages sensor lifecycle and coordinates system behavior.
- **OutputDevices**: Facade managing sirens, logs, and phone notifications.

---

## 4. Build & Run Instructions

### Build the Project
The `Makefile` automatically detects your operating system and applies the appropriate compiler flags.

```bash
make
```

### Run the Program
```bash
./TitanHub
```

### Clean Compiled Files
Removes object files and the executable for a fresh build.

```bash
make clean
```
