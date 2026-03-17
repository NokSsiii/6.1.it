#include "IntVector.h"
#include <cmath>
#include <sstream>

IntVector::IntVector() {
    size = 1;
    data = new int[size] {0};
}

IntVector::IntVector(int n) {
    if (n <= 0) n = 1;
    size = n;
    data = new int[size] {0};
}

IntVector::IntVector(const IntVector& other) {
    size = other.size;
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

IntVector::~IntVector() {
    delete[] data;
}

int IntVector::getSize() const {
    return size;
}

void IntVector::setSize(int newSize) {
    if (newSize <= 0) {
        cerr << "Error: Vector size must be > 0!" << endl;
        return;
    }

    int* newData = new int[newSize] {0};
    int minSize = (size < newSize) ? size : newSize;

    for (int i = 0; i < minSize; i++) {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
    size = newSize;
}

double IntVector::getNorm() const {
    double sumSq = 0;
    for (int i = 0; i < size; i++) {
        sumSq += data[i] * data[i];
    }
    return sqrt(sumSq);
}

IntVector& IntVector::operator=(const IntVector& other) {
    if (this == &other) return *this;

    delete[] data;
    size = other.size;
    data = new int[size];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
    return *this;
}

int& IntVector::operator[](int index) {
    if (index < 0 || index >= size) {
        cerr << "Error: Index out of bounds!" << endl;
        return data[0];
    }
    return data[index];
}

IntVector::operator string() const {
    stringstream ss;
    ss << "{ ";
    for (int i = 0; i < size; i++) {
        ss << data[i] << (i < size - 1 ? ", " : " ");
    }
    ss << "}";
    return ss.str();
}

IntVector operator-(const IntVector& lhs, const IntVector& rhs) {
    int minSize = (lhs.size < rhs.size) ? lhs.size : rhs.size;
    IntVector result(minSize);
    for (int i = 0; i < minSize; i++) {
        result.data[i] = lhs.data[i] - rhs.data[i];
    }
    return result;
}

bool operator==(const IntVector& lhs, const IntVector& rhs) {
    if (lhs.size != rhs.size) return false;
    for (int i = 0; i < lhs.size; i++) {
        if (lhs.data[i] != rhs.data[i]) return false;
    }
    return true;
}

bool operator!=(const IntVector& lhs, const IntVector& rhs) {
    return !(lhs == rhs);
}

ostream& operator<<(ostream& out, const IntVector& vec) {
    out << string(vec);
    return out;
}

istream& operator>>(istream& in, IntVector& vec) {
    cout << "Enter " << vec.size << " elements: ";
    for (int i = 0; i < vec.size; i++) {
        in >> vec.data[i];
    }
    return in;
}