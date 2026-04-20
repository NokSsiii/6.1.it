#pragma once
#include "Object.h"
#include <iostream>
#include <string>

class Matrix : public Object {
private:
    int** m;
    int R;
    int C;

    void allocateMemory(int r, int c);
    void freeMemory();

public:
    Matrix();
    Matrix(int r, int c);
    Matrix(const Matrix& other);
    ~Matrix();

    int getRows() const;
    int getCols() const;
    int getElement(int r, int c) const;
    void setElement(int r, int c, int value);

    void Init(int r, int c);
    void Read();
    void Display() const;
    std::string toString() const;

    operator std::string() const;

    Matrix& operator=(const Matrix& other);
    Matrix& operator++();
    Matrix operator++(int);
    Matrix& operator--();
    Matrix operator--(int);

    friend Matrix operator+(const Matrix& a, const Matrix& b);
    friend Matrix operator-(const Matrix& a, const Matrix& b);
    friend Matrix operator*(const Matrix& a, const Matrix& b);
    friend Matrix operator*(const Matrix& a, int scalar);
    friend Matrix operator*(int scalar, const Matrix& a);

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
    friend std::istream& operator>>(std::istream& is, Matrix& matrix);
};