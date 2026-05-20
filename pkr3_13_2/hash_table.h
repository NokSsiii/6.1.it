#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string>
#include <vector>

// --- —“–” “”–» ƒ¿Õ»’ ---
enum SlotStatus { EMPTY, OCCUPIED, DELETED };

struct Employee {
    std::string surnameInitials;
    std::string position;
    int yearHired;
    double salary;
};

struct HashSlot {
    Employee data;
    SlotStatus status;
};

struct HashTable {
    std::vector<HashSlot> table;
    int capacity;
    int size;
};

// --- ‘”Õ ÷≤Ø ÀŒ√≤ » “¿ ‘¿…À≤¬ ---
void initHashTable(HashTable& ht, int capacity);
int calculateHash(const std::string& key, int capacity);
int findSlotIndex(const HashTable& ht, const std::string& key);
bool insertEmployee(HashTable& ht, const Employee& emp);
bool deleteEmployee(HashTable& ht, const std::string& key);
bool getEmployee(const HashTable& ht, const std::string& key, Employee& outEmp);

bool saveTableToFile(const HashTable& ht, const std::string& filename);
bool loadTableFromFile(HashTable& ht, const std::string& filename);

#endif 