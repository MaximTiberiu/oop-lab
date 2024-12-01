#include <iostream>

void addNumber(int x) {
    static int sum = 0;
    sum += x;
    std::cout << sum << std::endl;
}

class Obj {
public:
    static int x;
    std::string name;

    Obj() = default;
    ~Obj() = default;

    static void display(const Obj& obj) {
        std::cout << x << std::endl;
        std::cout << obj.name << std::endl;
    }
};

int Obj::x;

int main() {
    // static in cod standard, fara clase
    // for (int i = 1; i <= 10; i++) {
    //     addNumber(i);
    // }

    // varibila static intr-o clasa
    Obj obj1;
    Obj::x = 1; // putem scrie si asa, intr-un mod mai corect
    std::cout << obj1.x << std::endl; // functioneaza, dar nu este chiar corect

    Obj obj2;
    obj2.x = 2;
    std::cout << obj1.x << std::endl;
    std::cout << obj2.x << std::endl;

    // functii statice
    Obj::display(obj1);
    return 0;
}
