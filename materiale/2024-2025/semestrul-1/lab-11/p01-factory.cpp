#include <iostream>
#include <memory>

class Jucarie {
public:
    virtual ~Jucarie() {}
    virtual void printInfo() = 0;
    virtual void joaca() = 0;
};

class Masina : public Jucarie {
public:
    void printInfo() override {
        std::cout << "Aceasta este o masina de jucarie\n";
    }

    void joaca() override {
        std::cout << "Masina de jucarie este utilizata\n";
    }
};

class Ratusca : public Jucarie {
public:
    void printInfo() override {
        std::cout << "Aceasta este o ratusca de jucarie\n";
    }

    void joaca() override {
        std::cout << "Ratusca de jucarie este utilizata\n";
    }
};

enum class TipJucarie {MASINA, RATUSCA};

std::shared_ptr<Jucarie> makeJucarieFactory(TipJucarie tipJucarie) {
    if (tipJucarie == TipJucarie::MASINA) {
        return std::make_shared<Masina>();
    } else if (tipJucarie == TipJucarie::RATUSCA) {
        return std::make_shared<Ratusca>();
    }
    return nullptr;
}

int main() {
    std::shared_ptr<Jucarie> masina = makeJucarieFactory(TipJucarie::MASINA);
    std::shared_ptr<Jucarie> ratusca = makeJucarieFactory(TipJucarie::RATUSCA);
    masina->printInfo();
    masina->joaca();
    return 0;
}
