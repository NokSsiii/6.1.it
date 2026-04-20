#pragma once
#include <iostream>

class Array {
protected:
    static const int MAX_SIZE = 100;
    unsigned char data[MAX_SIZE];
    int size;

    bool rangeCheck(int index) const;

public:
    Array(int s = 0, unsigned char val = 0);
    virtual ~Array();

    unsigned char& operator[](int index);
    const unsigned char& operator[](int index) const;

    virtual Array* add(const Array* other) const;
    virtual void print() const;

    int getSize() const;


};