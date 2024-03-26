#include <iostream>
#include "headers/Animal.hpp"
#include "headers/Caine.hpp"
#include "headers/Pisica.hpp"

int main() {
    Animal *caine = new Caine("caine");
    caine->sound();
    Animal *pisica = new Pisica("pisica");
    pisica->sound();
    pisica->test();
    return 0;
}
