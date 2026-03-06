#include "Ellipse.h"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

const double PI = 3.141592653589793;

void Ellipse::setSemiAxes(Pair axes)
{
    this->semiAxes = axes;
}

double Ellipse::Perimeter() const
{
    double a = semiAxes.getA();
    double b = semiAxes.getB();
    // Using the approximate formula for the perimeter of an ellipse
    return 2 * PI * sqrt((a * a + b * b) / 2.0);
}

double Ellipse::Area() const
{
    // Delegating the product calculation (a * b) to the Pair class
    return PI * semiAxes.Product();
}

void Ellipse::Init(Pair axes)
{
    setSemiAxes(axes);
}

void Ellipse::Read()
{
    Pair p;
    cout << "\n--- Entering data for the Ellipse ---" << endl;
    p.Read(); // Delegation
    Init(p);
}

void Ellipse::Display() const
{
    cout << "\nEllipse parameters:" << endl;
    semiAxes.Display(); // Delegation
    cout << "Perimeter: " << Perimeter() << endl;
    cout << "Area: " << Area() << endl;
}

string Ellipse::toString() const
{
    stringstream ss;
    ss << "Ellipse with semi-axes " << semiAxes.toString();
    return ss.str();
}