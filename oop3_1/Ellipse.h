#pragma once
#include "Pair.h"

class Ellipse : public Pair
{
public:
    Ellipse(const double x = 1.0, const double y = 1.0);
    Ellipse(const Ellipse& r);
    ~Ellipse();

    double perimeter() const;
    double area() const;

    operator string() const;
    friend ostream& operator << (ostream& out, const Ellipse& r);
    friend istream& operator >> (istream& in, Ellipse& r);
};