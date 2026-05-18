#include "ArrayLogic.h"
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int getRandomNumber() {
    return std::rand() % 100;
}

void fillVector(vector<int>& vec, int n) {
    vec.resize(n);
    generate(vec.begin(), vec.end(), getRandomNumber);
}

void printVector(const vector<int>& vec) {
    for (int i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

void sortDescending(vector<int>& vec) {
    sort(vec.begin(), vec.end(), greater<int>());
}