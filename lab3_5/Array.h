#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <vector>

class Array {
private:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int currentSize;

protected:
    void rangeCheck(int index) const;
    void setInternalSize(int newSize);

public:
    Array(int size = 0, int initialValue = 0);
    virtual ~Array();

    int getSize() const;
    void setSize(int newSize);

    int operator[](int index) const;
    virtual void setElement(int index, int value);

    virtual std::string toString() const;
    operator std::string() const;
};

#endif