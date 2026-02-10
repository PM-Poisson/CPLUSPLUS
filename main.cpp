#include <iostream>
#include "utils.hpp"

int main() {
    int a = 10, b = 20;
    std::cout << "Valeurs initiales: a = " << a << ", b = " << b << "\n";
    std::cout << "Max(a, b) = " << max(a, b) << "\n";
    std::cout << "Min(a, b) = " << min(a, b) << "\n";
    swap(a, b);std::cout << "Après swap: a = " << a << ", b = " << b << "\n";
    return 0;
}