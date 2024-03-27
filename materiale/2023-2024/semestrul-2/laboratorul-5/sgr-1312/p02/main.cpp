#include <iostream>
#include "headers/Meteo.hpp"
#include "headers/Furtuna.hpp"

int main() {
    Meteo *fenomen = new Furtuna("furtuna", 20);
    fenomen->infoFenomen();
    return 0;
}
