#include "Ellipse.h"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

const double PI = 3.141592653589793;

void Ellipse::Pair::setA(double a)
{
    if (a > 0) {
        this->a = a;
    }
    else {
        cout << "[Warning] Semi-axis 'a' must be > 0. Defaulting to 1.0." << endl;
        this->a = 1.0;
    }
}

void Ellipse::Pair::setB(double b)
{
    if (b > 0) {
        this->b = b;
    }
    else {
        cout << "[Warning] Semi-axis 'b' must be > 0. Defaulting to 1.0." << endl;
        this->b = 1.0;
    }
}

double Ellipse::Pair::Product() const
{
    return a * b;
}

void Ellipse::Pair::Init(double a, double b)
{
    setA(a);
    setB(b);
}

void Ellipse::Pair::Display() const
{
    cout << "a = " << a << ", b = " << b << endl;
}

void Ellipse::Pair::Read()
{
    double a_val, b_val;
    cout << "Enter semi-axis a: "; cin >> a_val;
    cout << "Enter semi-axis b: "; cin >> b_val;
    Init(a_val, b_val);
}

string Ellipse::Pair::toString() const
{
    stringstream ss;
    ss << "(" << a << ", " << b << ")";
    return ss.str();
}

double Ellipse::Perimeter() const
{
    double a = semiAxes.getA();
    double b = semiAxes.getB();
    return 2 * PI * sqrt((a * a + b * b) / 2.0);
}

double Ellipse::Area() const
{
    return PI * semiAxes.Product();
}

void Ellipse::Init(Ellipse::Pair axes)
{
    setSemiAxes(axes);
}

void Ellipse::Display() const
{
    cout << "\nEllipse parameters:" << endl;
    cout << "Semi-axes: " << endl;
    semiAxes.Display();
    cout << "Perimeter: " << Perimeter() << endl;
    cout << "Area: " << Area() << endl;
}

void Ellipse::Read()
{
    Ellipse::Pair p;
    cout << "\n--- Enter Ellipse Data ---" << endl;
    p.Read();
    Init(p);
}

string Ellipse::toString() const
{
    stringstream ss;
    ss << "Ellipse parameters: " << semiAxes.toString();
    return ss.str();
}