#include <iostream>
#include <memory>
#include <vector>

class Animal {
protected:
    std::string nume;

public:
    Animal() = default;
    Animal(std::string nume) : nume(nume) {}

    virtual void print(std::ostream& os) const {
        os << nume << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const Animal& animal) {
        animal.print(os);
        return os;
    }

    virtual void zgomot() = 0;

    virtual Animal* clone() = 0;
};

class Caine : public Animal {
private:
    int varsta;

public:
    Caine() = default;
    Caine(std::string nume, int varsta) : Animal(nume), varsta(varsta) {}

    void print(std::ostream& os) const override {
        Animal::print(os);
        os << varsta << std::endl;
    }

    void zgomot() override {
        std::cout << "ham\n";
    }

    void musca() {
        std::cout << "am muscat\n";
    }

    Animal* clone() override {
        return new Caine(*this);
    }
};

class Pisica : public Animal {
private:
    float greutate;

public:
    Pisica() = default;
    Pisica(std::string nume, float greutate) : Animal(nume), greutate(greutate) {}

    void print(std::ostream& os) const override {
        Animal::print(os);
        os << greutate << std::endl;
    }

    void zgomot() override {
        std::cout << "miau\n";
    }

    void zgarie() {
        std::cout << "am zgariat\n";
    }

    Animal* clone() override {
        return new Pisica(*this);
    }
};

class A {
public:
    void print() {
        std::cout << "A\n";
    }
};

class B : public A {
public:
    void print() {
        std::cout << "B\n";
    }
};

int main() {
    Animal *c = new Caine("caine", 10);
    std::cout << *c << std::endl;

    Animal *p = new Pisica("pisica", 4.5);
    std::cout << *p << std::endl;

    std::cout << "---------------------------\n";
    Animal *c1 = c->clone();
    std::cout << *c1 << std::endl;

    Animal *p1 = p->clone();
    std::cout << *p1 << std::endl;

    std::cout << "--------------UPCASTING-------------\n";
    B b;
    b.print();

    A &a = b;
    a.print();

    std::cout << "--------------DOWNCASTING-------------\n";
    std::vector<Animal*> animale;
    animale.push_back(new Caine("caine1", 10));
    animale.push_back(new Pisica("pisica1", 4.5));
    animale.push_back(new Caine("caine2", 10));
    animale.push_back(new Pisica("pisica2", 4.5));
    animale.push_back(new Caine("caine3", 10));
    animale.push_back(new Pisica("pisica3", 4.5));

    for (auto animal : animale) {
        Caine *caine = dynamic_cast<Caine*>(animal);
        Pisica *pisica = dynamic_cast<Pisica*>(animal);

        animal->zgomot();

        if (caine != nullptr) {
            caine->musca();
        } else {
            std::cout << "Nu sunt un caine!\n";
        }

        if (pisica != nullptr) {
            pisica->zgarie();
        } else {
            std::cout << "Nu sunt o pisica!\n";
        }

        std:: cout << "_____________________\n";
    }

    for (auto animal : animale) {
        if (dynamic_cast<Caine*>(animal) != nullptr) {
            std::cout << *animal << std::endl;
        }
    }

    std::cout << "--------------SMART_PTRS-------------\n";

    std::shared_ptr<Animal> smart_c = std::make_shared<Caine>("caine", 10);
    std::cout << smart_c.use_count() << std::endl;
    std::weak_ptr<Animal> smart_c1 = smart_c;
    std::cout << smart_c.use_count() << std::endl;


    {
        std::shared_ptr<Animal> smart_c2 = smart_c;
        std::cout << smart_c.use_count() << std::endl;
    }
    std::cout << smart_c.use_count() << std::endl;

    {
        std::unique_ptr<Animal> smart_p = std::make_unique<Pisica>("pisica", 4.5);
        ///
    }


    return 0;
}
