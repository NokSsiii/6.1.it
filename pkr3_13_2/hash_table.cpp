#include "hash_table.h"
#include <fstream>
#include <limits>

using namespace std;

void initHashTable(HashTable& ht, int capacity) {
    ht.capacity = capacity;
    ht.size = 0;
    ht.table.assign(capacity, { Employee(), EMPTY });
}

int calculateHash(const string& key, int capacity) {
    int hashVal = 0;
    for (char c : key) {
        hashVal = (hashVal + c) % capacity;
    }
    return hashVal;
}

int findSlotIndex(const HashTable& ht, const string& key) {
    int index = calculateHash(key, ht.capacity);
    int startIndex = index;

    while (ht.table[index].status != EMPTY) {
        if (ht.table[index].status == OCCUPIED && ht.table[index].data.surnameInitials == key) {
            return index;
        }
        index = (index + 1) % ht.capacity;
        if (index == startIndex) break;
    }
    return -1;
}

bool insertEmployee(HashTable& ht, const Employee& emp) {
    if (ht.size >= ht.capacity) return false;

    int index = calculateHash(emp.surnameInitials, ht.capacity);
    int startIndex = index;

    while (ht.table[index].status == OCCUPIED) {
        if (ht.table[index].data.surnameInitials == emp.surnameInitials) return false;
        index = (index + 1) % ht.capacity;
        if (index == startIndex) return false;
    }

    ht.table[index].data = emp;
    ht.table[index].status = OCCUPIED;
    ht.size++;
    return true;
}

bool deleteEmployee(HashTable& ht, const string& key) {
    int index = findSlotIndex(ht, key);
    if (index != -1 && ht.table[index].status == OCCUPIED) {
        ht.table[index].status = DELETED;
        ht.size--;
        return true;
    }
    return false;
}

bool getEmployee(const HashTable& ht, const string& key, Employee& outEmp) {
    int index = findSlotIndex(ht, key);
    if (index != -1 && ht.table[index].status == OCCUPIED) {
        outEmp = ht.table[index].data;
        return true;
    }
    return false;
}

bool saveTableToFile(const HashTable& ht, const string& filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) return false;

    for (int i = 0; i < ht.capacity; ++i) {
        if (ht.table[i].status == OCCUPIED) {
            outFile << ht.table[i].data.surnameInitials << '\n'
                << ht.table[i].data.position << '\n'
                << ht.table[i].data.yearHired << '\n'
                << ht.table[i].data.salary << '\n';
        }
    }
    return true;
}

bool loadTableFromFile(HashTable& ht, const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) return false;

    initHashTable(ht, ht.capacity);
    Employee temp;
    while (getline(inFile, temp.surnameInitials)) {
        getline(inFile, temp.position);
        inFile >> temp.yearHired;
        inFile >> temp.salary;
        inFile.ignore(numeric_limits<streamsize>::max(), '\n');
        insertEmployee(ht, temp);
    }
    return true;
}