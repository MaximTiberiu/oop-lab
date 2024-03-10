#include <iostream>
#include <vector>
#include <algorithm>

class Smartphone {
private:
    unsigned int RAM;
    unsigned int stocare;
    std::string brand;

public:
    Smartphone() = default;
    ~Smartphone() = default;

    Smartphone(unsigned int ram, unsigned int stocare, const std::string &brand) : RAM(ram), stocare(stocare),
                                                                                   brand(brand) {}

    unsigned int getRam() const {
        return RAM;
    }

    unsigned int getStocare() const {
        return stocare;
    }

    const std::string &getBrand() const {
        return brand;
    }

    friend std::ostream& operator<<(std::ostream& out, const Smartphone& smartphone) {
        out << "Brand: " << smartphone.brand << " | RAM: " << smartphone.RAM << " | Stocare: " << smartphone.stocare << "\n";
        return out;
    }

    Smartphone& operator=(const Smartphone& smartphone) {
        this->brand = smartphone.brand;
        this->stocare = smartphone.stocare;
        this->RAM = smartphone.RAM;
        return *this;
    }
};

bool comparator(const Smartphone& s1, const Smartphone& s2) {
    if (s1.getBrand() == s2.getBrand()) {
        if (s1.getStocare() == s2.getStocare()) {
            return s1.getRam()  > s2.getRam();
        }

        return s1.getStocare() > s2.getStocare();
    }

    return s1.getBrand() < s2.getBrand();
}

int main() {
    std::vector<Smartphone> smartphones;
    smartphones.emplace_back(8, 256, "Xiaomi");
    smartphones.emplace_back(8, 256, "Samsung");
    smartphones.emplace_back(4, 128, "Samsung");
    smartphones.emplace_back(4, 256, "Apple");
    smartphones.emplace_back(12, 512, "Motorola");
    smartphones.emplace_back(12, 256, "Google");

//    for (int i = 0 ; i < smartphones.size() ; i++) {
////        std::cout << "Brand: " << smartphones[i].getBrand() << " | RAM: " << smartphones[i].getRam() << " | Stocare: " << smartphones[i].getStocare() << "\n";
////        operator<<(std::cout, smartphones[i]);
//        std::cout << smartphones[i];
//    }

//    operator<<(operator<<(std::cout, smartphones[1]), smartphones[0]);

//    for (auto& smartphone : smartphones) {
//        std::cout << smartphone;
//    }

    std::sort(smartphones.begin(), smartphones.end(), comparator);

    std::sort(smartphones.begin(), smartphones.end(), [](const Smartphone& s1, const Smartphone& s2) {
        if (s1.getBrand() == s2.getBrand()) {
            if (s1.getStocare() == s2.getStocare()) {
                return s1.getRam()  > s2.getRam();
            }

            return s1.getStocare() > s2.getStocare();
        }

        return s1.getBrand() < s2.getBrand();
    })

    Smartphone nokia1(1, 64, "Nokia");
    std::cout << nokia1;
    Smartphone nokia2, nokia3;
    nokia3 = nokia2 = nokia1;
    std::cout << nokia2;
    return 0;
}
