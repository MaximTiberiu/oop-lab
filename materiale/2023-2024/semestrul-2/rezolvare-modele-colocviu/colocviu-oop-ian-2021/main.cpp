// https://tinyurl.com/model-colocviu-oop
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

class Jucarie {
protected:
    std::string denumire;
    float dimensiune{};
    std::string tip;

public:
    Jucarie() = default;
    virtual ~Jucarie() = default;

    Jucarie(const std::string& denumire, float dimensiune, const std::string& tip) {
        this->denumire = denumire;
        this->dimensiune = dimensiune;
        this->tip = tip;
    }

    friend std::istream& operator>>(std::istream& in, Jucarie& jucarie) {
        jucarie.read(in);
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Jucarie& jucarie) {
        jucarie.print(out);
        return out;
    }

    virtual void read(std::istream& in) {
        std::cout << "Denumire: ";
        in >> denumire;

        std::cout << "Dimensiune: ";
        in >> dimensiune;

        std::cout << "Tip: ";
        in >> tip;
    }

    virtual void print(std::ostream& out) const {
        out << "Denumire: " << denumire << "\n";
        out << "Dimensiune: " << dimensiune << "\n";
        out << "Tip: " << tip << "\n";
    }
};

class JucarieClasica : public Jucarie {
private:
    std::string material;
    std::string culoare;

public:
    JucarieClasica() = default;
    ~JucarieClasica() override = default;

    JucarieClasica(const std::string& denumire, float dimensiune, const std::string& tip,
                   const std::string& material, const std::string& culoare) : Jucarie(denumire, dimensiune, tip) {
        this->material = material;
        this->culoare = culoare;
    }

    void read(std::istream& in) override {
        Jucarie::read(in);

        std::cout << "Material: ";
        in >> material;

        std::cout << "Culoare: ";
        in >> culoare;
    }

    void print(std::ostream& out) const override {
        Jucarie::print(out);
        out << "Material: " << material << "\n";
        out << "Culoare: " << culoare << "\n";
    }
};

class JucarieEducativa : virtual public Jucarie {
protected:
    std::string abilitate;

public:
    JucarieEducativa() = default;
    ~JucarieEducativa() override = default;

    JucarieEducativa(const std::string& denumire, float dimensiune, const std::string& tip, const std::string& abilitate)
        : Jucarie(denumire, dimensiune, tip) {
        this->abilitate = abilitate;
    }

    void read (std::istream& in) override {
        Jucarie::read(in);

        std::cout << "Abilitate: ";
        in >> abilitate;
    }

    void print(std::ostream& out) const override {
        Jucarie::print(out);
        out << "Abilitate: " << abilitate << "\n";
    }
};

class JucarieElectronica : virtual public Jucarie {
protected:
    int numarBaterii{};

public:
    JucarieElectronica() = default;
    ~JucarieElectronica() override = default;

    JucarieElectronica(const std::string& denumire, float dimensiune, const std::string& tip, int numarBaterii)
        : Jucarie(denumire, dimensiune, tip) {
        this->numarBaterii = numarBaterii;
    }

    void read(std::istream& in) override {
        Jucarie::read(in);

        std::cout << "Numar baterii: ";
        in >> numarBaterii;
    }

    void print(std::ostream& out) const override {
        Jucarie::print(out);
        out << "Numar baterii: " << numarBaterii << "\n";
    }
};

class JucarieModerna : public JucarieEducativa, public JucarieElectronica {
private:
    std::string brand;
    std::string model;

public:
    JucarieModerna() = default;
    ~JucarieModerna() override = default;

    JucarieModerna(const std::string& denumire, float dimensiune, const std::string& tip, const std::string& brand,
                   const std::string& model) : JucarieEducativa(denumire, dimensiune, tip, "generala") {
        this->numarBaterii = 1;
        this->brand = brand;
        this->model = model;
    };

    void read(std::istream &in) override {
        std::cout << "Denumire: ";
        in >> denumire;

        std::cout << "Dimensiune: ";
        in >> dimensiune;

        std::cout << "Tip: ";
        in >> tip;

        std::cout << "Brand: ";
        in >> brand;

        std::cout << "Model: ";
        in >> model;
    }

    void print(std::ostream &out) const override {
        JucarieEducativa::print(out);
        out << "Numar baterii: " << numarBaterii << "\n";
        out << "Brand: " << brand << "\n";
        out << "Model: " << model << "\n";
    }
};

class Copil {
protected:
    static int static_idCopil;
    const int idCopil{};
    std::string nume;
    std::string prenume;
    std::string adresa;
    unsigned int varsta{};
    unsigned int numarFapteBune{};
    std::vector<std::shared_ptr<Jucarie>> jucarii; // echivalent cu: std::vector<Jucarie*> jucarii
public:
    Copil() : idCopil(++static_idCopil) {};
    virtual ~Copil() = default;

    Copil(const std::string& nume, const std::string& prenume, const std::string& adresa, unsigned int varsta,
          unsigned int numarFapteBune, const std::vector<std::shared_ptr<Jucarie>>& jucarii) : idCopil(++static_idCopil) {
        this->nume = nume;
        this->prenume = prenume;
        this->adresa = adresa;
        this->varsta = varsta;
        this->numarFapteBune = numarFapteBune;
        this->jucarii = jucarii;
    }

    friend std::istream& operator>>(std::istream& in, Copil& copil) {
        copil.read(in);
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Copil& copil) {
        copil.print(out);
        return out;
    }

    virtual void read(std::istream& in) {
        std::cout << "Nume: ";
        in >> nume;

        std::cout << "Prenume: ";
        in >> prenume;

        std::cout << "Adresa: ";
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(in, adresa);

        std::cout << "Varsta: ";
        in >> varsta;

        std::cout << "Numar fapte bune: ";
        in >> numarFapteBune;

        for (int i = 0 ; i < numarFapteBune ; i++) {
            std::shared_ptr<Jucarie> tempJucarie;
            unsigned int option, conditieCitire = 0;
            while (conditieCitire == 0) {
                std::cout << "Tip jucarie (1-clasica, 2-educativa, 3-electronica, 4-moderna): ";
                std::cin >> option;
                conditieCitire = 1;
                try {
                    switch (option) {
                        case 1: {
                            tempJucarie = std::make_shared<JucarieClasica>();
                            break;
                        }
                        case 2: {
                            tempJucarie = std::make_shared<JucarieEducativa>();
                            break;
                        }
                        case 3: {
                            tempJucarie = std::make_shared<JucarieElectronica>();
                            break;
                        }
                        case 4: {
                            tempJucarie = std::make_shared<JucarieModerna>();
                            break;
                        }
                        default: {
                            throw option;
                            break;
                        }
                    }
                    tempJucarie->read(std::cin);
                    jucarii.push_back(tempJucarie);
                } catch (...) {
                    std::cout << "Eroare: Optiune invalida!\n";
                    conditieCitire = 0;
                }
            }
        }
    }

    virtual void print(std::ostream& out) const {
        out << "ID: " << idCopil << "\n";
        out << "Nume si Prenume: " << nume << " " << prenume << "\n";
        out << "Adresa: " << adresa << "\n";
        out << "Varsta: " << varsta << "\n";
        out << "Numar fapte bune: " << numarFapteBune << "\n";
        out << "Jucarii:\n";
        for (auto &jucarie : jucarii) {
            jucarie->print(out);
        }
    }

    void setNumarFapteBune(unsigned int numarFapteBune) {
        this->numarFapteBune = numarFapteBune;
    }

    [[nodiscard]] const std::string &getNume() const {
        return this->nume;
    }

    [[nodiscard]] unsigned int getVarsta() const {
        return this->varsta;
    }

    void setJucarii(const std::vector<std::shared_ptr<Jucarie>>& jucarii) {
        this->jucarii = jucarii;
    }

    [[nodiscard]] unsigned int getNumarFapteBune() const {
        return this->numarFapteBune;
    }

    [[nodiscard]] const std::vector<std::shared_ptr<Jucarie>>& getJucarii() const {
        return this->jucarii;
    }

    [[nodiscard]] int getIdCopil() const {
        return this->idCopil;
    }
};

int Copil::static_idCopil = 0;

class CopilCuminte : public Copil {
private:
    int numarDulciuri{};

public:
    CopilCuminte() = default;
    ~CopilCuminte() override = default;
    CopilCuminte(const std::string& nume, const std::string& prenume, const std::string& adresa, unsigned int varsta,
                 unsigned int numarFapteBune, const std::vector<std::shared_ptr<Jucarie>>& jucarii, int numarDulciuri)
                 : Copil(nume, prenume, adresa, varsta, numarFapteBune, jucarii) {
        this->numarDulciuri = numarDulciuri;
    }

    void read(std::istream& in) override {
        std::cout << "Nume: ";
        in >> nume;

        std::cout << "Prenume: ";
        in >> prenume;

        std::cout << "Adresa: ";
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(in, adresa);

        std::cout << "Varsta: ";
        in >> varsta;

        std::cout << "Numar fapte bune: ";
        in >> numarFapteBune;
        // este corect, dar pentru testare ramane comentat
//        while(numarFapteBune < 10) {
//            std::cout << "Numar fapte bune gresit! Numarul de fapte bune trebuie sa fie >= 10!\n";
//            std::cout << "Numar fapte bune: ";
//            in >> numarFapteBune;
//        }
        std::cout << "Numar dulciuri: ";
        in >> numarDulciuri;

        for (int i = 0 ; i < numarFapteBune ; i++) {
            std::shared_ptr<Jucarie> tempJucarie;
            unsigned int option, conditieCitire = 0;
            while (conditieCitire == 0) {
                std::cout << "Tip jucarie (1-clasica, 2-educativa, 3-electronica, 4-moderna): ";
                std::cin >> option;
                conditieCitire = 1;
                try {
                    switch (option) {
                        case 1: {
                            tempJucarie = std::make_shared<JucarieClasica>();
                            break;
                        }
                        case 2: {
                            tempJucarie = std::make_shared<JucarieEducativa>();
                            break;
                        }
                        case 3: {
                            tempJucarie = std::make_shared<JucarieElectronica>();
                            break;
                        }
                        case 4: {
                            tempJucarie = std::make_shared<JucarieModerna>();
                            break;
                        }
                        default: {
                            throw option;
                            break;
                        }
                    }
                    tempJucarie->read(std::cin);
                    jucarii.push_back(tempJucarie);
                } catch (...) {
                    std::cout << "Eroare: Optiune invalida!\n";
                    conditieCitire = 0;
                }
            }
        }
    }

    void print(std::ostream& out) const override {
        Copil::print(out);
        out << "Numar dulciuri: " << numarDulciuri << "\n";
    }
};

class CopilNeastamparat : public Copil {
private:
    int numarCarbuni{};

public:
    CopilNeastamparat() = default;
    ~CopilNeastamparat() override = default;

    CopilNeastamparat(const std::string& nume, const std::string& prenume, const std::string& adresa, unsigned int varsta,
                      unsigned int numarFapteBune, const std::vector<std::shared_ptr<Jucarie>>& jucarii, int numarCarbuni)
                      : Copil(nume, prenume, adresa, varsta, numarFapteBune, jucarii) {
        this->numarCarbuni = numarCarbuni;
    }

    void read(std::istream& in) override {
        Copil::read(in);
        std::cout << "Numar carbuni: ";
        in >> numarCarbuni;
    }

    void print(std::ostream& out) const override {
        Copil::print(out);
        out << "Numar carbuni: " << numarCarbuni << "\n";
    }
};

// functie comparator necesara in sortare (daca nu optati pentru functii lambda)
[[maybe_unused]] bool comparator(const std::shared_ptr<Copil>& a, const std::shared_ptr<Copil>& b) {
    return a->getNumarFapteBune() < b->getNumarFapteBune();
}

class Meniu {
private:
    static Meniu* instance;
    Meniu() = default;
    std::vector<std::shared_ptr<Copil>> copii;

public:
    ~Meniu() = default;
    static Meniu* getInstance() {
        if (instance == nullptr) {
            instance = new Meniu();
        }
        return instance;
    }

    // functii
    static void meniu() {
        std::cout << "-------------------------------\n";
        std::cout << "\tMENIU\tALEGETI O OPTIUNE:\n";
        std::cout << "1. Citire Copii\n";
        std::cout << "2. Afisare Copii\n";
        std::cout << "3. Cautare Copil\n";
        std::cout << "4. Ordonare dupa Varsta\n";
        std::cout << "5. Ordonare dupa numarul de fapte bune\n";
        std::cout << "6. Adaugare fapte bune\n";
        std::cout << "7. Raport jucarii\n";
        std::cout << "0. Iesire\n";
        std::cout << "-------------------------------\n";
    }

    void adaugareCopii() {
        unsigned int numarCopii;
        std::cout << "Numarul de copii este: ";
        std::cin >> numarCopii;

        for (int i = 0 ; i < numarCopii ; i++) {
            unsigned int option, conditieCitire = 0;
            std::shared_ptr<Copil> tempCopil;
            while (conditieCitire == 0) {
                std::cout << "Tip copil (1-Cuminte, 2-Neastamparat): ";
                std::cin >> option;
                conditieCitire = 1;
                try {
                    switch (option) {
                        case 1: {
                            tempCopil = std::make_shared<CopilCuminte>();
                            break;
                        }
                        case 2: {
                            tempCopil = std::make_shared<CopilNeastamparat>();
                            break;
                        }
                        default: {
                            throw option;
                        }
                    }
                    tempCopil->read(std::cin);
                    copii.push_back(tempCopil);
                } catch(...) {
                    std::cout << "Eroare: Optiune invalida!\n";
                    conditieCitire = 0;
                }
            }
        }
    }

    void afisareCopii() {
        for (auto &copil : copii) {
            copil->print(std::cout);
        }
    }

    void cautaCopil(const std::string& numeCopil) {
        std::size_t found;
        for (auto &copil : copii) {
            found = copil->getNume().find(numeCopil);
            if (found != std::string::npos) {
                copil->print(std::cout);
            }
        }
    }

    void ordonareVarsta() {
        std::sort(copii.begin(), copii.end(), [](const std::shared_ptr<Copil>& a, const std::shared_ptr<Copil>& b) -> bool {
            return a->getVarsta() > b->getVarsta();
        });
        afisareCopii();
    }

    void ordonareFapteBune() {
        // std::sort(copii.begin(), copii.end(), &comparator);
        std::sort(copii.begin(), copii.end(), [](const std::shared_ptr<Copil>& a, const std::shared_ptr<Copil>& b) -> bool {
            return a->getNumarFapteBune() < b->getNumarFapteBune();
        });
        afisareCopii();
    }

    void adaugareFapteBune(int idCopil, int numarFapteBune) {
        for (auto &copil : copii) {
            if (copil->getIdCopil() == idCopil) {
                copil->setNumarFapteBune(copil->getNumarFapteBune() + numarFapteBune);
                std::vector<std::shared_ptr<Jucarie>> jucarii = copil->getJucarii();
                for (int i = 0 ; i < numarFapteBune ; i++) {
                    std::shared_ptr<Jucarie> tempJucarie;
                    unsigned int option, conditieCitire = 0;
                    while (conditieCitire == 0) {
                        std::cout << "Tip jucarie (1-clasica, 2-educativa, 3-electronica, 4-moderna): ";
                        std::cin >> option;
                        conditieCitire = 1;
                        try {
                            switch (option) {
                                case 1: {
                                    tempJucarie = std::make_shared<JucarieClasica>();
                                    break;
                                }
                                case 2: {
                                    tempJucarie = std::make_shared<JucarieEducativa>();
                                    break;
                                }
                                case 3: {
                                    tempJucarie = std::make_shared<JucarieElectronica>();
                                    break;
                                }
                                case 4: {
                                    tempJucarie = std::make_shared<JucarieModerna>();
                                    break;
                                }
                                default: {
                                    throw option;
                                    break;
                                }
                            }
                            tempJucarie->read(std::cin);
                            jucarii.push_back(tempJucarie);
                        } catch (...) {
                            std::cout << "Eroare: Optiune invalida!\n";
                            conditieCitire = 0;
                        }
                    }
                }
                copil->setJucarii(jucarii);
            }
        }
    }

    void raportJucarii() {
        int numarJucarii = 0;
        int frecventaJucarii[4] = {0, 0, 0, 0};
        for (auto &copil : copii) {
            std::vector<std::shared_ptr<Jucarie>> jucarii = copil->getJucarii();
            numarJucarii += jucarii.size();
            for (auto &jucarie : jucarii) {
                // am verificat mai intai jucaria moderna, pentru ca ar fi fost contorizata la educativa, din cauza mostenirii diamant
                // O jucarie moderna este atat jucarie educativa, cat si jucarie electronica
                if (std::dynamic_pointer_cast<std::shared_ptr<JucarieModerna>>(jucarie)){
                    frecventaJucarii[3]++;
                } else if (std::dynamic_pointer_cast<std::shared_ptr<JucarieClasica>>(jucarie)) {
                    frecventaJucarii[0]++;
                } else if (std::dynamic_pointer_cast<std::shared_ptr<JucarieEducativa>>(jucarie)) {
                    frecventaJucarii[1]++;
                } else if (std::dynamic_pointer_cast<std::shared_ptr<JucarieElectronica>>(jucarie)) {
                    frecventaJucarii[2]++;
                }
            }
        }
        std::cout << "Numarul total de jucarii este " << numarJucarii << " dintre care " << frecventaJucarii[0] << " sunt clasice, "
                  << frecventaJucarii[1] << " sunt educative, " << frecventaJucarii[2] << " sunt electronice, " << frecventaJucarii[3]
                  << " sunt moderne.\n";
    }
};

Meniu* Meniu::instance = nullptr;

void aplicatie() {
    int option = 0;
    Meniu *meniu = Meniu::getInstance();
    do {
        Meniu::meniu();
        std::cout << "Introduceti numarul optiunii: ";
        std::cin >> option;

        switch(option) {
            case 1: {
                meniu->adaugareCopii();
                break;
            }
            case 2: {
                meniu->afisareCopii();
                break;
            }
            case 3: {
                std::string numeCopil;
                std::cout << "Numele copilului cautat este: ";
                std::cin >> numeCopil;
                meniu->cautaCopil(numeCopil);
                break;
            }
            case 4: {
                meniu->ordonareVarsta();
                break;
            }
            case 5: {
                meniu->ordonareFapteBune();
                break;
            }
            case 6: {
                int id, numarFapteBune;
                std::cout << "ID-ul copilui este: ";
                std::cin >> id;
                std::cout << "Numarul de fapte bune adaugate: ";
                std::cin >> numarFapteBune;
                meniu->adaugareFapteBune(id, numarFapteBune);
                break;
            }
            case 7: {
                meniu->raportJucarii();
                break;
            }
            case 0: {
                std::cout << "Iesire din aplicatie...\n";
                break;
            }
            default: {
                std::cout << "Nu exista aceasta optiune!\n";
            }
        }
    } while (option != 0);
}

int main() {
    aplicatie();
    return 0;
}
