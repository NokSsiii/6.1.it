#include "Array.h"

void Array::rangeCheck(int index) const {
    if (index < 0 || index >= currentSize) {
        exit(1);
    }
}

void Array::setInternalSize(int newSize) {
    if (newSize < 0 || newSize > MAX_SIZE) {
        exit(1);
    }
    currentSize = newSize;
}

Array::Array(int size, int initialValue) {
    setInternalSize(size);
    for (int i = 0; i < currentSize; ++i) {
        arr[i] = initialValue;
    }
}

Array::~Array() {}

int Array::getSize() const { return currentSize; }

void Array::setSize(int newSize) {
    setInternalSize(newSize);
}

int Array::operator[](int index) const {
    rangeCheck(index);
    return arr[index];
}

void Array::setElement(int index, int value) {
    rangeCheck(index);
    arr[index] = value;
}

std::string Array::toString() const {
    std::string s = "[";
    for (int i = 0; i < currentSize; ++i) {
        s += std::to_string(arr[i]);
        if (i < currentSize - 1) s += ", ";
    }
    s += "]";
    return s;
}

Array::operator std::string() const {
    return toString();
}