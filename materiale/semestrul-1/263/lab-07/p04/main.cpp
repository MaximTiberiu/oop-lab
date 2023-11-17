#include <iostream>

class Baza {
public:
    // functionalitati

    virtual Baza* clone() {
        return new Baza(*this);
    }
};

class Derivata : public Baza {
public:
    // functionalitati specifice Derivatei

    Derivata* clone() override {
        return new Derivata(*this);
    }
};

void blaBla(Baza *localBaza) { // TIP: DERIVATA
    Baza *baza = new Baza(*localBaza); // TIP: BAZA (incorect!!!)
    Baza *baza2 = localBaza->clone(); // TIP: DERIVATA (corect)
    // cod

}

int main() {
    Derivata derivata;
    blaBla(&derivata);
    return 0;
}
