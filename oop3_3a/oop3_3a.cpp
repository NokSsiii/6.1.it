#include "MatrixDerived.h"
#include <iostream>
using namespace std;

int main() {
    MatrixDerived A(2, 2), B(2, 2);

    cout << "Enter A:\n";
    cin >> A;

    cout << "Enter B:\n";
    cin >> B;

    cout << "A:\n" << A;
    cout << "B:\n" << B;

    MatrixDerived C = A + B;
    cout << "A + B:\n" << C;

    MatrixDerived D = A * B;
    cout << "A * B:\n" << D;

    MatrixDerived E = A * 2;
    cout << "A * 2:\n" << E;

    ++A;
    cout << "++A:\n" << A;

    string s = A;
    cout << "String:\n" << s;

    return 0;
}