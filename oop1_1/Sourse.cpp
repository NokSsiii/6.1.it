#include <iostream>
#include "Money.h"
using namespace std;

Money makeMoney(int value, int count)
{
    Money m;
    if (!m.Init(value, count))
        cout << "Wrong arguments to Init!" << endl;
    return m;
}

int main()
{
    Money m;

    m.Read();
    m.Display();
    cout << "Summa = " << m.Summa() << endl << endl;

    int value, count;
    cout << "Nominal = ";
    cin >> value;
    cout << "Count = ";
    cin >> count;

    m = makeMoney(value, count);
    m.Display();
    cout << "Summa = " << m.Summa() << endl;

    return 0;
}