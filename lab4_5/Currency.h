#pragma once
#include "ICurrency.h"

class Currency : public ICurrency {
protected:
    double amount;
    double exchangeRate;

public:
    Currency(double amount = 0.0, double exchangeRate = 1.0);
    virtual ~Currency() = default;
};