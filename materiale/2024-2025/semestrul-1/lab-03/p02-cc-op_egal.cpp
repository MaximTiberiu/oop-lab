#include <iostream>
#include <vector>

class Materie {
private:
    std::string numeMaterie;
    unsigned int nrCredite;

public:
    Materie() = default;
    ~Materie() {
        std::cout << "Destructorul a fost apelat! - " << numeMaterie << "\n";
    };

    Materie(const std::string &numeMaterie, unsigned int nrCredite) : numeMaterie(numeMaterie), nrCredite(nrCredite) {
        std::cout << "Constructorul parametrizabil a fost apelat! - " << numeMaterie << "\n";
    }

    Materie(const Materie& materie) {
        this->numeMaterie = materie.numeMaterie;
        this->nrCredite = materie.nrCredite;

        std::cout << "Constructorul de copiere a fost apelat! - " << numeMaterie << "\n";
    }

    const std::string &getNumeMaterie() const {
        return numeMaterie;
    }

    void setNumeMaterie(const std::string &numeMaterie) {
        Materie::numeMaterie = numeMaterie;
    }

    unsigned int getNrCredite() const {
        return nrCredite;
    }

    void setNrCredite(unsigned int nrCredite) {
        Materie::nrCredite = nrCredite;
    }
};

int main() {
    unsigned int nrMaterii;
    std::vector<Materie> materii;

//    materii.reserve(3);

    std::cout << "Numar materii: ";
    std::cin >> nrMaterii;

    for (int i = 0; i < nrMaterii; i++) {
        unsigned int nrCredite;
        std::string numeMaterie;

        std::cin >> numeMaterie >> nrCredite;
        Materie temp_materie(numeMaterie, nrCredite);
        materii.push_back(temp_materie);
//        materii.emplace_back(numeMaterie, nrCredite);


    }

    for (int i = 0; i < nrMaterii; i++) {
        std::cout << materii[i].getNumeMaterie() << " " << materii[i].getNrCredite() << "\n";
    }
    return 0;
}
