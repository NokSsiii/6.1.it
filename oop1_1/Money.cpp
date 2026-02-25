#include "Money.h"
#include <iostream>
using namespace std;

bool Money::SetFirst(int value)
{
    if (value == 1 || value == 2 || value == 5 || value == 10 ||
        value == 20 || value == 50 || value == 100 ||
        value == 200 || value == 500)
    {
        first = value;
        return true;
    }
    else
    {
        first = 0;
        return false;
    }
}

bool Money::SetSecond(int value)
{
    if (value > 0)
    {
        second = value;
        return true;
    }
    else
    {
        second = 0;
        return false;
    }
}

bool Money::Init(int value, int count)
{
    return SetFirst(value) && SetSecond(count);
}

void Money::Read()
{
    int value, count;
    do {
        cout << "Nominal = ";
        cin >> value;
        cout << "Count = ";
        cin >> count;
    } while (!Init(value, count));
}

void Money::Display() const
{
    cout << "Nominal = " << first << endl;
    cout << "Count = " << second << endl;
}

int Money::Summa() const
{
    return first * second;
}