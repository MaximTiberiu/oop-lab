//
// Created by Tiberiu on 3/26/2024.
//

#include <iostream>
#include "../headers/Pisica.hpp"

Pisica::Pisica(const std::string &nume) : Animal(nume) {}

void Pisica::sound() {
    std::cout << "Miau miau\n";

}
