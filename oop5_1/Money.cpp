#include "Money.h"

// перевірка
void Money::validate(int f, int s) const
{
    int allowed[] = { 1,2,5,10,20,50,100,200,500 };
    bool ok = false;

    for (int val : allowed)
        if (f == val) ok = true;

    if (!ok)
        throw MoneyException("Invalid nominal!");

    if (s <= 0)
        throw MoneyException("Invalid count!");
}


Money::Money() : first(1), second(1) {}

Money::Money(int f, int s)
{
    Init(f, s);
}

Money::Money(const Money& m)
{
    first = m.first;
    second = m.second;
}

void Money::Init(int f, int s)
{
    validate(f, s);
    first = f;
    second = s;
}

int Money::GetFirst() const { return first; }
int Money::GetSecond() const { return second; }

void Money::SetFirst(int value)
{
    validate(value, second);
    first = value;
}

void Money::SetSecond(int value)
{
    validate(first, value);
    second = value;
}

double Money::summa() const
{
    return first * second;
}

void Money::Read()
{
    int f, s;
    cin >> f >> s;
    Init(f, s);
}

void Money::Display() const
{
    cout << *this << endl;
}

Money& Money::operator=(const Money& m)
{
    if (this != &m)
    {
        first = m.first;
        second = m.second;
    }
    return *this;
}

Money& Money::operator++()
{
    first++;
    return *this;
}

Money Money::operator++(int)
{
    Money temp(*this);
    second++;
    return temp;
}

Money& Money::operator--()
{
    first--;
    return *this;
}

Money Money::operator--(int)
{
    Money temp(*this);
    second--;
    return temp;
}

Money::operator string() const
{
    return "Money: " + to_string(first) + " x " + to_string(second);
}

istream& operator>>(istream& in, Money& m)
{
    int f, s;
    in >> f >> s;
    m.Init(f, s);
    return in;
}

ostream& operator<<(ostream& out, const Money& m)
{
    out << "Nominal=" << m.first
        << " Count=" << m.second
        << " Sum=" << m.summa();
    return out;
}

Money makeMoney(int f, int s)
{
    if (s <= 0)
        throw MoneyException("Error in makeMoney");

    return Money(f, s);
}