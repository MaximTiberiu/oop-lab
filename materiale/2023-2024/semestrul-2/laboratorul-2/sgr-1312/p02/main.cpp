#include <iostream>
#include <cstring>

// Sa se implementeze o structura de date care sa stocheze date despre fructe (nume, culoare, greutate).

class Fruct {
private:
    std::string nume;
    std::string culoare;
    float greutate;

public:
    Fruct(std::string val_nume, std::string val_culoare, float val_greutate) {
        this->nume = val_nume;
        this->greutate = val_greutate;
        this->culoare = val_culoare;
    }

    void setNume(std::string nume) {
        this->nume = nume;
    }

    void setCuloare(std::string culoare) {
        this->culoare = culoare;
    }

    void setGreutate(float greutate) {
        this->greutate = greutate;
    }

    std::string getNume() {
        return this->nume;
    }

    std::string getCuloare() {
        return this->culoare;
    }

    float getGreutate() {
        return this->greutate;
    }
};

int main() {
    Fruct mar("Mere", "Rosu", 10.5);
    Fruct banana("Banana", "Galben", 8.7);

    std::cout << mar.getCuloare() << "\n";
    std::cout << banana.getGreutate() << "\n";
}
