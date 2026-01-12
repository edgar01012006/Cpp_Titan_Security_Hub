#ifndef SIREN_HPP
#define SIREN_HPP

#include <string>
#include <iostream>

class Siren {
    public:
        virtual void makeSound(std::string severity);
        
        virtual ~Siren() = default;
};

#endif