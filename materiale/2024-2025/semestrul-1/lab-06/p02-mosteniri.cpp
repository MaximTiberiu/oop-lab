#include <iostream>

class Obj {
public:
    virtual void printInfo() = 0;
};

class Bicicleta : public Obj {
protected:
    std::string brand;
    std::string tipSchimbator;
    int pret;

public:
    Bicicleta(const std::string &brand, const std::string &tipSchimbator, int pret) : brand(brand),
                                                                                      tipSchimbator(tipSchimbator),
                                                                                      pret(pret) {
        std::cout << "Constructor BAZA\n";
    }

    virtual ~Bicicleta() {
        std::cout << "Destructor BAZA\n";
    }

    const std::string &getBrand() const {
        return brand;
    }

    void setBrand(const std::string &brand) {
        Bicicleta::brand = brand;
    }

    const std::string &getTipSchimbator() const {
        return tipSchimbator;
    }

    void setTipSchimbator(const std::string &tipSchimbator) {
        Bicicleta::tipSchimbator = tipSchimbator;
    }

    int getPret() const {
        return pret;
    }

    void setPret(int pret) {
        Bicicleta::pret = pret;
    }

    void printInfo() override {
        std::cout << "Bicileta " << brand << " are schimbator tip " << tipSchimbator << " si costa " << pret << " lei.\n";
    }
};

class BicicletaElectrica : public Bicicleta {
private:
    int capacitateBaterie;

public:
    BicicletaElectrica(const std::string &brand, const std::string &tipSchimbator, int pret, int capacitateBaterie)
            : Bicicleta(brand, tipSchimbator, pret), capacitateBaterie(capacitateBaterie) {
        std::cout << "Constructor DERIVATA\n";
    }

    ~BicicletaElectrica() {
        std::cout << "Destructor DERIVATA\n";
    }

    int getCapacitateBaterie() const {
        return capacitateBaterie;
    }

    void setCapacitateBaterie(int capacitateBaterie) {
        BicicletaElectrica::capacitateBaterie = capacitateBaterie;
    }

    void printInfo() override {
        std::cout << "Bicicleta electrica " << brand << " are schimbator tip " << tipSchimbator << " si costa " << pret << " lei.\n";
        std::cout << "Capacitatea bateriei este de: "<< capacitateBaterie << " W\n";
    }
};

class BicicletaTandem : public Bicicleta {
private:
    int lungime;

public:
    BicicletaTandem(const std::string &brand, const std::string &tipSchimbator, int pret, int lungime) : Bicicleta(
            brand, tipSchimbator, pret), lungime(lungime) {}

    int getLungime() const {
        return lungime;
    }

    void setLungime(int lungime) {
        BicicletaTandem::lungime = lungime;
    }

    void printInfo() override {
        std::cout << "Bicicleta tandem " << brand << " are schimbator tip " << tipSchimbator << " si costa " << pret << " lei.\n";
        std::cout << "Lungimea este de: " << lungime <<" m\n";
    }
};

int main() {
    Bicicleta* bicicleta = new Bicicleta("A", "Shimano", 1700);
    bicicleta->printInfo();
    delete bicicleta;

    std::cout << "----------------------------------------------------\n";

    Bicicleta* bicicletaElectrica = new BicicletaElectrica("B", "Shimano2", 7500, 100);
    bicicletaElectrica->printInfo();
    delete bicicletaElectrica;

    std::cout << "----------------------------------------------------\n";

    Bicicleta* bicicletaTandem = new BicicletaTandem("C", "Shimano3", 3500, 2);
    bicicletaTandem->printInfo();
    delete bicicletaTandem;
    return 0;
}
