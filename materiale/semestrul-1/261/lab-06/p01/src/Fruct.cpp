//
// Created by Tiberiu on 11/10/2023.
//

#include <iostream>
#include "../headers/Fruct.hpp"

Fruct::Fruct() {}

Fruct::Fruct(const std::string &numeFruct, double greutate) : numeFruct(numeFruct), greutate(greutate) {}

const std::string &Fruct::getNumeFruct() const {
    return numeFruct;
}

void Fruct::setNumeFruct(const std::string &numeFruct) {
    Fruct::numeFruct = numeFruct;
}

double Fruct::getGreutate() const {
    return greutate;
}

void Fruct::setGreutate(double greutate) {
    Fruct::greutate = greutate;
}

void Fruct::print() {
    std::cout << this->numeFruct << " " << this->greutate << "\n";
}

