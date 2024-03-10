#include <iostream>

// clasa abstracta (interfata)
class Obj {
public:
    Obj() = default;
    virtual void print() = 0; // functie virtuala pura
};

class Persoana : public Obj {
private:
    std::string nume;
    std::string prenume;

public:
    Persoana() = default;
    Persoana(const std::string &nume, const std::string &prenume) : nume(nume), prenume(prenume) {}

    void print() override {
        std::cout << "Persoana cu prenumele " << this->prenume << " si numele " << this->nume << ".\n";
    }
};

class Aliment : public Obj {
protected:
    std::string numeAliment;

public:
    Aliment() = default;
    explicit Aliment(const std::string &numeAliment) : numeAliment(numeAliment) {}
    void print() override = 0;
};

class Lactat : public Aliment {
private:
    std::string tipLapte;

public:
    Lactat() = default;
    Lactat(const std::string &numeAliment, const std::string &tipLapte) : Aliment(numeAliment), tipLapte(tipLapte) {}

    void print() override {
        std::cout << "Lactatul " << this->numeAliment << " din lapte de " << this->tipLapte << ".\n";
    }
};

int main() {
    Obj *obj = new Persoana("Ion", "Ion");
    obj->print();
    return 0;
}
