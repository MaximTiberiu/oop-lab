//
// Created by Tiberiu on 3/27/2024.
//

#include <iostream>
#include "../headers/Furtuna.hpp"

Furtuna::Furtuna(const std::string &fenomen, int cantitate) : Meteo(fenomen), cantitate(cantitate) {}

void Furtuna::infoFenomen() {
    std::cout << "Fenomenul " << this->fenomen << " a avut loc. Cantitate: " << this->cantitate << "\n";
}
