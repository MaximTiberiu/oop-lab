#include <iostream>
#include <memory>

class DummyObj {
private:
    int x;

public:
    DummyObj(int x) : x(x) {
        std::cout << x << " - CONSTRUCTOR" << std::endl;
    }
    ~DummyObj() {
        std::cout << x << " - DESTRUCTOR" << std::endl;
    }
};

int main() {
    // unique_ptr
    // std::unique_ptr<DummyObj> obj = std::make_unique<DummyObj>(10);
    // {
    //     std::unique_ptr<DummyObj> obj2 = std::make_unique<DummyObj>(20);
    // }

    // shared_ptr
    std::shared_ptr<DummyObj> obj3 = std::make_shared<DummyObj>(30);
    std::cout << obj3.use_count() << std::endl;
    std::shared_ptr<DummyObj> obj4 = obj3;
    std::cout << obj4.use_count() << std::endl;
    {
        std::shared_ptr<DummyObj> obj5 = obj4;
        std::cout << obj5.use_count() << std::endl;
    }
    std::cout << obj3.use_count() << std::endl;

    // weak_ptr
    std::weak_ptr<DummyObj> obj6 = obj3;
    std::cout << obj6.use_count() << std::endl;
    return 0;
}
