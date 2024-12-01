#include <iostream>

class Baza {
public:
    virtual Baza* clone() {
        return new Baza(*this);
    }
};

class Derivata : public Baza {
public:
    Derivata* clone() {
        return new Derivata(*this);
    }
};

void doSomething(Baza* baza) {              // derivata
    Baza* localBaza = new Baza(*baza);      // baza - INCORECT!
    Baza* localBaza2 = baza->clone();       // derivata - CORECT!
    // cod
}

int main() {
    Derivata derivata;                      // derivata
    doSomething(&derivata);                 // derivata
    return 0;
}
