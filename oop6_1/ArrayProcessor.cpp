#include "ArrayProcessor.h"

int* ArrayProcessor::Process(const int* arr, int n, int& newSize)
{
    if (n <= 0 || arr == nullptr)
    {
        newSize = 0;
        return nullptr;
    }

    int minVal = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < minVal)
            minVal = arr[i];
    }

    int k = std::abs(minVal);

    newSize = n + 2;
    int* result = new int[newSize];

    int sum = 0;
    double absSum = 0;

    for (int i = 0; i < n; i++)
    {
        result[i] = arr[i] * k;
        sum += result[i];
        absSum += std::abs(result[i]);
    }

    double avgAbs = absSum / n;

    result[n] = sum;
    result[n + 1] = (int)avgAbs; // середнє по модулях (ціле)

    return result;
}