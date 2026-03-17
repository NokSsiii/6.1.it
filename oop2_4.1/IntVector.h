#pragma once
#include <iostream>
#include <string>

using namespace std;

class IntVector {
private:
    int* data;
    int size;

public:
    IntVector();
    IntVector(int n);
    IntVector(const IntVector& other);
    ~IntVector();

    int getSize() const;
    void setSize(int newSize);

    double getNorm() const;

    IntVector& operator=(const IntVector& other);
    int& operator[](int index);
    operator string() const;

    friend IntVector operator-(const IntVector& lhs, const IntVector& rhs);
    friend bool operator==(const IntVector& lhs, const IntVector& rhs);
    friend bool operator!=(const IntVector& lhs, const IntVector& rhs);
    friend ostream& operator<<(ostream& out, const IntVector& vec);
    friend istream& operator>>(istream& in, IntVector& vec);
};