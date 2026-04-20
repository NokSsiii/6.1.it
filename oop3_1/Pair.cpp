#include "Pair.h"
#include <sstream>
#include <cstdlib>

Pair::Pair(const double x, const double y)
{
    setA(x);
    setB(y);
}

Pair::Pair(const Pair& r)
{
    a = r.a;
    b = r.b;
}

Pair::~Pair()
{
}

void Pair::setA(const double value)
{
    if (value <= 0)
    {
        cout << "Error: Value must be strictly greater than 0. Terminating program." << endl;
        exit(1);
    }
    a = value;
}

void Pair::setB(const double value)
{
    if (value <= 0)
    {
        cout << "Error: Value must be strictly greater than 0. Terminating program." << endl;
        exit(1);
    }
    b = value;
}

double Pair::product() const
{
    return a * b;
}

Pair::operator string() const
{
    stringstream ss;
    ss << "Pair( " << getA() << ", " << getB() << " )";
    return ss.str();
}

ostream& operator << (ostream& out, const Pair& r)
{
    return out << (string)r;
}

istream& operator >> (istream& in, Pair& r)
{
    double a, b;
    cout << "Enter a (a > 0): "; in >> a;
    cout << "Enter b (b > 0): "; in >> b;
    r.setA(a);
    r.setB(b);
    return in;
}