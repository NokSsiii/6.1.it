#pragma once
#include <iostream>
#include <string>
using namespace std;

class Matrix {
protected:
    int** m;
    int R, C;

public:
    Matrix();
    Matrix(int r, int c);
    Matrix(const Matrix& other);

    ~Matrix();

    void Init(int r, int c);
    void Read();
    void Display() const;
    string toString() const;

    int Get(int i, int j) const;
    void Set(int i, int j, int value);

    int GetR() const { return R; }
    int GetC() const { return C; }

    friend istream& operator>>(istream& in, Matrix& mat);
    friend ostream& operator<<(ostream& out, const Matrix& mat);
};