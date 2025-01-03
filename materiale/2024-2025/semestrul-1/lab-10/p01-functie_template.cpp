#include <iostream>
#include <vector>

// int getMin(int a, int b) {
//     if (a < b) {
//         std::cout << "a ";
//         return a;
//     }
//     std::cout << "b ";
//     return b;
// }
//
// float getMin(float a, float b) {
//     if (a < b) {
//         std::cout << "a ";
//         return a;
//     }
//     std::cout << "b ";
//     return b;
// }

template<typename T>
T getMin(T a, T b) {
    if (a < b) {
        std::cout << "a ";
        return a;
    }
    std::cout << "b ";
    return b;
}

int main() {
    std::cout << getMin<int>(4, 5) << "\n";
    std::cout << getMin<float>(3.3, 3.7) << "\n";
    return 0;
}
