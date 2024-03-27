#include <iostream>

class Meteo {
protected:
    std::string fenomenMeteo;

public:
    Meteo() = default;
    virtual  ~Meteo() = default;
    explicit Meteo(const std::string &fenomenMeteo) : fenomenMeteo(fenomenMeteo) {}

    virtual void infoFenomen() {
        std::cout << "Fenomenul " << this->fenomenMeteo << " a avut loc.\n";
    }
};

class Furtuna : public Meteo {
private:
    int cantitate;

public:
    Furtuna() = default;
    ~Furtuna() = default;
    Furtuna(const std::string &fenomenMeteo, int cantitate) : Meteo(fenomenMeteo), cantitate(cantitate) {}

    void infoFenomen() override {
        std::cout << "Fenomenul " << this->fenomenMeteo << " a avut loc. Precipitatii: "<< this->cantitate << " l/m2.\n";
    }
};

class Grindina : public Meteo {
private:
    int dimensiuneGrindina;

public:
    Grindina() = default;
    ~Grindina() = default;
    Grindina(const std::string &fenomenMeteo, int dimensiuneGrindina) : Meteo(fenomenMeteo),
                                                                        dimensiuneGrindina(dimensiuneGrindina) {}

    void infoFenomen() override {
        std::cout << "Fenomenul " << this->fenomenMeteo << " a avut loc. Dimenisune grindina: "<< this->dimensiuneGrindina << ".\n";
    }
};

int main() {
    Meteo *fenomen = new Meteo("fenomen");
    fenomen->infoFenomen();

    Meteo *furtuna = new Furtuna("furtuna", 20);
    furtuna->infoFenomen();

    Meteo *grindina = new Grindina("grindina", 5);
    grindina->infoFenomen();
    return 0;
}
