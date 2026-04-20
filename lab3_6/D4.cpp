#include "D4.h"

D4::D4(int x, int d1_val, int b_d1_val, int b_direct_val, int d2_val, int b_d2_val)
    : D1(d1_val, b_d1_val), B(b_direct_val), D2(d2_val, b_d2_val)
{
    d4 = x;
}

D4::~D4() {}

void D4::show_D4()
{
    cout << "class D4:\n";
    show_D1();
    show_D2();
    cout << "show_D4()\n" << "D4::d4 = " << d4 << "\n\n";
}