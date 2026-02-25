#pragma once
class Matrix
{
private:
    int m[10][10];
    int R, C;      // кількість рядків і стовпців

public:
    bool Init(int r, int c);
    void Read();
    void Display() const;

    int GetElement(int i, int j) const;

    Matrix Add(const Matrix& other) const;
    Matrix Sub(const Matrix& other) const;
    Matrix Mul(const Matrix& other) const;
    Matrix MulByNumber(int num) const;
};