#include <iostream>
#include "Pair.h"
#include "Ellipse.h"

using namespace std;

Pair processBaseObject(Pair obj)
{
    cout << "  [processBaseObject function] Received: " << obj << endl;
    cout << "  Product of fields: " << obj.product() << endl;

    obj.setA(obj.getA() + 2.0);
    obj.setB(obj.getB() + 2.0);
    return obj;
}

int main()
{
    cout << "=== Testing base class Pair ===" << endl;
    Pair p1;
    Pair p2(3.5, 4.0);
    Pair p3(p2);

    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "p3 (copy of p2): " << p3 << endl;
    cout << "Product of numbers in p2: " << p2.product() << endl << endl;

    // --- Demonstrating arrays of objects ---
    cout << "=== Testing array of Ellipse objects ===" << endl;
    const int ARR_SIZE = 2;
    Ellipse arr[ARR_SIZE] = { Ellipse(2.0, 3.0), Ellipse(4.0, 5.0) };

    for (int i = 0; i < ARR_SIZE; i++)
    {
        cout << "Ellipse [" << i << "]: " << arr[i] << endl;
        cout << "  Area: " << arr[i].area() << endl;
        cout << "  Perimeter: " << arr[i].perimeter() << endl;
    }
    cout << endl;

    cout << "=== Testing Liskov Substitution Principle ===" << endl;
    Ellipse e1(5.0, 10.0);
    cout << "Original ellipse e1: " << e1 << endl;

    cout << "Passing e1 to function (as Pair):" << endl;
    Pair returnedPair = processBaseObject(e1);

    cout << "Returned Pair object (with modified fields): " << returnedPair << endl << endl;

    cout << "=== Testing keyboard input ===" << endl;
    Ellipse e_input;
    cin >> e_input;
    cout << "You entered: " << e_input << endl;
    cout << "Its area: " << e_input.area() << endl;

    return 0;
}