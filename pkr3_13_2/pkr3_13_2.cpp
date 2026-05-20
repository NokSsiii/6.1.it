#include "hash_table.h"
#include "interface.h"
#include <iostream>
#include <locale>

using namespace std;

int main() {
    std::setlocale(LC_ALL, "Ukrainian");

    HashTable employeeTable;
    initHashTable(employeeTable, 100);

    int choice = -1;
    while (choice != 0) {
        showMenu();
        choice = getValidInt("Оберіть пункт: ");

        switch (choice) {
        case 1: handleAddEmployee(employeeTable); break;
        case 2: handleDeleteEmployee(employeeTable); break;
        case 3: handleEditEmployee(employeeTable); break;
        case 4: handleFindEmployee(employeeTable); break;
        case 5: displayAllEmployees(employeeTable); break;
        case 6: handleSaveToFile(employeeTable); break;
        case 7: handleLoadFromFile(employeeTable); break;
        case 0: cout << "Завершення.\n"; break;
        default: cout << ">> Невірно.\n"; break;
        }
    }
    return 0;
}