#include <iostream>
#include <cmath>
#include <vector>

// Sa se defineasca o clasa Punct care stocheaza coodronatele x,y (x,y - numere intregi).
// Sa se defineasca o clasa Dreptunghi care sa calculeze aria si perimetrul acestuia.

class Punct{

private:
    int x, y;

public:

    Punct() = default;

    Punct(int x, int y) : x(x) {
        this->y = y;
    }

    int getX() const {
        return x;
    }

    void setX(int x) {
        Punct::x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        Punct::y = y;
    }
};

class Dreptunghi{
private:
    Punct p1, p2;
public:
    Dreptunghi(int x1, int x2, int y1, int y2) {
        p1.setX(x1);
        p1.setY(y1);
        p2.setX(x2);
        p2.setY(y2);
    }

    Dreptunghi(Punct p1, Punct p2) {
        this->p1 = p1;
        this->p2 = p2;
    }

    int perimetru() {
        int lungime = abs(p2.getX() - p1.getX());
        int latime = abs(p2.getY() - p1.getY());
        return 2 * (lungime + latime);
    }

    float arie(){
        int lungime = abs(p2.getX() - p1.getX());
        int latime = abs(p2.getY() - p1.getY());
        return lungime * latime;
    }
};

int main() {
    // Punct p1(4, 4), p2(2, 2);
    // Dreptunghi d(p1, p2);
    // std::cout << d.arie() << "\n" << d.perimetru() << "\n";
    // Dreptunghi d1(4, 2, 4, 2);
    // std::cout << d1.arie() << "\n" << d1.perimetru();
    
    int n=5;

    std::vector<Punct> puncte;
    for (int i=0; i<5; i++){
        int x, y;
        std::cin >> x >> y;
        Punct temp(x, y);
        puncte.push_back(temp);
    }

    for (int i = 0; i < 5; i++) {
        std::cout<< puncte[i].getX() << " " << puncte[i].getY() << "\n";
    }
    return 0;
}
