#include "BitString.h"
#include <stdexcept>
#include <algorithm>

using namespace std;

BitString::BitString(int s, unsigned char val) : Array(s, (val > 0) ? 1 : 0) {}

Array* BitString::add(const Array* other) const {
    const BitString* bOther = dynamic_cast<const BitString*>(other);
    if (!bOther) throw invalid_argument("Неможливо додати BitString до іншого типу");

    BitString* result = new BitString();
    int carry = 0;
    int maxSize = max(this->size, bOther->size);

    for (int i = 0; i < maxSize || carry > 0; ++i) {
        if (i >= MAX_SIZE) throw overflow_error("Переповнення масиву BitString");

        int v1 = (i < this->size) ? this->data[i] : 0;
        int v2 = (i < bOther->size) ? bOther->data[i] : 0;

        int sum = v1 + v2 + carry;
        result->data[i] = sum % 2;
        result->size = i + 1;
        carry = sum / 2;
    }
    return result;
}

BitString BitString::bitAnd(const BitString& other) const {
    BitString res(max(this->size, other.size));
    for (int i = 0; i < res.size; ++i) {
        unsigned char v1 = (i < this->size) ? this->data[i] : 0;
        unsigned char v2 = (i < other.size) ? other.data[i] : 0;
        res.data[i] = v1 & v2;
    }
    return res;
}

BitString BitString::bitOr(const BitString& other) const {
    BitString res(max(this->size, other.size));
    for (int i = 0; i < res.size; ++i) {
        unsigned char v1 = (i < this->size) ? this->data[i] : 0;
        unsigned char v2 = (i < other.size) ? other.data[i] : 0;
        res.data[i] = v1 | v2;
    }
    return res;
}

BitString BitString::bitXor(const BitString& other) const {
    BitString res(max(this->size, other.size));
    for (int i = 0; i < res.size; ++i) {
        unsigned char v1 = (i < this->size) ? this->data[i] : 0;
        unsigned char v2 = (i < other.size) ? other.data[i] : 0;
        res.data[i] = v1 ^ v2;
    }
    return res;
}

BitString BitString::bitNot() const {
    BitString res(this->size);
    for (int i = 0; i < this->size; ++i) {
        res.data[i] = (this->data[i] == 0) ? 1 : 0;
    }
    return res;
}

BitString BitString::shiftLeft(int n) const {
    BitString res;
    res.size = min(MAX_SIZE, this->size + n);
    for (int i = 0; i < res.size; ++i) {
        res.data[i] = (i >= n) ? this->data[i - n] : 0;
    }
    return res;
}

BitString BitString::shiftRight(int n) const {
    BitString res;
    if (n >= this->size) {
        res.size = 1;
        res.data[0] = 0;
        return res;
    }
    res.size = this->size - n;
    for (int i = 0; i < res.size; ++i) {
        res.data[i] = this->data[i + n];
    }
    return res;
}

void BitString::print() const {
    cout << "BitString: ";
    if (size == 0) cout << "0";
    for (int i = size - 1; i >= 0; --i) {
        cout << (int)data[i];
    }
    cout << endl;
}