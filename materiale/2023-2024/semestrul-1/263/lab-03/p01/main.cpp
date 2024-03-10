#include <iostream>
#include <vector>

class Curs {
private:
    unsigned int numarOre{};
    std::string titular;
    unsigned int grupa{};
public:
    Curs() = default;
    ~Curs() {
        std::cout << "DESTRUCTOR APELAT!\n";
    }

    Curs(unsigned int numarOre, const std::string &titular, unsigned int grupa) : numarOre(numarOre), titular(titular),
                                                                                  grupa(grupa) {
        std::cout << "CONSTRUCTOR APELAT\n";
    }

    Curs(const Curs & curs) {
        this->numarOre = curs.numarOre;
        this->titular = curs.titular;
        this->grupa = curs.grupa;

        std::cout << "CC APELAT!\n";
    }

    // getters
    unsigned int getNumarOre() const {
        return numarOre;
    }

    const std::string &getTitular() const {
        return titular;
    }

    unsigned int getGrupa() const {
        return grupa;
    }

    // setters
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
    unsigned int numarCursuri;
    std::vector<Curs> cursuri;

    cursuri.reserve(3);

    std::cin >> numarCursuri;
    for (int i = 0 ; i < numarCursuri ; i++) {
        unsigned int tempNumarOre, tempGrupa;
        std::string tempTitular;

        std::cin >> tempNumarOre >> tempTitular >> tempGrupa;

//        Curs tempCurs(tempNumarOre, tempTitular, tempGrupa);
//        cursuri.emplace_back(tempCurs);
//        cursuri.push_back(tempCurs);
        cursuri.emplace_back(tempNumarOre, tempTitular, tempGrupa);
    }

    for (int i = 0 ; i < numarCursuri ; i++) {
        std::cout << cursuri[i].getNumarOre() << " " << cursuri[i].getTitular() << " " << cursuri[i].getGrupa() << "\n";
    }
    return 0;
}
