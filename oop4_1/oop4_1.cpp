#include "Hierarchy.h"
#include <typeinfo> 

int main() {
    const int SIZE = 2;
    // Масив вказівників на абстрактний клас
    Parent* arr[SIZE];

    arr[0] = new Child("Ivan", "Ivanov", "Ivanovych");
    arr[1] = new Child("Petro", "Petrov", "Petrovych");

    for (int i = 0; i < SIZE; ++i) {
        cout << "Real type: " << typeid(*arr[i]).name() << endl;
        arr[i]->print();
        cout << "\n-----------------------" << endl;

        delete arr[i];
    }

    return 0;
}