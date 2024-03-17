#include <iostream>
#include <vector>

class Meteo {
private:
    std::string oras;
    float temperatura;

public:
    Meteo() {
        std::cout << "CONSTRCUTOR DEFAULT\n";
    }

    Meteo(const std::string &oras, float temperatura) : oras(oras), temperatura(temperatura) {
        std::cout << "CONSTRUCTOR PARAM\n";
    }

    Meteo(const Meteo &meteo) {
        this->oras = meteo.oras;
        this->temperatura = meteo.temperatura;
        std::cout << "CONSTRUCTOR COPIERE\n";
    }

    Meteo &operator=(const Meteo &meteo) {
        this->oras = meteo.oras;
        this->temperatura = meteo.temperatura;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &out, const Meteo &meteo) {
        out << "oras: " << meteo.oras << " temperatura: " << meteo.temperatura;
        return out;
    }

    friend std::istream &operator>>(std::istream &in, Meteo &meteo) {
        in >> meteo.oras >> meteo.temperatura;
        return in;
    }

    ~Meteo() {
        std::cout << "DESTRUCTOR\n";
    }

    const std::string &getOras() const {
        return oras;
    }

    void setOras(const std::string &oras) {
        Meteo::oras = oras;
    }

    float getTemperatura() const {
        return temperatura;
    }

    void setTemperatura(float temperatura) {
        Meteo::temperatura = temperatura;
    }
};

int main() {
//    Meteo bucuresti("bucuresti", 12.5);
//    Meteo sector1(bucuresti);
//    Meteo sector2;
//    sector2 = bucuresti;
//    sector2.operator=(bucuresti);
//    Meteo sector3;
//
//    operator<<(std::cout, bucuresti);
//    std::cout << sector2 << "\n\n";
//
////    operator>>(std::cin, sector3);
//    std::cin >> sector3;
//    std::cout << sector3;

    std::vector<Meteo> meteo;
    meteo.reserve(5);
    for (int i = 0 ; i < 5 ; i++) {
        Meteo tempMeteo;
        std::cin >> tempMeteo;
        meteo.emplace_back(tempMeteo);
    }

    std::cout << "\n\nFINAL\n";
    return 0;
}
