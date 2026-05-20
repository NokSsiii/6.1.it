#include "EmployeeTrie.h"
#include <iostream>
#include <limits>

using namespace std;

TrieNode::TrieNode() : isEndOfWord(false) {}

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int getValidInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value && value > 1900 && value <= 2100) {
            clearInputBuffer();
            return value;
        }
        cout << "Помилка: введіть коректний рік!\n";
        clearInputBuffer();
    }
}

double getValidDouble(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= 0) {
            clearInputBuffer();
            return value;
        }
        cout << "Помилка: введіть коректну суму!\n";
        clearInputBuffer();
    }
}

string getValidString(const string& prompt) {
    string value;
    while (true) {
        cout << prompt;
        getline(cin, value);
        if (!value.empty()) return value;
        cout << "Помилка: рядок не може бути порожнім!\n";
    }
}

void insertEmployee(TrieNode* root, const Employee& emp) {
    TrieNode* current = root;
    for (char ch : emp.surname_initials) {
        if (current->children.find(ch) == current->children.end()) {
            current->children[ch] = new TrieNode();
        }
        current = current->children[ch];
    }
    current->isEndOfWord = true;
    current->data = emp;
}

bool searchEmployee(TrieNode* root, const string& surname, Employee& result) {
    TrieNode* current = root;
    for (char ch : surname) {
        if (current->children.find(ch) == current->children.end()) return false;
        current = current->children[ch];
    }
    if (current != nullptr && current->isEndOfWord) {
        result = current->data;
        return true;
    }
    return false;
}

bool editEmployee(TrieNode* root, const string& surname, const Employee& newData) {
    TrieNode* current = root;
    for (char ch : surname) {
        if (current->children.find(ch) == current->children.end()) return false;
        current = current->children[ch];
    }
    if (current != nullptr && current->isEndOfWord) {
        current->data = newData;
        return true;
    }
    return false;
}

bool deleteEmployeeHelper(TrieNode* current, const string& key, int depth) {
    if (current == nullptr) return false;
    if (depth == key.length()) {
        if (!current->isEndOfWord) return false;
        current->isEndOfWord = false;
        return current->children.empty();
    }
    char ch = key[depth];
    if (current->children.find(ch) == current->children.end()) return false;
    bool shouldDeleteChild = deleteEmployeeHelper(current->children[ch], key, depth + 1);
    if (shouldDeleteChild) {
        delete current->children[ch];
        current->children.erase(ch);
        return current->children.empty() && !current->isEndOfWord;
    }
    return false;
}

void deleteEmployee(TrieNode* root, const string& surname) {
    deleteEmployeeHelper(root, surname, 0);
}

void printEmployee(const Employee& emp) {
    cout << "----------------------------------------\n"
        << "Прізвище:    " << emp.surname_initials << "\n"
        << "Посада:      " << emp.position << "\n"
        << "Рік прийому: " << emp.year << "\n"
        << "Оклад:       " << emp.salary << "\n";
}

void traverseAndPrint(TrieNode* current) {
    if (current == nullptr) return;
    if (current->isEndOfWord) printEmployee(current->data);
    for (auto const& pair : current->children) traverseAndPrint(pair.second);
}

void traverseAndSave(TrieNode* current, ofstream& outFile) {
    if (current == nullptr) return;
    if (current->isEndOfWord) {
        outFile << current->data.surname_initials << '\n'
            << current->data.position << '\n'
            << current->data.year << '\n'
            << current->data.salary << '\n';
    }
    for (auto const& pair : current->children) traverseAndSave(pair.second, outFile);
}

bool saveToFile(TrieNode* root, const string& filename) {
    ofstream outFile(filename);
    if (!outFile.is_open()) return false;
    traverseAndSave(root, outFile);
    return true;
}

bool loadFromFile(TrieNode* root, const string& filename) {
    ifstream inFile(filename);
    if (!inFile.is_open()) return false;
    Employee emp;
    string yearStr, salaryStr;
    while (getline(inFile, emp.surname_initials)) {
        if (emp.surname_initials.empty()) continue;
        getline(inFile, emp.position);
        getline(inFile, yearStr);
        emp.year = stoi(yearStr);
        getline(inFile, salaryStr);
        emp.salary = stod(salaryStr);
        insertEmployee(root, emp);
    }
    return true;
}

void freeTree(TrieNode* current) {
    if (current == nullptr) return;
    for (auto const& pair : current->children) freeTree(pair.second);
    delete current;
}