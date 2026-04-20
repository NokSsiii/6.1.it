#include "Ellipse.h"
#include <sstream>
#include <cmath>

int Ellipse::counter = 0;

void Ellipse::Init(Pair pair)
{
    setPair(pair);
}

void Ellipse::Display() const
{
    cout << endl;
    cout << "pair = " << endl;
    pair.Display();
    cout << "perimeter = " << Perimeter() << endl;
    cout << "area = " << Area() << endl;
}

void Ellipse::Read()
{
    Pair p;
    cout << endl;
    cout << "Pair = ? " << endl;
    p.Read();
    Init(p);
}

double Ellipse::Perimeter() const
{
    double a = pair.getA();
    double b = pair.getB();
    return 2 * 3.141592653589793 * sqrt((a * a + b * b) / 2.0);
}

double Ellipse::Area() const
{
    return 3.141592653589793 * pair.getA() * pair.getB();
}

Ellipse::Ellipse(const double a, const double b)
    : pair(a, b)
{
    Ellipse::counter++;
}

Ellipse::Ellipse(const Ellipse& e)
{
    pair = e.pair;
    Ellipse::counter++;
}

Ellipse::~Ellipse(void)
{
    Ellipse::counter--;
}

Ellipse& Ellipse::operator = (const Ellipse& e)
{
    pair = e.pair;
    return *this;
}

Ellipse::operator string () const
{
    stringstream ss;
    ss << "pair:" << endl << pair << endl;
    return ss.str();
}

ostream& operator << (ostream& out, const Ellipse& e)
{
    out << string(e);
    return out;
}

istream& operator >> (istream& in, Ellipse& e)
{
    cout << endl;
    cout << "pair = ? ";
    in >> e.pair;
    return in;
}

Ellipse Ellipse::operator ++ (int)
{
    Ellipse e(*this);
    pair++;
    return e;
}

Ellipse Ellipse::operator -- (int)
{
    Ellipse e(*this);
    pair--;
    return e;
}

Ellipse& Ellipse::operator ++ ()
{
    ++pair;
    return *this;
}

Ellipse& Ellipse::operator -- ()
{
    --pair;
    return *this;
}

int Ellipse::getCounter()
{
    return Ellipse::counter;
}

int Ellipse::Pair::counter = 0;

void Ellipse::Pair::Init(double a, double b)
{
    setA(a);
    setB(b);
}

void Ellipse::Pair::Display() const
{
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "product = " << Product() << endl;
}

void Ellipse::Pair::Read()
{
    double a;
    double b;
    cout << endl;
    cout << "a = ? "; cin >> a;
    cout << "b = ? "; cin >> b;
    Init(a, b);
}

double Ellipse::Pair::Product() const
{
    return a * b;
}

Ellipse::Pair::Pair()
    : a(0), b(0)
{
    Ellipse::Pair::counter++;
}

Ellipse::Pair::Pair(const double a)
    : a(a), b(0)
{
    Ellipse::Pair::counter++;
}

Ellipse::Pair::Pair(const double a, const double b)
    : a(a), b(b)
{
    Ellipse::Pair::counter++;
}

Ellipse::Pair::Pair(const Ellipse::Pair& p)
    : a(p.a), b(p.b)
{
    Ellipse::Pair::counter++;
}

Ellipse::Pair::~Pair(void)
{
    Ellipse::Pair::counter--;
}

Ellipse::Pair& Ellipse::Pair::operator = (const Ellipse::Pair& p)
{
    this->a = p.a;
    this->b = p.b;
    return *this;
}

Ellipse::Pair::operator string () const
{
    stringstream ss;
    ss << "a = " << a << endl;
    ss << "b = " << b << endl;
    return ss.str();
}

ostream& operator << (ostream& out, const Ellipse::Pair& p)
{
    out << string(p);
    return out;
}

istream& operator >> (istream& in, Ellipse::Pair& p)
{
    double a;
    double b;
    cout << endl;
    cout << "a = ? "; in >> a;
    cout << "b = ? "; in >> b;
    p.setA(a);
    p.setB(b);
    return in;
}

Ellipse::Pair& Ellipse::Pair::operator ++ ()
{
    ++a;
    ++b;
    return *this;
}

Ellipse::Pair& Ellipse::Pair::operator -- ()
{
    --a;
    --b;
    return *this;
}

Ellipse::Pair Ellipse::Pair::operator ++ (int)
{
    Ellipse::Pair t(*this);
    a++;
    b++;
    return t;
}

Ellipse::Pair Ellipse::Pair::operator -- (int)
{
    Ellipse::Pair t(*this);
    a--;
    b--;
    return t;
}

int Ellipse::Pair::getCounter()
{
    return Ellipse::Pair::counter;
}