#ifndef P02_METEO_HPP
#define P02_METEO_HPP

#include <string>

class Meteo {
protected:
    std::string fenomen;

public:
    Meteo() = default;
    virtual ~Meteo() = default;
    explicit Meteo(const std::string &fenomen);
    virtual void infoFenomen() = 0;
};


#endif //P02_METEO_HPP
