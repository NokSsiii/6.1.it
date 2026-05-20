#pragma once
#include <string>
#include <map>
#include <fstream>

struct Employee {
    std::string surname_initials;
    std::string position;
    int year;
    double salary;
};

struct TrieNode {
    std::map<char, TrieNode*> children;
    bool isEndOfWord;
    Employee data;

    TrieNode();
};

void clearInputBuffer();
int getValidInt(const std::string& prompt);
double getValidDouble(const std::string& prompt);
std::string getValidString(const std::string& prompt);

// Операції з деревом
void insertEmployee(TrieNode* root, const Employee& emp);
bool searchEmployee(TrieNode* root, const std::string& surname, Employee& result);
bool editEmployee(TrieNode* root, const std::string& surname, const Employee& newData);
bool deleteEmployeeHelper(TrieNode* current, const std::string& key, int depth);
void deleteEmployee(TrieNode* root, const std::string& surname);

// Виведення та файли
void printEmployee(const Employee& emp);
void traverseAndPrint(TrieNode* current);
void traverseAndSave(TrieNode* current, std::ofstream& outFile);
bool saveToFile(TrieNode* root, const std::string& filename);
bool loadFromFile(TrieNode* root, const std::string& filename);

void freeTree(TrieNode* current);