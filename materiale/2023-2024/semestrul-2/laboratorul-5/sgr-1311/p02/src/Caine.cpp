#include <iostream>
#include "../headers/Caine.hpp"

void Caine::sound() {
    std::cout << "Ham ham\n";
}

Caine::Caine(const std::string &nume) : Animal(nume) {}
