#include <iostream>
#include <vector>

/*
 PERSOANA (nume, prenume):
    - Angajat (companie)
        - Bugetar (salariu)
        - Muncitor (numarOre, tarifOra)
    - Student (universitatea)
        StudentBursier (bursa)
 */

enum class Type {Persoana, Angajat};

using std::string;
class Persoana{
    // Misu Stefan-Leonard
protected:
    string nume;
    string prenume;
public:
    virtual void afisare(){
        std::cout << "Nume: " << this->nume << std::endl;
        std::cout << "Prenume: " << this->prenume << std::endl;
    }

    virtual Type type() const {
        return Type::Persoana;
    }

    Persoana(const string &nume, const string &prenume) : nume(nume), prenume(prenume) {}
};

class Angajat : public Persoana {
    //Alexandru Norina
protected:
    string companie;
public:
    void afisare() override{
        Persoana::afisare();
        std::cout << "Companie: " << this->companie << std::endl;
    }

    Angajat(const string &nume, const string &prenume, const string &companie) : Persoana(nume, prenume),
                                                                                 companie(companie) {}
};

class Student : public Persoana {
protected:
    string universitate;
public:
    void afisare() override {
        Persoana::afisare();
        std::cout << "Universitate: " << this->universitate << "\n";
    }

    Student(const string &nume, const string &prenume, const string &universitate) : Persoana(nume, prenume),
                                                                                     universitate(universitate) {}
};

class Bugetar : public Angajat {
private:
    unsigned int salariu;
public:
    void afisare() override {
        Angajat::afisare();
        std::cout << "Salariu: " << this->salariu << "\n";
    }

    Bugetar(const string &nume, const string &prenume, const string &companie, unsigned int salariu) : Angajat(nume,
                                                                                                               prenume,
                                                                                                               companie),
                                                                                                       salariu(salariu) {}
};

class Muncitor : public Angajat {
private:
    unsigned int numarOre;
    unsigned int tarifOra;

public:
    void afisare() override {
        Angajat::afisare();
        std::cout << "Numar ore: " << this->numarOre << "\n";
        std::cout << "Tarif ora: " << this->tarifOra << "\n";
    }

    Muncitor(const string &nume, const string &prenume, const string &companie, unsigned int numarOre,
             unsigned int tarifOra) : Angajat(nume, prenume, companie), numarOre(numarOre), tarifOra(tarifOra) {}
};

class StudentBursier : public Student {
private:
    unsigned int bursa;

public:
    void afisare() override {
        Student::afisare();
        std::cout << "Bursa: " << this->bursa << "\n";
    }

    StudentBursier(const string &nume, const string &prenume, const string &universitate, unsigned int bursa) : Student(
            nume, prenume, universitate), bursa(bursa) {}
};

/*
                 PRODUS
             /            \
         PERISABIL      PROMOTIE
              \         /
          PERISBAIL_PROMOTIE
 */

class Produs {
public:
    Produs() {
        std::cout << "Apelare Constructor Produs\n";
    }
};

class Perisabil : virtual public Produs{
public:
    Perisabil() {
        std::cout << "Apelare Constructor Perisabil\n";
    }
};

class Promotie : virtual public Produs{
public:
    Promotie() {
        std::cout << "Apelare Constructor Promotie\n";
    }
};

class PerisabilPromotie : public Perisabil, public Promotie {
public:
    PerisabilPromotie() {
        std::cout << "Apelare Constructor PersiabilPromotie\n";
    }
};

int main() {
//    std::cout << "Persoana\n";
    Persoana *p_persoana = new Persoana("Mihai" , "Popescu");
//    p_persoana->afisare();

//    std::cout << "\nAngajat\n";
    Persoana *p_angajat = new Angajat("Popa", "Andrei", "ABC");
//    p_angajat->afisare();

//    std::cout << "\nBugetar\n";
    Persoana *p_bugetar = new Bugetar("Popa", "Andrei", "ABC", 6790);
//    p_bugetar->afisare();

//    std::cout << "\nMuncitor\n";
    Persoana *p_muncitor = new Muncitor("Popa", "Andrei", "ABC", 20, 150);
//    p_muncitor->afisare();

//    std::cout << "\nStudent\n";
    Persoana *p_student = new Student("Mihai" , "Popescu", "UniBuc");
//    p_student->afisare();

//    std::cout << "\nStudentBursier\n";
    Persoana *p_studentBursier = new StudentBursier("Mihai" , "Popescu", "UniBuc", 800);
    Persoana *p_studentBursier1 = new StudentBursier("Mihai" , "Popescu1", "UniBuc", 800);
    Persoana *p_studentBursier2 = new StudentBursier("Mihai" , "Popescu2", "UniBuc", 800);
//    p_studentBursier->afisare();

    std::vector<Persoana*> persoane;
    persoane.push_back(p_persoana);
    persoane.push_back(p_bugetar);
    persoane.push_back(p_angajat);
    persoane.push_back(p_muncitor);
    persoane.push_back(p_student);
    persoane.push_back(p_studentBursier);
    persoane.push_back(p_studentBursier1);
    persoane.push_back(p_studentBursier2);

//    for (auto &persoana : persoane) {
//        std::cout << "\n\n";
//        persoana->afisare();
//    }

//    std::cout << "\nAfisare Bugetari:\n";
//    for (auto &persoana : persoane) {
//        if(typeid(*persoana) == typeid(Bugetar))
//            persoana->afisare();
//    }
//
//    std::cout << "\nAfisare Studenti Bursieri:\n";
//    for (auto &persoana : persoane) {
//        if(dynamic_cast<StudentBursier*>(persoana))
//            persoana->afisare();
//    }

    PerisabilPromotie *pp = new PerisabilPromotie();


    return 0;
}
