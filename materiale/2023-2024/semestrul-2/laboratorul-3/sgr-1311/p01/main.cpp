#include <iostream>
#include <vector>

class EchipaF1 {
private:
    std::string nume;
    unsigned int codEchipa;

public:
    EchipaF1() {
        std::cout << "CONSTRUCTOR DEFAULT\n";
    };

    EchipaF1(const std::string &nume, unsigned int codEchipa) : nume(nume), codEchipa(codEchipa) {
        std::cout << "CONSTRUCTOR PARAM\n";
    }

    EchipaF1(const EchipaF1 &echipaF1) {
        this->nume = echipaF1.nume;
        this->codEchipa = echipaF1.codEchipa;
        std::cout << "CONSTRUCTOR COPIERE\n";
    }

    EchipaF1 &operator=(const EchipaF1 &echipaF1) {
        this->codEchipa = echipaF1.codEchipa;
        this->nume = echipaF1.nume;
        return *this;
    }

    ~EchipaF1() {
        std::cout << "DESTRUCTOR\n";
    }

    const std::string &getNume() const {
        return nume;
    }

    void setNume(const std::string &nume) {
        EchipaF1::nume = nume;
    }

    unsigned int getCodEchipa() const {
        return codEchipa;
    }

    void setCodEchipa(unsigned int codEchipa) {
        EchipaF1::codEchipa = codEchipa;
    }

    friend std::ostream &operator<<(std::ostream &out, const EchipaF1 &echipaF1) {
        out << "nume: " << echipaF1.nume << " codEchipa: " << echipaF1.codEchipa;
        return out;
    }

    friend std::istream &operator>>(std::istream &in, EchipaF1 &echipaF1) {
        in >> echipaF1.nume >> echipaF1.codEchipa;
        return in;
    }
};

int main() {
//    EchipaF1 ferrari("Ferrari", 105);
//    std::cout << ferrari;
//    operator<<(std::cout, ferrari);
//    // constructor de copiere
//    EchipaF1 redBull(ferrari);
//
//    // operator=
//    EchipaF1 mercedes;
////    mercedes.operator=(ferrari);
//    mercedes = ferrari;

//    EchipaF1 echipaF1;
//    operator>>(std::cin, echipaF1);
//    std::cout << echipaF1;

    std::vector<EchipaF1> echipeF1;
    echipeF1.reserve(5);
    for (int i = 0 ; i < 5; i++) {
        EchipaF1 tempEchipaF1;
        std::cin >> tempEchipaF1;
        echipeF1.emplace_back(tempEchipaF1);
    }

    std::cout << "\n\nFINAL\n";

    return 0;
}
