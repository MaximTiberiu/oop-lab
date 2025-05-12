// #include <iostream>
//
// class Masina {
// private:
//     std::string brand;
//     std::string model;
//     int an_fabricatie;
//     float cc;
//
//     const int numar_roti = 4;
//
// public:
//     Masina() = default;
//
//     Masina(const std::string &brand, const std::string &model, int an_fabricatie, float cc)
//         : brand(brand),
//           model(model),
//           an_fabricatie(an_fabricatie),
//           cc(cc) {
//     }
//
//     [[nodiscard]] std::string brand1() const {
//         return brand;
//     }
//
//     [[nodiscard]] std::string model1() const {
//         return model;
//     }
//
//     [[nodiscard]] int an_fabricatie1() const {
//         return an_fabricatie;
//     }
//
//     [[nodiscard]] float cc1() const {
//         return cc;
//     }
//
//     [[nodiscard]] int numar_roti1() const {
//         return numar_roti;
//     }
// };
//
// int main() {
//     Masina audi("audi", "a4", 2025, 1.9);
//     std::cout << audi.an_fabricatie1() << std::endl;
//     return 0;
// }
























// Sa se implementeze un catalog pentru o clasa de elevi.
// Catalogul va putea stoca notele pentru diverse materii ale elevilor (exista doar 3 materii - romana, mate si info)
// Elevii sunt identificati dupa nume, prenume si numar matricol.
// Sa se adauge functionalitati pentru:
//      - adaugare note pentru un elev dat, la o materie data
//      - generarea mediilor pentru un elev dat (afisarea acestora la consola)
//      - generarea mediei finale pentru un elev dat (afisarea acesteia la consola)












#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

enum Materie {
    ROMANA,
    MATE,
    INFO,
    BIOLOGIE
};

const std::map<Materie, std::string> materiiNume = {
    {ROMANA, "romana"},
    {MATE, "mate"},
    {INFO, "info"},
    {BIOLOGIE, "biologie"}
};

class Elev {
private:
    std::string nume;
    std::string prenume;
    int numar_matricol;
    std::map<Materie, std::vector<int>> note;

public:

    Elev() = default;

    Elev(const std::string &nume, const std::string &prenume, int numar_matricol) {
        this->nume = nume;
        this->prenume = prenume;
        this->numar_matricol = numar_matricol;
    }

    [[nodiscard]] std::string get_nume() const {
        return nume;
    }

    [[nodiscard]] const std::string& get_prenume() const {
        return prenume;
    }

    [[nodiscard]] int get_numar_matricol() const {
        return numar_matricol;
    }

    [[nodiscard]] std::map<Materie, std::vector<int>> get_note() const {
        return note;
    }

    [[maybe_unused]] void dummy_function() {

    }

    void adaugaNota(const Materie &materie, int nota) {
        note[materie].push_back(nota);
    }

    double calculeazaMedie(const Materie &materie) {
        if (note[materie].empty()) return 0;
        double suma = 0;
        for (int nota : note[materie]) { // echivalent cu for (int i = 0 ; i < note[materie].size() ; i++)
            suma += nota;
        }
        return suma / note[materie].size();
    }

    double calculeazaMedieFinala() {
        double sumaMedii = 0;
        int numarMaterii = 0;
        for (const auto& [materie, _] : materiiNume) {
            if (!note[materie].empty()) {
                sumaMedii += calculeazaMedie(materie);
                numarMaterii++;
            }
        }
        return (numarMaterii > 0) ? sumaMedii / numarMaterii : 0;
    }
};

class Catalog {
private:
    std::map<int, Elev> elevi; // Număr matricol -> Elev

public:
    void adaugaElev(const std::string &nume, const std::string &prenume, int numar_matricol) {
        elevi[numar_matricol] = Elev(nume, prenume, numar_matricol);
    }

    void adaugaNota(int numar_matricol, const Materie &materie, int nota) {
        if (elevi.find(numar_matricol) != elevi.end()) {
            elevi[numar_matricol].adaugaNota(materie, nota);
        } else {
            std::cout << "Elevul nu exista!" << std::endl;
        }
    }

    void genereazaMedii(int numar_matricol) {
        if (elevi.find(numar_matricol) == elevi.end()) {
            std::cout << "Elevul nu exista!" << std::endl;
            return;
        }

        std::cout << "Medii pentru " << elevi[numar_matricol].get_nume() << " " << elevi[numar_matricol].get_prenume() << ":" << std::endl;
        for (const auto& [materie, numeMaterie] : materiiNume) {
            double medie = elevi[numar_matricol].calculeazaMedie(materie);
            std::cout << numeMaterie << ": " << (medie > 0 ? std::to_string(medie) : "Nicio nota") << std::endl;
        }
    }

    void genereazaMedieFinala(int numar_matricol) {
        if (elevi.find(numar_matricol) == elevi.end()) {
            std::cout << "Elevul nu exista!" << std::endl;
            return;
        }
        double medieFinala = elevi[numar_matricol].calculeazaMedieFinala();
        std::cout << "Medie finala pentru " << elevi[numar_matricol].get_nume() << " " << elevi[numar_matricol].get_prenume() << ": " << (medieFinala > 0 ? std::to_string(medieFinala) : "Nu exista note pentru calculul mediei finale!") << std::endl;
    }
};

int main() {
    Catalog catalog;
    catalog.adaugaElev("Popescu", "Ion", 1);
    catalog.adaugaElev("Ionescu", "Maria", 2);

    catalog.adaugaNota(1, MATE, 8);
    catalog.adaugaNota(1, MATE, 9);
    catalog.adaugaNota(1, ROMANA, 7);
    catalog.adaugaNota(2, INFO, 10);

    catalog.genereazaMedii(1);
    catalog.genereazaMedieFinala(1);

    return 0;
}

