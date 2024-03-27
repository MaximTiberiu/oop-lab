
#ifndef P02_FURTUNA_HPP
#define P02_FURTUNA_HPP

#include "Meteo.hpp"

class Furtuna : public Meteo {
private:
    int cantitate;

public:
    Furtuna() = default;
    ~Furtuna() = default;
    Furtuna(const std::string &fenomen, int cantitate);

    void infoFenomen() override;
};


#endif //P02_FURTUNA_HPP
