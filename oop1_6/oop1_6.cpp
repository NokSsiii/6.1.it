#include "Ellipse.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "=== Testing Nested Class Composition ===" << endl;

    Ellipse e1;
    e1.Read();
    e1.Display();
    cout << "String representation: " << e1.toString() << endl;

    cout << "\n=== Testing manual initialization ===" << endl;
    Ellipse::Pair manualAxes;
    manualAxes.Init(4.0, 3.0);

    Ellipse e2;
    e2.Init(manualAxes);
    e2.Display();

    return 0;
}