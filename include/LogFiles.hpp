#ifndef LOGFILES_HPP
#define LOGFILES_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <ctime>

class LogFiles {
    public:
        virtual void logToFile(std::string message);
        
        void logging(std::string severity, std::string notifyWho);

        virtual ~LogFiles() = default;
};

#endif