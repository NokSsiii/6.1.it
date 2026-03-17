#pragma once
#include <iostream>
#include <string>

using namespace std;

class Goods {
    double first;
    unsigned int second;

public:
    Goods();
    Goods(double f, unsigned int s);
    Goods(const Goods& r);
    ~Goods();

    void SetFirst(double f);
    void SetSecond(unsigned int s);
    double GetFirst() const;
    unsigned int GetSecond() const;

    double cost() const;

    Goods& operator = (const Goods& r);
    operator string() const;

    Goods& operator ++();
    Goods& operator --();
    Goods operator ++(int);
    Goods operator --(int);

    friend ostream& operator << (ostream& out, const Goods& r);
    friend istream& operator >> (istream& in, Goods& r);
};

Goods makeGoods(double f, unsigned int s);