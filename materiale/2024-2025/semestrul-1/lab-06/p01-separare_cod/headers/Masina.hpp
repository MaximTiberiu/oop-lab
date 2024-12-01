//
// Created by Tiberiu on 11/13/2024.
//

// #pragma once
#ifndef P01_MASINA_HPP
#define P01_MASINA_HPP

#include <string>

class Masina {
private:
    int anFabricatie;
    std::string brand;
    std::string model;

public:
    Masina() = default;
    ~Masina() = default;
    Masina(int anFabricatie, const std::string &brand, const std::string &model);

    int getAnFabricatie() const;
    void setAnFabricatie(int anFabricatie);

    const std::string &getBrand() const;
    void setBrand(const std::string &brand);

    const std::string &getModel() const;
    void setModel(const std::string &model);

    void printInfo();
};


#endif //P01_MASINA_HPP
