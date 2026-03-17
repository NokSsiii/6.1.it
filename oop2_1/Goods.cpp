#include "Goods.h"
#include <sstream>
#include <cstdlib>

Goods::Goods() {
    SetFirst(0.1);
    SetSecond(1);
}

Goods::Goods(double f, unsigned int s) {
    SetFirst(f);
    SetSecond(s);
}

Goods::Goods(const Goods& r) {
    first = r.first;
    second = r.second;
}

Goods::~Goods() {}

void Goods::SetFirst(double f) {
    if (f > 0) {
        first = f;
    }
    else {
        cout << "Error: Price must be > 0. Set to 0.1" << endl;
        first = 0.1;
    }
}

void Goods::SetSecond(unsigned int s) {
    if (s > 0) {
        second = s;
    }
    else {
        cout << "Error: Quantity must be > 0. Set to 1" << endl;
        second = 1;
    }
}

double Goods::GetFirst() const { return first; }
unsigned int Goods::GetSecond() const { return second; }

double Goods::cost() const {
    return first * second;
}

Goods& Goods::operator = (const Goods& r) {
    if (this != &r) {
        first = r.first;
        second = r.second;
    }
    return *this;
}

Goods::operator string() const {
    stringstream ss;
    ss << "Price = " << first << ", Quantity = " << second;
    return ss.str();
}

Goods& Goods::operator ++() {
    first++;
    return *this;
}

Goods& Goods::operator --() {
    if (first > 1) {
        first--;
    }
    else {
        first = 0.1;
    }
    return *this;
}

Goods Goods::operator ++(int) {
    Goods t(*this);
    second++;
    return t;
}

Goods Goods::operator --(int) {
    Goods t(*this);
    if (second > 1) {
        second--;
    }
    return t;
}

ostream& operator << (ostream& out, const Goods& r) {
    out << string(r);
    return out;
}

istream& operator >> (istream& in, Goods& r) {
    double f;
    unsigned int s;
    cout << "Enter price (>0): ";
    in >> f;
    cout << "Enter quantity (>0): ";
    in >> s;

    r.SetFirst(f);
    r.SetSecond(s);
    return in;
}

Goods makeGoods(double f, unsigned int s) {
    if (f <= 0 || s == 0) {
        cout << "Critical error in makeGoods(): Invalid parameters! Exiting." << endl;
        exit(1);
    }
    return Goods(f, s);
}