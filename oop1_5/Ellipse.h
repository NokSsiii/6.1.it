#pragma once
#include "Pair.h"
#include <string>

class Ellipse
{
private:
    Pair semiAxes; // Composition: ellipse contains a pair of numbers

public:
    // Access methods
    Pair getSemiAxes() const { return semiAxes; }
    void setSemiAxes(Pair axes);

    // Specific methods for Variant 24
    double Perimeter() const;
    double Area() const;

    // Mandatory methods
    void Init(Pair axes);
    void Read();
    void Display() const;
    std::string toString() const;
};