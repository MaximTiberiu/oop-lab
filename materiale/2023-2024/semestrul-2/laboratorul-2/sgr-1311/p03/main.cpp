#include <iostream>

// Implementati clasa Dreptunghi care sa calculeze aria si perimetrul acestuia.

class Dreptunghi {
private:
    float lungime;
    float latime;

public:
    Dreptunghi(float lungime, float latime) : lungime(lungime), latime(latime) {}

    float getLungime() const {
        return lungime;
    }

    void setLungime(float lungime) {
        Dreptunghi::lungime = lungime;
    }

    float getLatime() const {
        return latime;
    }

    void setLatime(float latime) {
        Dreptunghi::latime = latime;
    }

    float arie() {
        return lungime * latime;
    }

    float perimetru() {
        return 2 * (lungime + latime);
    }
};

int main() {
    Dreptunghi dreptunghi(4.0, 3.0);

    std::cout << "Arie: " << dreptunghi.arie() << ", Perimetru: " << dreptunghi.perimetru() << std::endl;
    return 0;
}
