#include <iostream>

/*
 *       A
 *     /  \
 *    B    C
 *     \  /
 *       D
 */

class A {
public:
    A() {
        std::cout << "A()" << std::endl;
    }

    void display() {
        std::cout << "A::display()" << std::endl;
    }

    ~A() {
        std::cout << "~A()" << std::endl;
    }
};

class B : virtual public A {
public:
    B() {
        std::cout << "B()" << std::endl;
    }

    void display() {
        std::cout << "B::display()" << std::endl;
    }

    ~B() {
        std::cout << "~B()" << std::endl;
    }
};

class C : virtual public A{
public:
    C() {
        std::cout << "C()" << std::endl;
    }

    void display() {
        std::cout << "C::display()" << std::endl;
    }

    ~C() {
        std::cout << "~C()" << std::endl;
    }
};

class D : public B, public C{
public:
    D() {
        std::cout << "D()" << std::endl;
    }

    void display() {
        B::display();
    }

    ~D() {
        std::cout << "~D()" << std::endl;
    }
};

int main() {
    D *d = new D;
    d->display();
    delete d;
    return 0;
}
