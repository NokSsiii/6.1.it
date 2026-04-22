#pragma once
#include "Matrix.h"

class MatrixDerived : public Matrix {
public:
    using Matrix::Matrix;

    MatrixDerived& operator=(const MatrixDerived& other);

    MatrixDerived operator+(const MatrixDerived& other) const;
    MatrixDerived operator-(const MatrixDerived& other) const;
    MatrixDerived operator*(const MatrixDerived& other) const;
    MatrixDerived operator*(int scalar) const;

    MatrixDerived& operator++();      
    MatrixDerived operator++(int);   
    MatrixDerived& operator--();
    MatrixDerived operator--(int);

    operator string() const;
};