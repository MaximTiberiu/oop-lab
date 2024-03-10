#include <iostream>
#include <memory>

class Obj {
private:
    std::string name;
public:
    Obj() {
        std::cout << "CONSTRUCTOR\n";
    }

    explicit Obj(const std::string &name) : name(name) {
        std::cout << "CONSTRUCTOR\n";
    }

    ~Obj() {
        std::cout << "DESTRUCTOR\n";
    }

    void printObj() {
        std::cout << this->name << "\n";
    }
};

int main() {

    // unique_ptr
//    std::cout << "Before Context\n";
//    {
//        std::unique_ptr<Obj> obj = std::make_unique<Obj>("obj1");
//        std::unique_ptr<Obj> obj1 = obj;
//    }
//    std::cout << "After Context\n";
//    obj->printObj();

    // shared_ptr
    std::shared_ptr<Obj> obj = std::make_shared<Obj>("obj1");
    std::shared_ptr<Obj> obj1 = obj;

    std::cout << obj.use_count() << "\n---------------\n";

    // weak_ptr
    std::shared_ptr<Obj> obj2 = std::make_shared<Obj>("obj2");
    std::weak_ptr<Obj> obj3 = obj2;

    std::cout << obj2.use_count() << "\n";
    return 0;
}
