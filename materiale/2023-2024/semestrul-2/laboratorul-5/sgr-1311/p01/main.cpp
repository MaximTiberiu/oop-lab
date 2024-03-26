#include <iostream>

class Automobil {
protected:
    std::string marca;

public:
    Automobil() = default;
    explicit Automobil(const std::string &marca) : marca(marca) {}
    virtual ~Automobil() = default;

    const std::string &getMarca() const {
        return marca;
    }

    void setMarca(const std::string &marca) {
        Automobil::marca = marca;
    }

    virtual void print() {
        std::cout << "Acesta este un automobil marca " << this->getMarca() << "\n";
    }
};

class Masina : public Automobil {
private:
    int nrLocuri;

public:
    Masina() = default;
    Masina(const std::string &marca, int nrLocuri) : Automobil(marca), nrLocuri(nrLocuri) {}
    ~Masina() override = default;

    int getNrLocuri() const {
        return nrLocuri;
    }

    void setNrLocuri(int nrLocuri) {
        Masina::nrLocuri = nrLocuri;
    }

    void print() override {
        std::cout << "Aceasta este o masina marca " << this->marca << ", nrLocuri = "
            << this->nrLocuri << "\n";
    }
};

class Camion : public Automobil {
private:
    int tonaj;

public:
    Camion() = default;
    Camion(const std::string &marca, int tonaj) : Automobil(marca), tonaj(tonaj) {}
    ~Camion() override = default;

    int getTonaj() const {
        return tonaj;
    }

    void setTonaj(int tonaj) {
        Camion::tonaj = tonaj;
    }

    void print() override {
        std::cout << "Acesta este un camion marca " << this->marca << ", tonaj = "
                  << this->tonaj << "\n";
    }
};

int main() {
    Automobil *aut = new Automobil("Volvo");
    aut->print();
    Automobil *masina = new Masina("Audi", 5);
    masina->print();
    Automobil *camion = new Camion("MAN", 20);
    camion->print();
    return 0;
}
