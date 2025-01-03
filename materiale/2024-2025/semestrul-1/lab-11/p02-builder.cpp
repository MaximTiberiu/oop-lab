#include <iostream>

class Masina {
private:
    std::string tipMasina;
    std::string sasiu;
    std::string motor;

public:
    Masina(const std::string& tipMasina) : tipMasina(tipMasina) {}

    [[nodiscard]] std::string getSasiu() const {
        return sasiu;
    }

    void setSasiu(const std::string &sasiu) {
        this->sasiu = sasiu;
    }

    [[nodiscard]] std::string getMotor() const {
        return motor;
    }

    void setMotor(const std::string &motor) {
        this->motor = motor;
    }

    void printInfo() const {
        std::cout << tipMasina << std::endl;
        std::cout << sasiu << std::endl;
        std::cout << motor << std::endl;
    }
};

class MasinaBuilder {
protected:
    Masina *masina;

public:
    virtual void createMasina() = 0;
    virtual void buildSasiu() = 0;
    virtual void buildMotor() = 0;
    Masina* getMasina() { return masina; }
};

class Masina4x4Builder : public MasinaBuilder {
public:
    void createMasina() override {
        masina = new Masina("Masina 4x4");
    }

    void buildSasiu() override {
        masina->setSasiu("Sasiu 4x4");
    }

    void buildMotor() override {
        masina->setMotor("Motor 4x4");
    }
};

class MasinaLimuzinaBuilder : public MasinaBuilder {
public:
    void createMasina() override {
        masina = new Masina("Masina Limuzina");
    }

    void buildSasiu() override {
        masina->setSasiu("Sasiu Limuzina");
    }

    void buildMotor() override {
        masina->setMotor("Motor Limuzina");
    }
};

class Director {
public:
    Masina* buildMasina4x4(MasinaBuilder* masinaBuilder) {
        masinaBuilder->createMasina();
        masinaBuilder->buildSasiu();
        masinaBuilder->buildMotor();
        return masinaBuilder->getMasina();
    }

    Masina* buildMasina4x4FaraMotor(MasinaBuilder* masinaBuilder) {
        masinaBuilder->createMasina();
        masinaBuilder->buildSasiu();
        return masinaBuilder->getMasina();
    }

    Masina* buildMasinaLimuzina(MasinaBuilder* masinaBuilder) {
        masinaBuilder->createMasina();
        masinaBuilder->buildSasiu();
        masinaBuilder->buildMotor();
        return masinaBuilder->getMasina();
    }
};

int main() {
    Director director;
    Masina4x4Builder masina4x4Builder;
    MasinaLimuzinaBuilder masinaLimuzinaBuilder;


    Masina* masina4x4 = director.buildMasina4x4(&masina4x4Builder);
    masina4x4->printInfo();

    Masina* masinaLimuzina = director.buildMasinaLimuzina(&masinaLimuzinaBuilder);
    masinaLimuzina->printInfo();

    Masina* masina4x4FaraMotor = director.buildMasina4x4FaraMotor(&masina4x4Builder);
    masina4x4FaraMotor->printInfo();
    return 0;
}
