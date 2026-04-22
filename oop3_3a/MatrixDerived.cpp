#include "MatrixDerived.h"

MatrixDerived& MatrixDerived::operator=(const MatrixDerived& other) {
    if (this != &other) {
        Init(other.R, other.C);
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                m[i][j] = other.m[i][j];
    }
    return *this;
}

MatrixDerived MatrixDerived::operator+(const MatrixDerived& other) const {
    MatrixDerived res(R, C);
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            res.m[i][j] = m[i][j] + other.m[i][j];
    return res;
}

MatrixDerived MatrixDerived::operator-(const MatrixDerived& other) const {
    MatrixDerived res(R, C);
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            res.m[i][j] = m[i][j] - other.m[i][j];
    return res;
}

MatrixDerived MatrixDerived::operator*(const MatrixDerived& other) const {
    MatrixDerived res(R, other.C);

    for (int i = 0; i < R; i++)
        for (int j = 0; j < other.C; j++) {
            res.m[i][j] = 0;
            for (int k = 0; k < C; k++)
                res.m[i][j] += m[i][k] * other.m[k][j];
        }

    return res;
}

MatrixDerived MatrixDerived::operator*(int scalar) const {
    MatrixDerived res(R, C);
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            res.m[i][j] = m[i][j] * scalar;
    return res;
}

MatrixDerived& MatrixDerived::operator++() {
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            m[i][j]++;
    return *this;
}

MatrixDerived MatrixDerived::operator++(int) {
    MatrixDerived temp = *this;
    ++(*this);
    return temp;
}

MatrixDerived& MatrixDerived::operator--() {
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            m[i][j]--;
    return *this;
}

MatrixDerived MatrixDerived::operator--(int) {
    MatrixDerived temp = *this;
    --(*this);
    return temp;
}

MatrixDerived::operator string() const {
    return toString();
}