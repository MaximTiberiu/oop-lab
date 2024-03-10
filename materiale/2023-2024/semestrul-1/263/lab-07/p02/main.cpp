#include <iostream>

/*
 * IF1: -print1, -print2
 * IF2: -print1, print2, print3
 *
 * A(IF1)
 * B(IF2)
 */

class IF1 {
public:
    virtual void print1() = 0;
    virtual void print2() = 0;
};

class IF2 : public IF1{
public:
    void print1() override = 0;
    void print2() override = 0;
    virtual void print3() = 0;
};

class A : public IF2 {
public:
    void print3() override {

    }
};

class Fruct {
protected:
    std::string numeFruct;

public:
    explicit Fruct(const std::string &numeFruct) : numeFruct(numeFruct) {}
    virtual void printFruct() = 0;
};

class Mar : public Fruct {
private:
    std::string culoareFruct;

public:
    Mar(const std::string &numeFruct, const std::string &culoareFruct) : Fruct(numeFruct), culoareFruct(culoareFruct) {}
    void printFruct() {
        std::cout << "Acesta este un/o " << this->numeFruct << "\n";
    }
};

class MarGolden {

};

int main() {
    Fruct *fruct = new Mar("mar", "rosie");
    fruct->printFruct();
    return 0;
}
