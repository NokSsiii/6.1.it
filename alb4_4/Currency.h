#pragma once

class Currency {
protected:
    double amount;
    double exchangeRate;

public:
    Currency(double amount = 0.0, double exchangeRate = 1.0);
    virtual ~Currency() = default;

    virtual void read() = 0;
    virtual void print() const = 0;
    virtual double convertToUAH() const = 0;
};