/*
 * Nume fisier: Masina.hpp
 * Autor: Tiberiu Maxim
 * Data: 13/11/2023
 * Descriere:
 *
 */

#ifndef P01_MASINA_HPP
#define P01_MASINA_HPP


#include <string>

class Masina {
private:
    std::string marca;

public:
    explicit Masina(const std::string &marca);

    const std::string &getMarca() const;

    /// \brief Setter pentru atributul marca
    /// \param marca Marca masinii
    void setMarca(const std::string &marca);

    void print();

};


#endif //P01_MASINA_HPP
