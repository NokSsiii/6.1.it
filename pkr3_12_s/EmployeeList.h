#pragma once
#include <string>

struct Employee {
    std::string fullName;
    std::string position;
    int yearHired;
    double salary;
};
\
struct Node {
    Employee data;
    Node* next;
    Node* prev;
};

void addEmployee(Node*& head, const Employee& emp);
Node* searchEmployee(Node* head, const std::string& fullName);
bool removeEmployee(Node*& head, const std::string& fullName);
bool editEmployee(Node* head, const std::string& oldFullName, const Employee& newEmp);
void sortList(Node* head, int criteria); 
bool saveToFile(Node* head, const std::string& filename);
bool loadFromFile(Node*& head, const std::string& filename);
void clearList(Node*& head);

int getIntInput(const std::string& prompt, int min, int max);
double getDoubleInput(const std::string& prompt, double min, double max);
std::string getStringInput(const std::string& prompt);
void printEmployee(const Employee& emp);
void printList(Node* head);