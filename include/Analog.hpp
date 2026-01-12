#ifndef ANALOG_HPP
#define ANALOG_HPP

#include "Data.hpp"

class Analog : public Data<int> {
    public:
        Analog(int data) : Data<int>(std::move(data)) {}
};

#endif