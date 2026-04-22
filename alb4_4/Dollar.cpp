#include "Dollar.h"
#include <iostream>

Dollar::Dollar(double amount, double exchangeRate)
    : Currency(amount, exchangeRate) {
}

void Dollar::read() {
    std::cout << "Enter amount in USD: ";
    std::cin >> amount;
}

void Dollar::print() const {
    std::cout << amount << " USD (Rate: " << exchangeRate << " UAH)";
}

double Dollar::convertToUAH() const {
    return amount * exchangeRate;
}