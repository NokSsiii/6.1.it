#pragma once
#include "Array.h"

class BitString : public Array {
public:
    BitString(int s = 0, unsigned char val = 0);

    Array* add(const Array* other) const override;
    void print() const override;


    BitString bitAnd(const BitString& other) const;
    BitString bitOr(const BitString& other) const;
    BitString bitXor(const BitString& other) const;
    BitString bitNot() const;
    BitString shiftLeft(int n) const;
    BitString shiftRight(int n) const;
};