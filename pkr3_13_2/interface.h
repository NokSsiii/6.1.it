#ifndef INTERFACE_H
#define INTERFACE_H

#include "hash_table.h"
#include <string>

// --- ‘”Õ ÷≤Ø ¬¿À≤ƒ¿÷≤Ø ---
void clearInputBuffer();
int getValidInt(const std::string& prompt);
double getValidDouble(const std::string& prompt);
std::string getValidString(const std::string& prompt);

// --- ‘”Õ ÷≤Ø ≤Õ“≈–‘≈…—” ---
void showMenu();
void displayAllEmployees(const HashTable& ht);
void handleAddEmployee(HashTable& ht);
void handleDeleteEmployee(HashTable& ht);
void handleEditEmployee(HashTable& ht);
void handleFindEmployee(const HashTable& ht);
void handleSaveToFile(const HashTable& ht);
void handleLoadFromFile(HashTable& ht);

#endif // INTERFACE_H