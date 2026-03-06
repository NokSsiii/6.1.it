#include "Pair.h"
#include <iostream>
#include <sstream>

using namespace std;

void Pair::setA(double a)
{
    // Validation: semi-axis must be greater than 0
    if (a > 0) {
        this->a = a;
    }
    else {
        cout << "[Error] Value must be > 0. Defaulting to 1.0." << endl;
        this->a = 1.0;
    }
}

void Pair::setB(double b)
{
    if (b > 0) {
        this->b = b;
    }
    else {
        cout << "[Error] Value must be > 0. Defaulting to 1.0." << endl;
        this->b = 1.0;
    }
}

double Pair::Product() const
{
    return a * b;
}

void Pair::Init(double a, double b)
{
    // Using setters to prevent bypassing the validation
    setA(a);
    setB(b);
}

void Pair::Read()
{
    double a_val, b_val;
    cout << "Enter the first number (semi-axis a): "; cin >> a_val;
    cout << "Enter the second number (semi-axis b): "; cin >> b_val;
    Init(a_val, b_val);
}

void Pair::Display() const
{
    cout << "a = " << a << ", b = " << b << endl;
}

string Pair::toString() const
{
    stringstream ss;
    ss << "(" << a << ", " << b << ")";
    return ss.str();
}