#include "Hierarchy.h"

int main() {
    const int SIZE = 2;

    // Масив вказівників на інтерфейс
    IParent* arr[SIZE];

    arr[0] = new Child("Ivan", "Ivanov", "Ivanovych");
    arr[1] = new Child("Petro", "Petrov", "Petrovych");

    for (int i = 0; i < SIZE; ++i) {
        cout << "Real type: " << arr[i]->getType() << endl;
        arr[i]->print();
        cout << "-----------------------" << endl;

        delete arr[i];
    }

    return 0;
}