#include <iostream>

struct MyStruct {
    int val;
};

class MyClass {
private:
    int val;

public:
    MyClass() {
        std::cout << "Sunt in constructorul default!\n";
    }
    ~MyClass() {
        std::cout << "Sunt in destructor!\n";
    }

    MyClass(int val) {
        std::cout << "Sunt in constructor parametrizabil!\n";
        this->val = val;
    }
    void setVal(int val) {
        this->val = val;
    }

    int getVal() {
        return this->val;
    }
};

int main() {
//    std::cout << "STRUCT\n";
//    MyStruct myStruct;
//    myStruct.val = 10;
//    std::cout << myStruct.val << "\n";

    std::cout << "CLASS\n";
    MyClass myClass(10);
    MyClass myClass1;
//    myClass.setVal(10);
    std::cout << myClass.getVal() << "\n";
    return 0;
}
