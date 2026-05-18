#include <iostream>
#include <vector>
#include <ctime>
#include "ArrayLogic.h"
#include <Windows.h>

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    srand(static_cast<unsigned>(time(nullptr)));

    int n;
    cout << "Введіть кількість елементів масиву (n): ";
    cin >> n;

    vector<int> myVector;

    fillVector(myVector, n);

    cout << "Початковий масив: " << endl;
    printVector(myVector);

    sortDescending(myVector);

    cout << "Масив, відсортований за спаданням: " << endl;
    printVector(myVector);

    return 0;
}