#include <iostream>
#include <vector>
#include <algorithm>

class Masina {
private:
    unsigned int anFabricatie;
    std::string marca;
    std::string numarInmatriculare;

public:
    Masina() = default;
    ~Masina() = default;

    Masina(unsigned int localAnFabricatie, const std::string& localMarca, const std::string& localNumarInmatriculare) {
        this->anFabricatie = localAnFabricatie;
        this->marca = localMarca;
        this->numarInmatriculare = localNumarInmatriculare;
    }

    friend std::ostream& operator<<(std::ostream& out, const Masina& masina) {
        out << "An Fabricatie: " << masina.anFabricatie << " ";
        out << "Marca: " << masina.marca << " ";
        out << "Numar Inmatriculare: " << masina.numarInmatriculare  << "\n";

        return out;
    }

    Masina& operator=(const Masina& masina) {
        this->anFabricatie = masina.anFabricatie;
        this->marca = masina.marca;
        this->numarInmatriculare = masina.numarInmatriculare;
        return *this;
    }

    unsigned int getAnFabricatie() const {
        return anFabricatie;
    }

    const std::string &getMarca() const {
        return marca;
    }

    const std::string &getNumarInmatriculare() const {
        return numarInmatriculare;
    }

};

class Depozit {
private:
    std::vector<Masina> masini;

public:
    Depozit() = default;
    ~Depozit() = default;

    Depozit(const std::vector<Masina>& localMasini) {
        this->masini = localMasini;
    }

    friend std::ostream &operator<<(std::ostream &os, const Depozit &depozit) {
        for (auto & masina : depozit.masini) {
            os << masina;
        }
//        os << "masini: " << depozit.masini;
        return os;
    }
};

bool comparator(const Masina& m1, const Masina& m2) {
    if (m1.getAnFabricatie() == m2.getAnFabricatie()) {
        if (m1.getMarca() == m2.getMarca()) {
            return m1.getNumarInmatriculare() < m2.getNumarInmatriculare();
        }

        return m1.getMarca() < m2.getMarca();
    }

    return m1.getAnFabricatie() > m2.getAnFabricatie();
}

int main() {
    std::vector<Masina> masini;
    masini.emplace_back(2020, "VW", "IF-105-BBC");
    masini.emplace_back(2016, "VW", "B-205-ABC");
    masini.emplace_back(2016, "VW", "B-105-BBC");
    masini.emplace_back(2016, "Audi", "IF-205-ABC");
    masini.emplace_back(2018, "Volvo", "AG-20-ABC");
    masini.emplace_back(2020, "Audi", "IS-50-ABC");


    for(auto it = masini.begin() ; it != masini.end() ; it++) {
        std::cout << *it;
    }

//    std::sort(masini.begin(), masini.end(), comparator);
    std::sort(masini.begin(), masini.end(), [](const Masina& m1, const Masina& m2) {
        if (m1.getAnFabricatie() == m2.getAnFabricatie()) {
            if (m1.getMarca() == m2.getMarca()) {
                return m1.getNumarInmatriculare() < m2.getNumarInmatriculare();
            }

            return m1.getMarca() < m2.getMarca();
        }

        return m1.getAnFabricatie() > m2.getAnFabricatie();
    });

    std::cout << "-------------";

    for (auto & masina : masini) {
        std::cout << masina;
    }



    Masina m1(2000, "Ford", "IS-10-ABC");
    std::cout << m1;

    Masina m2, m3;
    m3 = m2 = m1;
    std::cout << m2;
    std::cout << m3;


    return 0;
}

