#pragma once
#include <stdexcept>

template <typename T>
class GrowingArray
{
private:
    T* data;
    int size;

public:
    GrowingArray();
    GrowingArray(const GrowingArray<T>& other);
    ~GrowingArray();

    GrowingArray<T>& operator=(const GrowingArray<T>& other);

    int Size() const;

    T& operator[](int index);
    const T& operator[](int index) const;

    void PushBack(const T& value);
};

#include "GrowingArray.cpp"