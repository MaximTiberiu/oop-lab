#include <iostream>

const double PI {3.1415926535897932384626433832795};

class Cilindru {
private:
    double raza{1};
    double inaltime{1};

public:
    Cilindru() {
        std::cout << "Am facut un cilindru - default\n";
    }
    // Cilindru() = default;

    Cilindru(double raza, double inaltime) {
        std::cout << "Am facut un cilindru - parametrizabil\n";
        this->raza = raza;
        this->inaltime = inaltime;
    }

    Cilindru(double raza, double inaltime, std::string nume) {
        std::cout << "Am facut un cilindru - parametrizabil -> " << nume << "\n";
        this->raza = raza;
        this->inaltime = inaltime;
    }

    ~Cilindru() {
        std::cout << "Am sters un cilindru cu raza " << this->raza << " si inaltimea " << this->inaltime << "\n";
    }
    // ~Cilindru() = default;

    double getRaza() {
        return this->raza;
    }

    double getInaltime() {
        return this->inaltime;
    }

    void setRaza(double raza) {
        this->raza = raza;
    }

    void setInaltime(double inaltime) {
        this->inaltime = inaltime;
    }

    double arie_baza() {
        return PI * this->raza * this->raza;
    }

    double volum() {
        return arie_baza() * this->inaltime;
    }
};

int main() {
    {
        Cilindru cilindru1(2, 3, "cilindru1");
        std::cout << "Raza bazei este: " << cilindru1.getRaza() << "\n";
        std::cout << "Arie baza: " << cilindru1.arie_baza() << "\n";
        std::cout << "Volum: " << cilindru1.volum() << "\n";
    }

    std::cout << "--------------------\n";

    Cilindru cilindru2;
    std::cout << "Arie baza: " << cilindru2.arie_baza() << "\n";
    std::cout << "Volum: " << cilindru2.volum() << "\n";
    return 0;
}
