

#ifndef P01_FRUCT_HPP
#define P01_FRUCT_HPP


#include <string>


class Fruct {
private:
    std::string numeFruct;
    double greutate;

public:
    Fruct();

    Fruct(const std::string &numeFruct, double greutate);

    const std::string &getNumeFruct() const;
    void setNumeFruct(const std::string &greutate);

    double getGreutate() const;
    void setGreutate(double greutate);

    void print();

};


#endif //P01_FRUCT_HPP
