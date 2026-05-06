#pragma once
#include <cmath>
#include <stdexcept>

template <typename T>
double averageAbs(T arr[], int size)
{
    if (size <= 0)
        throw std::invalid_argument("Size must be > 0");

    double sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += std::abs(arr[i]);
    }

    return sum / size;
}