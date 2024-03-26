#ifndef P02_PISICA_HPP
#define P02_PISICA_HPP

#include "Animal.hpp"

class Pisica : public Animal {
public:
    explicit Pisica(const std::string &nume);

    void sound() override;
};


#endif //P02_PISICA_HPP
