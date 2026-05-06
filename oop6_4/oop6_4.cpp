#include <iostream>
#include "AverageAbs.h"

using namespace std;

int main()
{
    try
    {
        // int
        int arr1[] = { -1, 2, -3, 4, -5 };
        int size1 = sizeof(arr1) / sizeof(arr1[0]);

        cout << "Average abs (int): "
            << averageAbs<int>(arr1, size1) << endl;

        // double
        double arr2[] = { -1.5, 2.3, -3.7, 4.1 };
        int size2 = sizeof(arr2) / sizeof(arr2[0]);

        cout << "Average abs (double): "
            << averageAbs<double>(arr2, size2) << endl;
    }
    catch (const exception& e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}