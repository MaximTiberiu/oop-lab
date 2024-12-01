#include <iostream>

class MyException : public std::exception {
private:
    std::string message;
public:
    MyException(std::string message) : message(message) {}
    virtual const char* what() const throw() {
        return message.c_str();
    }
};

int main() {
    int a = 20, b = 0;
    try {
        if (b == 0) {
            throw std::runtime_error("Impartirea la zero este ilegala!\n");
        }

        if (a == 10 || b == 10) {
            throw a;
        }

        if (a == 20 && b == 1) {
            throw 'c';
        }

        std::cout << a / b;
    } catch (std::runtime_error& e) {
        std::cout << e.what();
    } catch (int x) {
        std::cout << "Valoarea " << x << " nu este valida!\n";
    } catch (...) {
        std::cout << "Alt caz ilegal!\n";
    }

    try {
        try {
            throw 100;
        } catch (int x) {
            std::cout << "Valoarea " << x << " nu este valida!\n";
            throw MyException("Am primit un int, si nu e ok!\n");
        }
    } catch (MyException& e) {
        std::cout << e.what();
    }
    return 0;
}
