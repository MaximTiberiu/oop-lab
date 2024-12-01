#include <iostream>
#include <memory>
#include <vector>

class Baza {
protected:
    int a, b, c;

public:
    virtual void display() {
        std::cout << "Baza\n";
    }
};

class Derivata1 : public Baza {
private:
    char d;

public:
    void display() {
        std::cout << "Derivata1\n";
    }
};

class Derivata2 : public Baza {
private:
    float e;

public:
    void display() {
        std::cout << "Derivata2\n";
    }
};

class Fruct {
public:
    virtual void display() = 0;
};

class Mar : public Fruct {
public:
    void display() override {
        std::cout << "Mar\n";
    }
};

class Para : public Fruct {
public:
    void display() override {
        std::cout << "Para\n";
    }
};

int main() {
    // Derivata1 derivata1;
    //
    // Baza* baza = dynamic_cast<Baza*>(&derivata1); // UPCASTING
    // if (baza == nullptr) {
    //     std::cout << "Upcasting esuat.\n";
    // } else {
    //     std::cout << "Upcasting cu succes.\n";
    // }
    //
    // Derivata2* derivata2 = dynamic_cast<Derivata2*>(baza); // DOWNCASTING
    // if (derivata2 == nullptr) {
    //     std::cout << "Downcasting esuat.\n";
    // } else {
    //     std::cout << "Downcasting cu succes.\n";
    // }

    std::vector<Fruct*> fructe;
    fructe.push_back(new Mar);
    fructe.push_back(new Para);
    fructe.push_back(new Mar);
    fructe.push_back(new Para);
    fructe.push_back(new Mar);
    fructe.push_back(new Mar);
    fructe.push_back(new Para);

    for(int i = 0; i < fructe.size(); i++) {
        std::cout << i << ": ";
        fructe[i]->display();
    }

    std::cout << "------------------------\n";

    // filtrare pere
    for (int i = 0; i < fructe.size(); i++) {
        if (dynamic_cast<Para*>(fructe[i]) != nullptr) {
            std::cout << i << ": ";
            fructe[i]->display();
        }
    }

    std::cout << "SMART PTRS\n";

    std::vector<std::shared_ptr<Fruct>> fructe2;
    fructe2.push_back(std::make_shared<Mar>());
    fructe2.push_back(std::make_shared<Para>());
    fructe2.push_back(std::make_shared<Mar>());
    fructe2.push_back(std::make_shared<Para>());
    fructe2.push_back(std::make_shared<Mar>());
    fructe2.push_back(std::make_shared<Mar>());
    fructe2.push_back(std::make_shared<Para>());

    for(int i = 0; i < fructe2.size(); i++) {
        std::cout << i << ": ";
        fructe2[i]->display();
    }

    std::cout << "------------------------\n";

    // filtrare mere
    for (int i = 0; i < fructe2.size(); i++) {
        if (dynamic_pointer_cast<Mar>(fructe2[i]) != nullptr) {
            std::cout << i << ": ";
            fructe2[i]->display();
        }
    }

    return 0;
}
