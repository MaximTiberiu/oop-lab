#include <iostream>

union MyUnion {
    int a;
    char b;
};

struct MyStruct {
    int a;
    char b;
};

class MyClass {
private:
    int val;

public:
//    MyClass() {
//        std::cout << "Sunt in constructorul default - custom\n";
//    }

    MyClass() = default;

    MyClass(int val) {
        std::cout << "Sunt in constructorul parametrizabil - custom\n";
        this->val = val;
    }

    ~MyClass() {
        std::cout << "Sunt in destructorul default - custom\n";
    }
    int getVal() {
        return val;
    }

    void setVal(int val) {
        this->val = val;
    }

    void hello() {
        std::cout << "hello\n";
    }
};

int main() {
    MyStruct myStruct;
    myStruct.b = 'a';
    std::cout << "b: " << myStruct.b << "\n";
    std::cout << "a: " << myStruct.a << "\n";

    std::cout << "\n\nCLASS\n";
    MyClass myClass;
    myClass.setVal(10);
    std::cout << myClass.getVal() << "\n";
    myClass.hello();

    MyClass myClass1(15);
    std::cout << myClass1.getVal() << "\n";
    return 0;
}
