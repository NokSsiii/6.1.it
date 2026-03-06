#pragma once
#include <string>

class Pair
{
private:
    double a;
    double b;

public:
    // Access methods (getters)
    double getA() const { return a; }
    double getB() const { return b; }

    // Modifiers (setters) with validation
    void setA(double a);
    void setB(double b);

    // Specific method for Variant 24
    double Product() const;

    // Mandatory methods
    void Init(double a, double b);
    void Read();
    void Display() const;
    std::string toString() const;
};