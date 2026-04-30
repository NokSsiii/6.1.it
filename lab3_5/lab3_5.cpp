#include "Money.h"

int main() {
    Money m1(4, 5);
    Money m2(3, 2);
    Money m3 = m1 + m2;
    std::cout << "M1: " << m1 << std::endl;
    std::cout << "M2: " << m2 << std::endl;
    std::cout << "Sum: " << m3 << std::endl;
    return 0;
}