#include "D2.h"

D2::D2(int x, int y) : B(y)
{
    d2 = x;
}

D2::~D2() {}

void D2::show_D2()
{
    cout << "class D2:\n";
    show_B();
    cout << "show_D2()\n" << "D2::d2 = " << d2 << "\n\n";
}