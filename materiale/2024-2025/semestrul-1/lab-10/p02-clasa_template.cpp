#include <iostream>

template <typename T, typename U, int N>
class sum {
private:
    T val1, val2;
    U val3;
    T val4[N];

public:
    sum(T val1, T val2) : val1(val1), val2(val2) {}

    [[nodiscard]] T getVal1() const {
        return val1;
    }

    [[nodiscard]] T getVal2() const {
        return val2;
    }
};

int main() {
    sum<int, std::string, 5> *s = new sum<int, std::string, 5>(1, 2);
    return 0;
}
