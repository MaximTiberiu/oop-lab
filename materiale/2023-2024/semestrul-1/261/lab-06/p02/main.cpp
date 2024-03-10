#include <iostream>
#include <vector>

class Automobil {
protected:
    std::string marca;

public:
    explicit Automobil(const std::string &marca) : marca(marca) {}

    virtual void print() {
        std::cout << "Marca: " << this->marca << "\n";
    }
};

class Masina : public Automobil {
private:
    std::string model;

public:
    Masina(const std::string &marca, const std::string &model) : Automobil(marca), model(model) {}

    void print() override {
        Automobil::print();
        std::cout << "Model: " << this->model << "\n";
    }
};

class TIR : public Automobil {
private:
    unsigned int tonaj;

public:
    TIR(const std::string &marca, unsigned int tonaj) : Automobil(marca), tonaj(tonaj) {}

    void print() override {
        Automobil::print();
        std::cout << "Tonaj: " << this->tonaj << "\n";
    }
};

int main() {
    Automobil *automobil = new Automobil("VW");
    automobil->print();

    std::cout << "------\n";
    Automobil *masina = new Masina("VW", "Golf 4");
    masina->print();

    std::cout << "------\n";
    Automobil *tir = new TIR("Scania", 45);
    tir->print();
    return 0;
}
