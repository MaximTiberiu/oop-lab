#ifndef P02_CAINE_HPP
#define P02_CAINE_HPP

#include "Animal.hpp"

class Caine : public Animal {
public:
    explicit Caine(const std::string &nume);

    void sound() override;

};


#endif //P02_CAINE_HPP
