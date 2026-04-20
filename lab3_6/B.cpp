#include "B.h"

B::B() : b(0) {}

B::B(int x)
{
    b = x;
}

B::~B() {}

void B::show_B()
{
    cout << "class B:\n";
    cout << "show_B()\n" << "B::b = " << b << "\n\n";
}