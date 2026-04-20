#include "D3.h"

D3::D3(int x, int y, int z) : D1(y, z)
{
    d3 = x;
}

D3::~D3() {}

void D3::show_D3()
{
    cout << "class D3:\n";
    show_D1();
    cout << "show_D3()\n" << "D3::d3 = " << d3 << "\n\n";
}