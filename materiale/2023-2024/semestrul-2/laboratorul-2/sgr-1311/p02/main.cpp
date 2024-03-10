#include <iostream>

// Implementati o aplicatie care stocheaza date despre studenti (nume, grupa).

class Student{
private:
    int grupa;
    std::string nume;
public:
    Student(int grupa, std::string nume)
        : grupa(grupa) {
        this->nume = nume;
    }

    ~Student() = default;

    void setGrupa(int grupa)
    {
        this->grupa = grupa;
    }
    int getGrupa()
    {
        return this->grupa;
    }

    void setNume(std::string nume)
    {
        this->nume = nume;
    }
    std::string getNume()
    {
        return this->nume;
    }
};

int main() {
    Student maria(131, "Popa Maria");
    Student ion(131, "Ion Ion");
    std::cout << maria.getGrupa() << " " << maria.getNume() << "\n";
    std::cout << ion.getGrupa() << " " << ion.getNume() << "\n";
    return 0;
}
