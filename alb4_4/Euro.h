#pragma once
#include "Currency.h"

class Euro : public Currency {
public:
    Euro(double amount = 0.0, double exchangeRate = 42.8);

    void read() override;
    void print() const override;
    double convertToUAH() const override;
};