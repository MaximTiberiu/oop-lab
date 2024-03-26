#ifndef P02_ANIMAL_HPP
#define P02_ANIMAL_HPP

#include <string>

class Animal {
protected:
    std::string nume;

public:
    Animal() = default;
    explicit Animal(const std::string &nume);
    ~Animal() = default;

    virtual void sound() = 0;
    virtual void test();
};


#endif //P02_ANIMAL_HPP
