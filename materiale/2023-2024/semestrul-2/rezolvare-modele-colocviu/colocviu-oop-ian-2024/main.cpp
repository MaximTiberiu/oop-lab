// tinyurl.com/colocviu-poo-ian-2024
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

class Proba {
public:
    [[nodiscard]] virtual int calculareNota() const = 0;
    virtual ~Proba() = default;
};

class Sprint : public Proba {
private:
    int t{};

public:
    Sprint() = default;
    explicit Sprint(int t) : t(t) {}
    ~Sprint() override = default;

    [[nodiscard]] int calculareNota() const override {
        if (t < 10) {
            return 10;
        }
        return 90 / t;
    }
};

class Cross : public Proba{
private:
    int t{};

public:
    Cross() = default;
    explicit Cross(int t) : t(t) {}
    ~Cross() override = default;

    [[nodiscard]] int calculareNota()  const override{
        if (t < 30) {
            return 10;
        }
        return 120 / t;
    }
};

class SemiMaraton : public Proba {
private:
    int d{};

public:
    SemiMaraton() = default;
    explicit SemiMaraton(int d) : d(d) {}
    ~SemiMaraton() override = default;

    [[nodiscard]] int calculareNota() const override {
        if (d > 50) {
            return 10;
        }
        return d / 5;
    }
};

class Maraton : public Proba {
private:
    int d{};

public:
    Maraton() = default;
    explicit Maraton(int d) : d(d) {}
    ~Maraton() override = default;

    [[nodiscard]] int calculareNota() const override {
        if (d > 50){
            return 10;
        }
        return d / 5;
    }
};

class Candidat {
private:
    std::string nume;
    std::string prenume;
    std::string dataNasterii;
    std::shared_ptr<Proba> tipProba;

public:
    Candidat() = default;
    Candidat(const std::string& nume, const std::string& prenume, const std::string& dataNasterii, const std::shared_ptr<Proba>& tipProba)
            : nume(nume), prenume(prenume), dataNasterii(dataNasterii), tipProba(tipProba) {}
    ~Candidat() = default;

    [[nodiscard]] int nota() const {
        return tipProba->calculareNota();
    }

    friend std::ostream& operator<<(std::ostream &out, std::shared_ptr<Candidat> &candidat) {
        out << candidat->nota() << " - " << candidat->nume << " " << candidat->prenume << " " << candidat->dataNasterii;
        return out;
    }
};

class Competitie {
    std::vector<std::shared_ptr<Candidat>> candidati;
    static const std::string parola;

    void inscrie() {
        std::cout << "nume, prenume, data nasterii: ";
        std::string nume, prenume, data_nasterii;
        std::cin >> nume >> prenume >> data_nasterii;

        int tip_proba;
        std::cout << "\nproba: sprint(1), cros(2), semimaraton(3), maraton(4) - ";
        std::cin >> tip_proba;

        std::shared_ptr<Proba> tipProba;
        if (tip_proba == 1) {
            int t;
            std::cout << "t: ";
            std::cin >> t;
            tipProba = std::make_shared<Sprint>(t);
        } else if(tip_proba == 2) {
            int t;
            std::cout << "t: ";
            std::cin >> t;
            tipProba = std::make_shared<Cross>(t);
        } else if(tip_proba == 3) {
            int d;
            std::cout << "d: ";
            std::cin >> d;
            tipProba = std::make_shared<SemiMaraton>(d);
        } else if(tip_proba == 4) {
            int d;
            std::cout << "d: ";
            std::cin >> d;
            tipProba = std::make_shared<Maraton>(d);
        }
        candidati.emplace_back(std::make_shared<Candidat>(nume, prenume, data_nasterii, tipProba));
    }

    void afiseaza_clasament() {
        size_t max_candidati = 500;
        for(int i = 0; i < std::min(max_candidati, candidati.size()); i++) {
            std::cout << i + 1 << ". " << candidati[i] << "\n";
        }
    }

public:
    explicit Competitie() : candidati{std::vector<std::shared_ptr<Candidat>>()} {}

    void incheie_inscrieri() {
        std::cout << "Parola este: ";
        std::string inputParola;
        std::cin >> inputParola;

        if (inputParola == Competitie::parola) {
            afiseaza_clasament();
        } else {
            std::cout << "Parola incorecta\n";
        }
    }

    void start() {
        int n;
        std::cout << "Numar candidati: ";
        std::cin >> n;
        for(int i = 0; i < n; i++) {
            inscrie();
        }

        std::sort(candidati.begin(), candidati.end(), [](const std::shared_ptr<Candidat>& c1, const std::shared_ptr<Candidat>& c2) {
            return c1->nota() > c2->nota();
        });
    }
};

const std::string Competitie::parola = "secr3t";

int main()
{
    Competitie comp;
    comp.start();
    comp.incheie_inscrieri();
    return 0;
}