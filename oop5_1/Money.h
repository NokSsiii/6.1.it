#pragma once
#include <iostream>
#include <string>
#include "ERROR.h"

using namespace std;

class Money
{
private:
    int first;
    int second;

    void validate(int f, int s) const;

public:
    Money();
    Money(int f, int s);
    Money(const Money& m);

    void Init(int f, int s);

    int GetFirst() const;
    int GetSecond() const;

    void SetFirst(int value);
    void SetSecond(int value);

    double summa() const;

    void Read();
    void Display() const;

    Money& operator=(const Money& m);

    Money& operator++();
    Money operator++(int);
    Money& operator--();
    Money operator--(int);

    operator string() const;

    friend istream& operator>>(istream& in, Money& m);
    friend ostream& operator<<(ostream& out, const Money& m);
};

Money makeMoney(int f, int s);