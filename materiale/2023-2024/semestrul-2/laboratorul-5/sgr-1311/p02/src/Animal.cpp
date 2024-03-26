#include <iostream>
#include "../headers/Animal.hpp"

Animal::Animal(const std::string &nume) : nume(nume) {}

void Animal::test() {
    std::cout << "Acesta este un test.\n";
}
