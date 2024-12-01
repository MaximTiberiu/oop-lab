//
// Created by Tiberiu on 11/13/2024.
//

#include <iostream>
#include "../headers/Masina.hpp"

Masina::Masina(int anFabricatie, const std::string &brand, const std::string &model) : anFabricatie(anFabricatie),
                                                                                       brand(brand), model(model) {}

int Masina::getAnFabricatie() const {
    return anFabricatie;
}

void Masina::setAnFabricatie(int anFabricatie) {
    Masina::anFabricatie = anFabricatie;
}

const std::string &Masina::getBrand() const {
    return brand;
}

void Masina::setBrand(const std::string &brand) {
    Masina::brand = brand;
}

const std::string &Masina::getModel() const {
    return model;
}

void Masina::setModel(const std::string &model) {
    Masina::model = model;
}

void Masina::printInfo() {
    std::cout << "Niste text.\n";
}
