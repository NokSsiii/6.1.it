#pragma once
#include <string>

struct Employee {
    std::string fullName;
    std::string position;
    int yearHired;
    double salary;
};

struct Node {
    Employee data;
    Node* left;
    Node* right;
};

void addEmployee(Node*& root, const Employee& emp);
Node* searchEmployee(Node* root, const std::string& fullName);
bool removeEmployee(Node*& root, const std::string& fullName);
bool editEmployee(Node*& root, const std::string& oldFullName, const Employee& newEmp);
void clearTree(Node*& root);

void balanceTree(Node*& root);
void sortAndPrint(Node*& root, int criteria);

bool saveToFile(Node* root, const std::string& filename);
bool loadFromFile(Node*& root, const std::string& filename);

int getIntInput(const std::string& prompt, int min, int max);
double getDoubleInput(const std::string& prompt, double min, double max);
std::string getStringInput(const std::string& prompt);
void printEmployee(const Employee& emp);
void printTreeInOrder(Node* root);