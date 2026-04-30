#include <iostream>
#include <vector>
#include <typeinfo>
#include "Dollar.h"
#include "Euro.h"

void displayCurrencyInfo(ICurrency& currency) {
    std::cout << "--- Object Info ---" << std::endl;

    std::cout << "Real type: " << typeid(currency).name() << std::endl;

    std::cout << "Data: ";
    currency.print();

    std::cout << "\nUAH: " << currency.convertToUAH() << std::endl;
    std::cout << "----------------------\n" << std::endl;
}

int main() {
    Dollar d(150);
    Euro e(100);

    displayCurrencyInfo(d);
    displayCurrencyInfo(e);

    std::vector<ICurrency*> wallet;

    Dollar d2;
    Euro e2;

    std::cout << "Input Dollar:\n";
    d2.read();

    std::cout << "Input Euro:\n";
    e2.read();

    wallet.push_back(&d2);
    wallet.push_back(&e2);

    double total = 0;

    std::cout << "\nWallet:\n";
    for (auto c : wallet) {
        std::cout << "Type: " << typeid(*c).name() << " | ";
        c->print();

        double val = c->convertToUAH();
        std::cout << " -> " << val << " UAH\n";

        total += val;
    }

    std::cout << "\nTotal: " << total << " UAH\n";

    return 0;
}