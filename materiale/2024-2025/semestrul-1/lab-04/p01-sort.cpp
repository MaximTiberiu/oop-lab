#include <iostream>
#include <vector>
#include <algorithm>

class Aliment {
private:
    std::string numeAliment;
    unsigned int gramaj;
    unsigned int pret;

public:
    Aliment() = default;
    ~Aliment() = default;

    Aliment(const std::string &numeAliment, unsigned int gramaj, unsigned int pret) : numeAliment(numeAliment),
                                                                                      gramaj(gramaj), pret(pret) {}

    const std::string &getNumeAliment() const {
        return numeAliment;
    }

    unsigned int getGramaj() const {
        return gramaj;
    }

    unsigned int getPret() const {
        return pret;
    }

    friend std::ostream& operator<<(std::ostream &out, const Aliment& aliment) {
        out << "Nume aliment: " << aliment.numeAliment << "\n";
        out << "Gramaj: " << aliment.gramaj << "\n";
        out << "Pret: " << aliment.pret << "\n";

        return out;
    }

    Aliment& operator=(const Aliment& aliment) {
        this->numeAliment = aliment.numeAliment;
        this->gramaj = aliment.gramaj;
        this->pret = aliment.pret;

        return *this;
    }
};

/*
 * Sortare:
 *  - crescator dupa pret
 *  - descrescator dupa gramaj (daca preturile sunt egale)
 */
bool comparator(const Aliment& a1, const Aliment& a2) {
    if (a1.getPret() == a2.getPret()) {
        return a1.getGramaj() > a2.getGramaj();
    }
    return a1.getPret() < a2.getPret();
}

int main() {
//    Aliment a1("Aliment", 100, 1);
//    std::cout << a1;
//
//    Aliment a2, a3;
//    a3 = a2 = a1;
//    std::cout << a2 << a3;

    std::vector<Aliment> alimente;
    alimente.emplace_back("Faina", 1000, 5);
    alimente.emplace_back("Lapte", 500, 4);
    alimente.emplace_back("Paine", 300, 2);
    alimente.emplace_back("Cartofi", 5000, 11);
    alimente.emplace_back("Fasole", 650, 11);

    for (auto & aliment : alimente) {
        std::cout << "--------------\n";
        std::cout << aliment;
    }

//    std::sort(alimente.begin(), alimente.end(), comparator);
    std::sort(alimente.begin(), alimente.end(), [](const Aliment& a1, const Aliment& a2) {
        if (a1.getPret() == a2.getPret()) {
            return a1.getGramaj() > a2.getGramaj();
        }
        return a1.getPret() < a2.getPret();
    });
    std::cout << "DUPA SORTARE-------------\n";

    for (auto it = alimente.begin(); it != alimente.end() ; it++) {
        std::cout << "--------------\n";
        std::cout << *it;
    }

    return 0;
}
