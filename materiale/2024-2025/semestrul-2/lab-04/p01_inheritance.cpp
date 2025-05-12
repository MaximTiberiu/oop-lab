#include <iostream>

/*
 *  Caracter:
 *      - Jucator
 *      - Monstru
 */

class Caracter {
protected:
    std::string nume;
    int hp;

public:
    Caracter() = default;
    ~Caracter() = default;
    Caracter(std::string nume, int hp) {
        this->nume = nume;
        this->hp = hp;
    }

    [[nodiscard]] std::string get_nume() const {
        return nume;
    }

    void set_nume(const std::string &nume) {
        this->nume = nume;
    }

    [[nodiscard]] int get_hp() const {
        return hp;
    }

    void set_hp(int hp) {
        this->hp = hp;
    }

    friend std::ostream &operator<<(std::ostream &os, const Caracter &caracter) {
        os << caracter.nume << "\n";
        os << caracter.hp << "\n";
        return os;
    }

    // virtual void displayInfo() {
    //     std::cout << "Acesta este un caracter!\n";
    // }
    virtual void displayInfo() = 0;
};

class Jucator : public Caracter {
private:
    float putere;

public:
    Jucator() = default;
    ~Jucator() = default;
    Jucator(std::string nume, int hp, float putere) : Caracter(nume, hp) {
        this->putere = putere;
    }

    [[nodiscard]] float get_putere() const {
        return putere;
    }

    void set_putere(float putere) {
        this->putere = putere;
    }

    friend std::ostream &operator<<(std::ostream &os, const Jucator &jucator) {
        os << jucator.nume << "\n";
        os << jucator.hp << "\n";
        os << jucator.putere << "\n";
        return os;
    }

    void displayInfo() override {
        std::cout << "Acesta este un jucator!\n";
    }
};

class Monstru : public Caracter {
private:
    int uratenie;

public:
    Monstru() = default;
    ~Monstru() = default;
    Monstru(std::string nume, int hp, int uratenie) : Caracter(nume, hp) {
        this->uratenie = uratenie;
    }

    [[nodiscard]] int get_uratenie() const {
        return uratenie;
    }

    void set_uratenie(int uratenie) {
        this->uratenie = uratenie;
    }

    friend std::ostream &operator<<(std::ostream &os, const Monstru &monstru) {
        os << monstru.nume << "\n";
        os << monstru.hp << "\n";
        os << monstru.uratenie << "\n";
        return os;
    }

    void displayInfo() override {
        std::cout << "Acesta este un monstru!\n";
    }
};

/*
    PROBLEMA DIAMANT
*/
class A {
    public:
        A() {
            std::cout << "A()" << std::endl;
        }
    };
    
    class B : virtual public A {
    public:
        B() {
            std::cout << "B()" << std::endl;
        }
    };
    
    class C : virtual public A {
    public:
        C() {
            std::cout << "C()" << std::endl;
        }
    };
    
    class D : public B, public C{
    public:
        D() {
            std::cout << "D()" << std::endl;
        }
    };

int main() {
    // Caracter caracter{"c1", 100};
    // std::cout << caracter << "\n";
    // caracter.displayInfo();

    std::cout << "-------------------\n";
    Jucator jucator{"j1", 100, 3};
    std::cout << jucator << "\n";
    jucator.displayInfo();

    std::cout << "-------------------\n";
    Monstru monstru{"m1", 100, 8};
    std::cout << monstru << "\n";
    monstru.displayInfo();

    std::cout << "-------------------\n";
    Caracter *ptrCaracter = new Jucator{"j2", 100, 2};
    std::cout << *ptrCaracter << "\n";
    ptrCaracter->displayInfo();

    std::cout << "--------------------\n";
    D d;
    return 0;
}
