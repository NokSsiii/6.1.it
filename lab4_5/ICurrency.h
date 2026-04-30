#pragma once

class ICurrency {
public:
    virtual void read() = 0;
    virtual void print() const = 0;
    virtual double convertToUAH() const = 0;

    virtual ~ICurrency() = default;
};