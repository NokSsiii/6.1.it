#include <iostream>
#include "Matrix.h"
using namespace std;

int main()
{
    Matrix A, B, C;

    cout << "Matrix A:" << endl;
    A.Read();

    cout << "Matrix B:" << endl;
    B.Read();

    cout << endl << "Matrix A:";
    A.Display();

    cout << endl << "Matrix B:";
    B.Display();

    C = A.Add(B);
    cout << endl << "A + B:";
    C.Display();

    C = A.Sub(B);
    cout << endl << "A - B:";
    C.Display();

    C = A.Mul(B);
    cout << endl << "A * B:";
    C.Display();

    C = A.MulByNumber(2);
    cout << endl << "A * 2:";
    C.Display();

    cout << endl;
    cin.get();
    return 0;
}