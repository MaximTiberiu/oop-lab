#include <iostream>

class Baza {
public:
    virtual Baza* clone() {
        return new Baza(*this);
    }
};

class Derivata : public Baza {
    Derivata* clone() override {
        return new Derivata(*this);
    }
};

void blaBla(Baza *baza) { // Derivata
//    Baza *localBaza = new Baza(*baza); // Baza
    Baza *localBaza = baza->clone(); // Derivata
    // cod
}

int main() {
//    Derivata derivata; // derivata
//    Baza *baza = new Baza(derivata); // baza

    Derivata derivata2;
    blaBla(&derivata2);
    return 0;
}
