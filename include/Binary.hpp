#ifndef BINARY_HPP
#define BINARY_HPP

#include "Data.hpp"

class Binary : public Data<bool> {
    public:
        Binary(bool data) : Data<bool>(std::move(data)) {}
};

#endif