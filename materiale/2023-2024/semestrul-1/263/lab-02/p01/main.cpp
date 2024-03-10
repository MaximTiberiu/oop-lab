#include <iostream>
#include <cmath>

class Fruct {
private:
    int greutate;
    std::string culoare;

public:
    Fruct() = default;
    ~Fruct() = default;

    Fruct(int greutate, const std::string &culoare) {
        this->greutate = greutate;
        this->culoare = culoare;
    }

    void setGreutate(int greutate) {
        this->greutate = greutate;
    }

    int getGreutate() {
        return this->greutate;
    }

    void setCuloare(const std::string &culoare) {
        this->culoare = culoare;
    }

    const std::string &getCuloare() {
        return this->culoare;
    }
};

class Punct {
private:
    int abscisa;
    int ordonata;

public:
    Punct() = default;
    ~Punct() = default;

    Punct(int abcisa, int ordonata) {
        this->abscisa = abcisa;
        this->ordonata = ordonata;
    }

    int getAbscisa() {
        return this->abscisa;
    }

    int getOrdonata() {
        return this->ordonata;
    }

    void setAbcisa(int ab) {
        this->abscisa = ab;
    }

    void setOrdonata(int ord) {
        this->ordonata = ord;
    }
};

class Dreptunghi {
private:
    Punct punct_1;
    Punct punct_2;

    int x1, x2, y1, y2;

public:
    Dreptunghi() = default;
    ~Dreptunghi() = default;

    Dreptunghi(Punct p1, Punct p2) {
        this->punct_1 = p1;
        this->punct_2 = p2;
    }

//    Dreptunghi(int x1, int y1, int x2, int y2) {
//        this->punct_1.setAbcisa(x1);
//        this->punct_1.setOrdonata(y1);
//        this->punct_2.setAbcisa(x2);
//        this->punct_2.setOrdonata(y2);
//    }

    Dreptunghi(int x1, int y1, int x2, int y2) : punct_1(x1, y1), punct_2(x2, y2) {
    }

    void calculeazaArie() {
        int x1 = punct_1.getAbscisa();
        int y1 = punct_1.getOrdonata();

        int x2 = punct_2.getAbscisa();
        int y2 = punct_2.getOrdonata();

        double L = std::sqrt(std::pow(x2 - x1, 2));
        double l = std::sqrt(std::pow(y2 - y1, 2));

        std::cout << "Aria dreptunghiului este: " << L * l << "\n";
    }

    double calculeazaArieReturn() {
        int x1 = punct_1.getAbscisa();
        int y1 = punct_1.getOrdonata();

        int x2 = punct_2.getAbscisa();
        int y2 = punct_2.getOrdonata();

        double L = std::sqrt(std::pow(x2 - x1, 2));
        double l = std::sqrt(std::pow(y2 - y1, 2));

        return L * l;
    }

};

int main() {

    Punct a(1, 1);
    Punct b(3, 3);

    Dreptunghi d1;
    Dreptunghi d2(a, b);
    Dreptunghi d3(2, 2, 6, 6);
    d2.calculeazaArie();
    d3.calculeazaArie();

    std::cout << "Functie double: " << d3.calculeazaArieReturn() << "\n";

//    Fruct mar;
//    mar.setGreutate(100);
//    mar.setCuloare("rosu");
//    std::cout << "Culoare: " <<mar.getCuloare() << " | Greutate: " << mar.getGreutate() << "\n\n\n\n";
//
//    Fruct banana(200, "galben");
//    std::cout << "Culoare: " <<banana.getCuloare() << " | Greutate: " << banana.getGreutate() << "\n";
    return 0;
}
