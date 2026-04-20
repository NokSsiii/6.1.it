#include "Array.h"
#include <stdexcept>
#include <algorithm>

using namespace std;

bool Array::rangeCheck(int index) const {
    return index >= 0 && index < size;
}

Array::Array(int s, unsigned char val) {
    if (s > MAX_SIZE) throw invalid_argument("Перевищено максимальний розмір масиву");
    size = s;
    for (int i = 0; i < size; ++i) {
        data[i] = val;
    }
    for (int i = size; i < MAX_SIZE; ++i) {
        data[i] = 0;
    }
}

Array::~Array() {}

unsigned char& Array::operator[](int index) {
    if (!rangeCheck(index)) throw out_of_range("Індекс виходить за межі масиву");
    return data[index];
}

const unsigned char& Array::operator[](int index) const {
    if (!rangeCheck(index)) throw out_of_range("Індекс виходить за межі масиву");
    return data[index];
}

Array* Array::add(const Array* other) const {
    int maxSize = max(this->size, other->size);
    Array* result = new Array(maxSize);
    for (int i = 0; i < maxSize; ++i) {
        unsigned char v1 = (i < this->size) ? this->data[i] : 0;
        unsigned char v2 = (i < other->size) ? other->data[i] : 0;
        (*result)[i] = v1 + v2;
    }
    return result;
}

void Array::print() const {
    cout << "Array: [ ";
    for (int i = 0; i < size; ++i) {
        cout << (int)data[i] << " ";
    }
    cout << "]" << endl;
}

int Array::getSize() const {
    return size;
}