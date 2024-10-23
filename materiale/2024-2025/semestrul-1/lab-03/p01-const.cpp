#include <iostream>

class Student {
private:
    std::string nume_student;
    std::string prenume_student;
    unsigned int grupa;

public:
    Student() = default;
    ~Student() = default;

    Student(unsigned int grupa) {
        this->nume_student = "Nume";
        this->prenume_student = "Prenume";
        this->grupa = grupa;
    }

    Student(const std::string& nume_student, const std::string& prenume_student, unsigned int grupa) {
        this->nume_student = nume_student;
        this->prenume_student = prenume_student;
        this->grupa = grupa;
    }

    const std::string &getNumeStudent() const {
        return nume_student;
    }

    void setNumeStudent(const std::string &numeStudent) {
        nume_student = numeStudent;
    }

    const std::string &getPrenumeStudent() const {
        return prenume_student;
    }

    void setPrenumeStudent(const std::string &prenumeStudent) {
        prenume_student = prenumeStudent;
    }

    unsigned int getGrupa() const {
        return grupa;
    }

    void setGrupa(unsigned int grupa) {
        Student::grupa = grupa;
    }

    void print_info() const {
        std::cout << "Studentul " << prenume_student << " " << nume_student << " de la grupa " << grupa << ".\n";
    }
};

int main() {
    const Student student1("Maxim", "Tiberiu", 508);
    student1.print_info();
    Student *student2 = new Student(508);
    student2->print_info();
    return 0;
}
