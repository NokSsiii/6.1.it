#include <iostream>
#include "B.h"
#include "D1.h"
#include "D2.h"
#include "D3.h"
#include "D4.h"

using namespace std;

int main()
{
    B o0(10);
    cout << "B o0(10);\n";
    cout << "sizeof(B) = " << sizeof(B) << "\n\n";
    o0.show_B();
    cout << "-----------------------------------\n";

    D1 o1(20, 21);
    cout << "D1 o1(20, 21);\n";
    cout << "sizeof(D1) = " << sizeof(D1) << "\n\n";
    o1.show_D1();
    cout << "-----------------------------------\n";

    D2 o2(30, 31);
    cout << "D2 o2(30, 31);\n";
    cout << "sizeof(D2) = " << sizeof(D2) << "\n\n";
    o2.show_D2();
    cout << "-----------------------------------\n";

    D3 o3(40, 41, 42);
    cout << "D3 o3(40, 41, 42);\n";
    cout << "sizeof(D3) = " << sizeof(D3) << "\n\n";
    o3.show_D3();
    cout << "-----------------------------------\n";

    D4 o4(50, 51, 52, 53, 54, 55);
    cout << "D4 o4(50, 51, 52, 53, 54, 55);\n";
    cout << "sizeof(D4) = " << sizeof(D4) << "\n\n";
    o4.show_D4();
    cout << "-----------------------------------\n";

    return 0;
}