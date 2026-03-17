#include <iostream>
#include "IntVector.h"

using namespace std;

#pragma pack(push, 1)
class IntVectorPacked {
    int* data;
    int size;
};
#pragma pack(pop)

int main() {
    cout << "--- Size Demonstration ---" << endl;
    cout << "Size of IntVector (standard): " << sizeof(IntVector) << " bytes" << endl;
    cout << "Size of IntVectorPacked (#pragma pack(1)): " << sizeof(IntVectorPacked) << " bytes" << endl;
    cout << "--------------------------" << endl << endl;

    IntVector v1;
    IntVector v2(3);

    cout << "Initialize vector v2:" << endl;
    cin >> v2;

    IntVector v3 = v2;

    cout << "\nVector v2: " << v2 << endl;
    cout << "Vector v3 (copy of v2): " << v3 << endl;

    v1.setSize(3);
    v1[0] = 10; v1[1] = 20; v1[2] = 30;
    cout << "\nVector v1: " << v1 << endl;

    cout << "\n--- Array of Objects ---" << endl;
    IntVector arr[2] = { IntVector(2), IntVector(2) };
    arr[0][0] = 5; arr[0][1] = 5;
    arr[1][0] = 1; arr[1][1] = 1;
    cout << "arr[0]: " << arr[0] << endl;
    cout << "arr[1]: " << arr[1] << endl;

    cout << "\n--- Operations ---" << endl;
    IntVector v_diff = v1 - v2;
    cout << "v1 - v2 = " << v_diff << endl;

    if (v2 == v3) cout << "v2 and v3 are equal!" << endl;
    if (v1 != v2) cout << "v1 and v2 are NOT equal!" << endl;

    cout << "\nNorm of v1 " << v1 << " = " << v1.getNorm() << endl;

    return 0;
}