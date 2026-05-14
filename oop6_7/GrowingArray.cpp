#pragma once
#include "GrowingArray.h"

template <typename T>
GrowingArray<T>::GrowingArray()
{
    data = nullptr;
    size = 0;
}

template <typename T>
GrowingArray<T>::GrowingArray(const GrowingArray<T>& other)
{
    size = other.size;
    data = new T[size];

    for (int i = 0; i < size; i++)
        data[i] = other.data[i];
}

template <typename T>
GrowingArray<T>::~GrowingArray()
{
    delete[] data;
}

template <typename T>
GrowingArray<T>& GrowingArray<T>::operator=(const GrowingArray<T>& other)
{
    if (this == &other)
        return *this;

    delete[] data;

    size = other.size;
    data = new T[size];

    for (int i = 0; i < size; i++)
        data[i] = other.data[i];

    return *this;
}

template <typename T>
int GrowingArray<T>::Size() const
{
    return size;
}

template <typename T>
T& GrowingArray<T>::operator[](int index)
{
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of range");
    return data[index];
}

template <typename T>
const T& GrowingArray<T>::operator[](int index) const
{
    if (index < 0 || index >= size)
        throw std::out_of_range("Index out of range");
    return data[index];
}

template <typename T>
void GrowingArray<T>::PushBack(const T& value)
{
    T* newData = new T[size + 1];

    for (int i = 0; i < size; i++)
        newData[i] = data[i];

    newData[size] = value;

    delete[] data;
    data = newData;
    size++;
}