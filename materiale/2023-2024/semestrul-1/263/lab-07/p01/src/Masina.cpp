//
// Created by Tiberiu on 11/13/2023.
//

#include <iostream>
#include "../headers/Masina.hpp"

Masina::Masina(const std::string &marca) : marca(marca) {}

const std::string &Masina::getMarca() const {
    return marca;
}

void Masina::setMarca(const std::string &marca) {
    Masina::marca = marca;
}

void Masina::print() {
    std::cout << "Masina mea este: " << this->marca << ".\n";
}


