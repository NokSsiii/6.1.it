#pragma once
#include <iostream>
#include <string>

using namespace std;

class Pair
{
private:
    double a, b;

public:
    Pair(const double x = 1.0, const double y = 1.0);
    Pair(const Pair& r);
    virtual ~Pair();

    double getA() const { return a; }
    double getB() const { return b; }

    void setA(const double value);
    void setB(const double value);

    double product() const;

    operator string() const;
    friend ostream& operator << (ostream& out, const Pair& r);
    friend istream& operator >> (istream& in, Pair& r);
};