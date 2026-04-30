#include "Money.h"
#include <algorithm>

void Money::trim() {
    int s = getSize();
    while (s > 2 && (*this)[s - 1] == 0) {
        s--;
    }
    if (s == 2 && (*this)[1] == 0 && (*this)[0] == 0) {
        s = 0;
    }
    setSize(s);
}

Money::Money() : Array(0, 0) {}

Money::Money(int size, int initialValue) : Array(size, initialValue) {
    if (initialValue < 0 || initialValue > 9) {
        exit(1);
    }
}

void Money::setElement(int index, int value) {
    if (value < 0 || value > 9) {
        exit(1);
    }
    Array::setElement(index, value);
}

void Money::setDigit(int index, int value) {
    setElement(index, value);
}

int Money::getDigit(int index) const {
    return (*this)[index];
}

std::string Money::toString() const {
    if (getSize() == 0) return "0.00";
    std::string result = "";
    if (getSize() <= 2) {
        result += "0";
    }
    else {
        for (int i = getSize() - 1; i >= 2; --i) {
            result += std::to_string((*this)[i]);
        }
    }
    result += ".";
    if (getSize() > 1) result += std::to_string((*this)[1]);
    else result += "0";
    if (getSize() > 0) result += std::to_string((*this)[0]);
    else result += "0";
    return result;
}

bool Money::operator<(const Money& other) const {
    int sz1 = this->getSize();
    int sz2 = other.getSize();
    if (sz1 != sz2) return sz1 < sz2;
    for (int i = sz1 - 1; i >= 0; --i) {
        if ((*this)[i] != other[i]) return (*this)[i] < other[i];
    }
    return false;
}

bool Money::operator==(const Money& other) const {
    int sz1 = this->getSize();
    int sz2 = other.getSize();
    if (sz1 != sz2) return false;
    for (int i = 0; i < sz1; ++i) {
        if ((*this)[i] != other[i]) return false;
    }
    return true;
}

Money Money::operator+(const Money& other) const {
    Money res;
    int maxLen = std::max(this->getSize(), other.getSize());
    res.setSize(maxLen);
    int carry = 0;
    for (int i = 0; i < maxLen; ++i) {
        int d1 = (i < this->getSize()) ? (*this)[i] : 0;
        int d2 = (i < other.getSize()) ? other[i] : 0;
        int sum = d1 + d2 + carry;
        res.setElement(i, sum % 10);
        carry = sum / 10;
    }
    if (carry > 0) {
        res.setSize(maxLen + 1);
        res.setElement(maxLen, carry);
    }
    return res;
}

Money Money::operator-(const Money& other) const {
    if (*this < other) {
        exit(1);
    }
    Money res;
    res.setSize(this->getSize());
    int borrow = 0;
    for (int i = 0; i < this->getSize(); ++i) {
        int d1 = (*this)[i];
        int d2 = (i < other.getSize()) ? other[i] : 0;
        int diff = d1 - d2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        }
        else {
            borrow = 0;
        }
        res.setElement(i, diff);
    }
    res.trim();
    return res;
}

Money& Money::operator+=(const Money& other) {
    *this = *this + other;
    return *this;
}

Money& Money::operator-=(const Money& other) {
    *this = *this - other;
    return *this;
}

Money& Money::operator=(const Money& other) {
    if (this != &other) {
        setSize(other.getSize());
        for (int i = 0; i < getSize(); ++i) {
            setElement(i, other[i]);
        }
    }
    return *this;
}

std::istream& operator>>(std::istream& is, Money& m) {
    std::string s;
    is >> s;
    size_t dotPos = s.find('.');
    std::string hrv = "", kop = "";
    if (dotPos != std::string::npos) {
        hrv = s.substr(0, dotPos);
        kop = s.substr(dotPos + 1);
    }
    else {
        hrv = s;
        kop = "00";
    }
    if (kop.length() == 1) kop += "0";
    else if (kop.length() == 0) kop = "00";
    else kop = kop.substr(0, 2);
    std::string total = hrv + kop;
    size_t start = 0;
    while (start < total.length() && total[start] == '0') start++;
    if (start == total.length()) {
        m.setSize(0);
        return is;
    }
    total = total.substr(start);
    int sz = total.length();
    m.setSize(sz);
    for (int i = 0; i < sz; ++i) {
        m.setElement(i, total[sz - 1 - i] - '0');
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Money& m) {
    os << m.toString();
    return os;
}