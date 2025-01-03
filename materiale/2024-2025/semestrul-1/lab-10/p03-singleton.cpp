#include <iostream>

class Singleton {
private:
    Singleton() {
        std::cout << "Singleton constructor" << std::endl;
    }

    static Singleton* instance;

public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
            return instance;
        }
        std::cout << "Deja exist!\n";
        return instance;
    }

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};

Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* singleton = Singleton::getInstance();
    Singleton* singleton2 = Singleton::getInstance();
    return 0;
}
