#include <iostream>
#include "GrowingArray.h"
#include "Algorithms.h"
#include "Predicates.h"

using namespace std;

int main()
{
    GrowingArray<int> arr;

    arr.PushBack(10);
    arr.PushBack(-5);
    arr.PushBack(7);
    arr.PushBack(-2);
    arr.PushBack(9);

    cout << "Original:\n";
    for (int i = 0; i < arr.Size(); i++)
        cout << arr[i] << " ";
    cout << endl;

    inverse(arr);

    cout << "\nAfter inverse:\n";
    for (int i = 0; i < arr.Size(); i++)
        cout << arr[i] << " ";
    cout << endl;

    inverse_if(arr, IsNegative());

    cout << "\nAfter inverse_if (negative only):\n";
    for (int i = 0; i < arr.Size(); i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}