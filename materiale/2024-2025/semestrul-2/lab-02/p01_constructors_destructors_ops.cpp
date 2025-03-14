#include <iostream>

class Fruct {
    std::string nume_fruct;
    float greutate_fruct{};

public:

    Fruct() { // analog cu Fruct() = default;
        std::cout << "Constructor Initializare Fruct\n";
    };

    Fruct(const std::string& nume_fruct, float greutate_fruct) {
        this->nume_fruct = nume_fruct;
        this->greutate_fruct = greutate_fruct;
        std::cout << "Constructor Parametrizabil\n";
    }

    Fruct(float greutate_fruct) {
        this->greutate_fruct = greutate_fruct;
        this->nume_fruct = "Fruct";
        std::cout << "Constructor Parametrizabil - doar greutate\n";
    }

    Fruct(const Fruct& other) {
        std::cout << "Constructor de Copiere\n";
        this->nume_fruct = other.nume_fruct;
        this->greutate_fruct = other.greutate_fruct;
    }

    // Fruct(Fruct&& other) {
    //     std::cout << "Constructor de Mutare\n";
    //     this->nume_fruct = std::move(other.nume_fruct);
    //     this->greutate_fruct = other.greutate_fruct;
    // }

    Fruct& operator=(const Fruct& other) {
        std::cout << "Operator egal\n";
        this->nume_fruct = other.nume_fruct;
        this->greutate_fruct = other.greutate_fruct;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Fruct& fruct) {
        os << fruct.nume_fruct << "\n";
        os << fruct.greutate_fruct << "\n";
        return os;
    }

    ~Fruct() {
        std::cout << "Destructor Fruct\n";
        std::cout << "Am distrus: " << nume_fruct << "\n";
    }

    float getGreutateFruct() {
        return greutate_fruct;
    }

    std::string getNumeFruct() {
        return nume_fruct;
    }

    void setGreutateFruct(float greutate_fruct) {
        this->greutate_fruct = greutate_fruct;
    }

    void setNumeFruct(const std::string& nume_fruct) {
        this->nume_fruct = nume_fruct;
    }
};

int main()
{
    std::cout << "BEFORE\n";
    Fruct fruct1;
    Fruct fruct2("mar", 103.4);

    std::cout << fruct2.getNumeFruct() << " " << fruct2.getGreutateFruct() << std::endl;

    fruct2.setGreutateFruct(103.3);

    std::cout << fruct2.getNumeFruct() << " " << fruct2.getGreutateFruct() << std::endl;

    Fruct fruct3{200};

    std::cout << fruct3.getNumeFruct() << " " << fruct3.getGreutateFruct() << std::endl;

    Fruct fruct4(fruct3);
    std::cout << fruct4.getNumeFruct() << " " << fruct4.getGreutateFruct() << std::endl;

    Fruct fruct5(std::move(fruct2));
    std::cout << fruct5.getNumeFruct() << " " << fruct5.getGreutateFruct() << std::endl;

    Fruct fruct6 = fruct2; // analog cu fruct6.operator=(fruct2);
    operator<<(operator<<(std::cout, fruct6), fruct5);
    std::cout << fruct6 << fruct5;

    std::cout << "-------------------\n";
    Fruct fruct7;
    fruct7 = fruct2;

    std::cout << "AFTER\n";
    // fruct2(fruct1), fruct3{fruct1};
    // Fruct fruct4 = fruct1;
    return 0;
}
