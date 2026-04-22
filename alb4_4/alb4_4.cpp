#include <iostream>
#include <vector>
#include <typeinfo>
#include "Dollar.h"
#include "Euro.h"

void displayCurrencyInfo(Currency& currency) {
    std::cout << "--- Reference Call Demonstration ---" << std::endl;
    std::cout << "Real object type: " << typeid(currency).name() << std::endl;

    std::cout << "Currency data: ";
    currency.print();

    std::cout << "\nUAH Equivalent: " << currency.convertToUAH() << " UAH\n";
    std::cout << "------------------------------------------\n" << std::endl;
}

int main() {
    Dollar myDollar(150.0);
    Euro myEuro(100.0);

    displayCurrencyInfo(myDollar);
    displayCurrencyInfo(myEuro);

    std::cout << "=== Pointer Array Demonstration ===" << std::endl;

    std::vector<Currency*> wallet;

    Dollar dynamicDollar;
    Euro dynamicEuro;

    std::cout << "Data input for dynamic Dollar:" << std::endl;
    dynamicDollar.read();

    std::cout << "Data input for dynamic Euro:" << std::endl;
    dynamicEuro.read();

    wallet.push_back(&dynamicDollar);
    wallet.push_back(&dynamicEuro);

    std::cout << "\nWallet content:" << std::endl;
    double totalUAH = 0;

    for (Currency* c : wallet) {
        std::cout << "- Type: " << typeid(*c).name() << " | ";
        c->print();
        double converted = c->convertToUAH();
        std::cout << " -> " << converted << " UAH" << std::endl;
        totalUAH += converted;
    }

    std::cout << "\nTotal amount in UAH: " << totalUAH << " UAH" << std::endl;

    return 0;
}