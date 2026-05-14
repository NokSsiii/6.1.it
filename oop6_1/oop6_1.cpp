#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ArrayProcessor.h"

using namespace std;

int main()
{
    srand((unsigned)time(0));

    int n;
    cout << "Enter size: ";
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; i++)
        arr[i] = rand() % 101 - 50;

    cout << "\nOriginal array:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    int newSize;
    int* res = ArrayProcessor::Process(arr, n, newSize);

    cout << "\nResult array:\n";
    for (int i = 0; i < newSize; i++)
        cout << res[i] << " ";
    cout << endl;

    delete[] arr;
    delete[] res;

    return 0;
}