#include "Ellipse.h"
#include <iostream>

using namespace std;

int main()
{
    // 1. Demonstration of standard object creation and keyboard input
    cout << "=== Testing Read() method and calculations ===" << endl;
    Ellipse e1;
    e1.Read();
    e1.Display();
    cout << "toString() method: " << e1.toString() << endl;

    // 2. Demonstration of creation via Init() with validation check
    cout << "\n=== Testing Init() method and value validation ===" << endl;
    Pair p;
    p.Init(-5.0, 4.0); // Intentionally passing a negative number to test validation

    Ellipse e2;
    e2.Init(p);
    e2.Display();

    // 3. Demonstration of working with an array of objects
    cout << "\n=== Testing array of objects ===" << endl;
    const int SIZE = 2;
    Ellipse arr[SIZE];

    for (int i = 0; i < SIZE; i++) {
        cout << "\nEllipse #" << i + 1 << ":\n";
        arr[i].Read();
    }

    cout << "\nArray results:" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Ellipse #" << i + 1 << " -> Area: " << arr[i].Area() << endl;
    }

    return 0;
}