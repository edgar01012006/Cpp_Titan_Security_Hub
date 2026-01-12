#include "Siren.hpp"

void Siren::makeSound(std::string severity) {
    if (severity == "High" || severity == "Critical") {
        std::cout << ">>> PLAYING LOUD SIREN SOUND <<<" << std::endl;
    } else {
        std::cout << ">>> Beeping Keypad <<<" << std::endl;
    }
}