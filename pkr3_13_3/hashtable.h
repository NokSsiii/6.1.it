#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>

// Структура, що описує службовця
struct Employee {
    std::string surnameInitials; // Прізвище і ініціали (ключ)
    std::string jobTitle;        // Назва посади
    int hireYear;                // Рік прийому на роботу
    double salary;               // Оклад
};

// Вузол відкритої хеш-таблиці (елемент ланцюжка)
struct HashNode {
    Employee data;
    HashNode* next;
};

// хеш-таблиця
struct HashTable {
    HashNode** table;
    int size;
};

// Оголошення функцій роботи з хеш-таблицею (логіка)
HashTable createHashTable(int size);
void destroyHashTable(HashTable& ht);
int calculateHash(const std::string& key, int tableSize);

// Функція шукає вузол і повертає його (не виводить нічого на екран за умовою)
HashNode* findEmployeeNode(const HashTable& ht, const std::string& key);

bool addEmployee(HashTable& ht, const Employee& emp);
bool removeEmployee(HashTable& ht, const std::string& key);
bool editEmployee(HashTable& ht, const std::string& key, const Employee& newData);

bool saveToFile(const HashTable& ht, const std::string& filename);
bool loadFromFile(HashTable& ht, const std::string& filename);

#endif 