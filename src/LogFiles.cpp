#include "LogFiles.hpp"

void LogFiles::logToFile(std::string message) {
    std::ofstream logFile;

    logFile.open("system_log.txt", std::ios_base::app); 
    if (logFile.is_open()) {
        // Get current time
        time_t result = time(nullptr);
        logFile << ctime(&result) << " - " << message << "\n";
        logFile.close();
    } else {
        std::cerr << "Failed to write to log file." << std::endl;
    }
}

void LogFiles::logging(std::string severity, std::string notifyWho) {
    logToFile("ALARM: " + severity + " sent to " + notifyWho);
}