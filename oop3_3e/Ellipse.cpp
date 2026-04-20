#include "Ellipse.h"
#include <cmath>
#include <sstream>

const double PI = 3.141592653589793;

Ellipse::Ellipse() : Pair(1.0, 1.0) {}

Ellipse::Ellipse(double a, double b) { Init(a, b); }

Ellipse::Ellipse(const Ellipse& e) : Pair(e) {}

Ellipse::~Ellipse() {}

bool Ellipse::SetFirst(double f) {
    if (f > 0) {
        return Pair::SetFirst(f);
    }
    std::cout << "Error: Semiaxis must be > 0. Set to 1.0" << std::endl;
    return Pair::SetFirst(1.0);
}

bool Ellipse::SetSecond(double s) {
    if (s > 0) {
        return Pair::SetSecond(s);
    }
    std::cout << "Error: Semiaxis must be > 0. Set to 1.0" << std::endl;
    return Pair::SetSecond(1.0);
}

void Ellipse::Init(double a, double b) {
    SetFirst(a);
    SetSecond(b);
}

void Ellipse::Read() {
    double a, b;
    std::cout << "Enter semiaxis a: "; std::cin >> a;
    std::cout << "Enter semiaxis b: "; std::cin >> b;
    Init(a, b);
}

void Ellipse::Display() const {
    std::cout << toString() << std::endl;
}

std::string Ellipse::toString() const {
    std::ostringstream oss;
    oss << "Ellipse with semiaxes a=" << GetFirst() << ", b=" << GetSecond();
    return oss.str();
}

double Ellipse::Perimeter() const {
    double a = GetFirst();
    double b = GetSecond();
    return 2 * PI * std::sqrt((a * a + b * b) / 2.0);
}

double Ellipse::Area() const {
    return PI * GetFirst() * GetSecond();
}

Ellipse& Ellipse::operator=(const Ellipse& e) {
    if (this != &e) {
        Pair::operator=(e);
    }
    return *this;
}

Ellipse::operator std::string() const {
    return toString();
}

Ellipse& Ellipse::operator++() {
    SetFirst(GetFirst() + 1);
    SetSecond(GetSecond() + 1);
    return *this;
}

Ellipse Ellipse::operator++(int) {
    Ellipse temp(*this);
    ++(*this);
    return temp;
}

Ellipse& Ellipse::operator--() {
    double new_a = GetFirst() - 1;
    double new_b = GetSecond() - 1;
    SetFirst(new_a > 0 ? new_a : 0.1);
    SetSecond(new_b > 0 ? new_b : 0.1);
    return *this;
}

Ellipse Ellipse::operator--(int) {
    Ellipse temp(*this);
    --(*this);
    return temp;
}

std::ostream& operator<<(std::ostream& out, const Ellipse& e) {
    out << (std::string)e;
    return out;
}

std::istream& operator>>(std::istream& in, Ellipse& e) {
    double a, b;
    in >> a >> b;
    e.Init(a, b);
    return in;
}