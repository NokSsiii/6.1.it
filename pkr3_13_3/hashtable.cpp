#include "hashtable.h"
#include <fstream>
#include <string>

using namespace std;

HashTable createHashTable(int size) {
    HashTable ht;
    ht.size = size;
    ht.table = new HashNode * [size];
    for (int i = 0; i < size; ++i) {
        ht.table[i] = nullptr;
    }
    return ht;
}

void destroyHashTable(HashTable& ht) {
    for (int i = 0; i < ht.size; ++i) {
        HashNode* current = ht.table[i];
        while (current != nullptr) {
            HashNode* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }
    delete[] ht.table;
    ht.table = nullptr;
    ht.size = 0;
}

int calculateHash(const string& key, int tableSize) {
    unsigned long hash = 5381;
    for (char c : key) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % tableSize;
}

HashNode* findEmployeeNode(const HashTable& ht, const string& key) {
    int index = calculateHash(key, ht.size);
    HashNode* current = ht.table[index];
    while (current != nullptr) {
        if (current->data.surnameInitials == key) {
            return current;
        }
        current = current->next;
    }
    return nullptr; // Не знайдено
}

bool addEmployee(HashTable& ht, const Employee& emp) {
    if (findEmployeeNode(ht, emp.surnameInitials) != nullptr) {
        return false; // Такий службовець вже існує
    }

    int index = calculateHash(emp.surnameInitials, ht.size);
    HashNode* newNode = new HashNode{ emp, ht.table[index] };
    ht.table[index] = newNode;
    return true;
}

bool removeEmployee(HashTable& ht, const string& key) {
    int index = calculateHash(key, ht.size);
    HashNode* current = ht.table[index];
    HashNode* prev = nullptr;

    while (current != nullptr) {
        if (current->data.surnameInitials == key) {
            if (prev == nullptr) {
                ht.table[index] = current->next;
            }
            else {
                prev->next = current->next;
            }
            delete current;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

bool editEmployee(HashTable& ht, const string& key, const Employee& newData) {
    HashNode* node = findEmployeeNode(ht, key);
    if (node != nullptr) {
        node->data.jobTitle = newData.jobTitle;
        node->data.hireYear = newData.hireYear;
        node->data.salary = newData.salary;
        return true;
    }
    return false;
}

bool saveToFile(const HashTable& ht, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) return false;

    for (int i = 0; i < ht.size; ++i) {
        HashNode* current = ht.table[i];
        while (current != nullptr) {
            file << current->data.surnameInitials << endl;
            file << current->data.jobTitle << endl;
            file << current->data.hireYear << endl;
            file << current->data.salary << endl;
            current = current->next;
        }
    }
    file.close();
    return true;
}

bool loadFromFile(HashTable& ht, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) return false;

    // Очищаємо поточну таблицю перед завантаженням нових даних
    destroyHashTable(ht);
    ht = createHashTable(10); // Повторна ініціалізація

    Employee emp;
    string salaryStr, yearStr;

    while (getline(file, emp.surnameInitials)) {
        getline(file, emp.jobTitle);
        getline(file, yearStr);
        getline(file, salaryStr);

        emp.hireYear = stoi(yearStr);
        emp.salary = stod(salaryStr);

        addEmployee(ht, emp);
    }
    file.close();
    return true;
}