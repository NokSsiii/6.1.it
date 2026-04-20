#include "D1.h"

D1::D1(int x, int y) : B(y)
{
    d1 = x;
}

D1::~D1() {}

void D1::show_D1()
{
    cout << "class D1:\n";
    show_B();
    cout << "show_D1()\n" << "D1::d1 = " << d1 << "\n\n";
}