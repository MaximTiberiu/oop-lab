#include <iostream>

class Baza {
public:
    Baza() {
        std::cout << "Constructor Baza\n";
    }

    virtual ~Baza() {
        std::cout << "Destructor Baza\n";
    }
};

class Derivata : public Baza {
private:
    int *arr;
public:
    Derivata() {
        arr = new int[10];
        std::cout << "Constructor Derivata\n";
    }

    ~Derivata() override {
        delete arr;
        std::cout << "Destructor Derivata\n";
    }
};

int main() {
    Baza *baza = new Baza();
    delete baza;

    std::cout << "---------\n";

    Derivata *derivata = new Derivata();
    delete derivata;

    std::cout << "---------\n";
    Baza *derivataPolimorfism = new Derivata();
    delete derivataPolimorfism;

    return 0;
}
