#include "Matrix.h"

Matrix::Matrix() : R(0), C(0), m(nullptr) {}

Matrix::Matrix(int r, int c) {
    Init(r, c);
}

Matrix::Matrix(const Matrix& other) {
    Init(other.R, other.C);
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            m[i][j] = other.m[i][j];
}

Matrix::~Matrix() {
    for (int i = 0; i < R; i++)
        delete[] m[i];
    delete[] m;
}

void Matrix::Init(int r, int c) {
    R = r;
    C = c;
    m = new int* [R];
    for (int i = 0; i < R; i++)
        m[i] = new int[C];
}

void Matrix::Read() {
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> m[i][j];
}

void Matrix::Display() const {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
            cout << m[i][j] << " ";
        cout << endl;
    }
}

string Matrix::toString() const {
    string s = "";
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
            s += to_string(m[i][j]) + " ";
        s += "\n";
    }
    return s;
}

int Matrix::Get(int i, int j) const {
    return m[i][j];
}

void Matrix::Set(int i, int j, int value) {
    m[i][j] = value;
}

istream& operator>>(istream& in, Matrix& mat) {
    mat.Read();
    return in;
}

ostream& operator<<(ostream& out, const Matrix& mat) {
    out << mat.toString();
    return out;
}