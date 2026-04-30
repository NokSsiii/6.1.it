#pragma once
#include "Currency.h"

class Dollar : public Currency {
public:
    Dollar(double amount = 0.0, double exchangeRate = 39.5);

    void read() override;
    void print() const override;
    double convertToUAH() const override;
};