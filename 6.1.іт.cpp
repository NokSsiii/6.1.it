#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void createArray(int* arr, int size, int min, int max);
void printArray(const int* arr, int size);
int countCriteria(const int* arr, int size);
int sumCriteria(const int* arr, int size);
void replaceCriteria(int* arr, int size);

int main() {
    srand(static_cast<unsigned>(time(0)));

    const int SIZE = 25;
    const int MIN_VAL = -11;
    const int MAX_VAL = 13;

    int t[SIZE];

    createArray(t, SIZE, MIN_VAL, MAX_VAL);

    cout << "Original array t[" << SIZE << "]:" << endl;
    printArray(t, SIZE);
    cout << endl;

    int count = countCriteria(t, SIZE);
    int sum = sumCriteria(t, SIZE);

    cout << "Results:" << endl;
    cout << "Criteria: elements < 0 AND index not divisible by 3" << endl;
    cout << "Count: " << count << endl;
    cout << "Sum:   " << sum << endl;
    cout << endl;

    replaceCriteria(t, SIZE);

    cout << "Modified array t[" << SIZE << "]:" << endl;
    printArray(t, SIZE);

    return 0;
}

void createArray(int* arr, int size, int min, int max) {
    for (int i = 0; i < size; i++) {
        arr[i] = min + rand() % (max - min + 1);
    }
}

void printArray(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(4) << arr[i];
    }
    cout << endl;
}

int countCriteria(const int* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0 && i % 3 != 0) {
            count++;
        }
    }
    return count;
}

int sumCriteria(const int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0 && i % 3 != 0) {
            sum += arr[i];
        }
    }
    return sum;
}

void replaceCriteria(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0 && i % 3 != 0) {
            arr[i] = 0;
        }
    }
}