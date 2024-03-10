#include <iostream>

class Baza {
public:
    Baza() {
        std::cout << "Apel Constructor Baza\n";
    }

    virtual ~Baza() {
        std::cout << "Apel Destructor Baza\n";
    }
};

class Derivata : public Baza {
private:
    int *arr;
public:
    Derivata() {
        arr = new int[10];
        std::cout << "\tApel Constructor Derivata\n";
    }

    ~Derivata() override {
        delete arr;
        std::cout << "\tApel Destructor Derivata\n";
    }
};

int main() {
    Baza *baza = new Baza();
    delete baza;

    std::cout << "----------\n";

    Baza *derivata = new Derivata();
    delete derivata;

    return 0;
}
