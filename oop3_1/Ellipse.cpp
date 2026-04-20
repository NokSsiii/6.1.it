#include "Ellipse.h"
#include <sstream>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Ellipse::Ellipse(const double x, const double y) : Pair(x, y)
{
}

Ellipse::Ellipse(const Ellipse& r) : Pair(r)
{
}

Ellipse::~Ellipse()
{
}

double Ellipse::perimeter() const
{
    double a = getA();
    double b = getB();
    return 2 * M_PI * sqrt((a * a + b * b) / 2.0);
}

double Ellipse::area() const
{
    return M_PI * getA() * getB();
}

Ellipse::operator string() const
{
    stringstream ss;
    ss << "Ellipse( semi-axes: " << getA() << ", " << getB() << " )";
    return ss.str();
}

ostream& operator << (ostream& out, const Ellipse& r)
{
    return out << (string)r;
}

istream& operator >> (istream& in, Ellipse& r)
{
    double a, b;
    cout << "Enter semi-axis a (a > 0): "; in >> a;
    cout << "Enter semi-axis b (b > 0): "; in >> b;
    r.setA(a);
    r.setB(b);
    return in;
}