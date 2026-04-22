#include "Euro.h"
#include <iostream>

Euro::Euro(double amount, double exchangeRate)
    : Currency(amount, exchangeRate) {
}

void Euro::read() {
    std::cout << "Enter amount in EUR: ";
    std::cin >> amount;
}

void Euro::print() const {
    std::cout << amount << " EUR (Rate: " << exchangeRate << " UAH)";
}

double Euro::convertToUAH() const {
    return amount * exchangeRate;
}