#include <iostream>

void addNumber(int x) {
    int res = 0;
    for (int i = 1; i <= x; i++) {
        res += i;
    }
    std::cout << res << std::endl;
}

void addNumberStatic(int x) {
    static int res = 0;
    for (int i = 1; i <= x; i++) {
        res += i;
    }
    std::cout << res << std::endl;
}

class Obj {
private:
    static int ID;
    int local_id = ++ID;
    std::string name;

public:
    Obj(const std::string& name) : name(name) {this->ID = ++ID;}
    static int getID() {
        return ID;
    }
};

int Obj::ID = 0;

class MyException : public std::exception {
private:
    std::string message;
public:
    MyException() {
        this->message = "Error";
    }
    MyException(const std::string& message) : message(message) {}
    const char* what() {
        return message.c_str();
    }
};

int main() {
    // addNumber(1);
    // addNumberStatic(1);
    // std::cout << "------------\n";
    // addNumber(2);
    // addNumberStatic(2);
    // std::cout << "------------\n";
    // addNumber(5);
    // addNumberStatic(5);

    // Obj telecomanda("telecomanda");
    // std::cout << Obj::getID() << "\n";
    //
    // Obj PC("PC");
    // std::cout << Obj::getID() << "\n";

    try {
        int a = 10, b = 10;
        if (b == 0) {
            throw std::runtime_error("Impartirea la zero este ilegala!");
        }

        if (a < 10) {
            throw a;
        }

        if (b < 10) {
            throw MyException("Valoarea lui b trebui sa fie de minim doua cifre!");
        }

        if (a == 10 && b == 10) {
            throw 'c';
        }

        std::cout << a / b << std::endl;
    } catch (std::runtime_error e) {
        std::cerr << e.what() << std::endl;
    } catch (int x) {
        std::cerr << "Valoarea pentru variabila a trebuie sa fie de minim doua cifre. Valoare curenta = " << x << std::endl;
    } catch (MyException e) {
        std::cerr << e.what() << std::endl;
    } catch (...) {
        std::cerr << "Error!" << std::endl;
    }

    try {
        try {
            throw MyException("Exceptie in try imbricat");
        } catch (MyException e) {
            throw e;
        }
    } catch (MyException e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
