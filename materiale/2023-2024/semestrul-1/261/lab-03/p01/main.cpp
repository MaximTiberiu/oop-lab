#include <iostream>
#include <vector>

class Curs {
private:
    unsigned int numarOre;
    std::string titular;
    unsigned int grupa;

public:
    Curs() = default;
    ~Curs() {
        std::cout << "Apelare destructor!\n";
    }
    Curs(unsigned int numarOre, const std::string &titular, unsigned int grupa) : numarOre(numarOre), titular(titular),
                                                                                  grupa(grupa) {
        std::cout << "Apelare constructor!\n";
    }

    Curs(const Curs & curs) {
        this->numarOre = curs.numarOre;
        this->titular = curs.titular;
        this->grupa = curs.grupa;

        std::cout << "Apelare CC!\n";
    }

    unsigned int getNumarOre() const {
        return numarOre;
    }

    const std::string &getTitular() const {
        return titular;
    }

    unsigned int getGrupa() const {
        return grupa;
    }

    void setNumarOre(unsigned int numarOre) {
        Curs::numarOre = numarOre;
    }

    void setTitular(const std::string &titular) {
        Curs::titular = titular;
    }

    void setGrupa(unsigned int grupa) {
        Curs::grupa = grupa;
    }
};

int main() {
    int numarCursuri;
    std::vector<Curs> cursuri;

    std::cin >> numarCursuri;
    cursuri.reserve(numarCursuri);

    for (int i = 0 ; i < numarCursuri ; i++) {
        unsigned int tempNumarOre, tempGrupa;
        std::string tempTitular;
        std::cin >> tempNumarOre >> tempTitular >> tempGrupa;
//        Curs tempCurs(tempNumarOre, tempTitular, tempGrupa);
//        cursuri.emplace_back(tempCurs);
        cursuri.emplace_back(tempNumarOre, tempTitular, tempGrupa);
    }

    std::cout << "OUTPUT\n";
    for (int i = 0 ; i < numarCursuri ; i++) {
        std::cout << cursuri[i].getNumarOre() << " " << cursuri[i].getTitular() << " " << cursuri[i].getGrupa() << "\n";
    }
    return 0;
}
