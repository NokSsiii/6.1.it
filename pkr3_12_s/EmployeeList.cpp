#include "EmployeeList.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <algorithm>

// Додавання в кінець списку
void addEmployee(Node*& head, const Employee& emp) {
    Node* newNode = new Node{ emp, nullptr, nullptr };
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Пошук (повертає вказівник на вузол, нічого не виводить на екран)
Node* searchEmployee(Node* head, const std::string& fullName) {
    Node* temp = head;
    while (temp) {
        if (temp->data.fullName == fullName) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

// Вилучення елемента
bool removeEmployee(Node*& head, const std::string& fullName) {
    Node* target = searchEmployee(head, fullName);
    if (!target) return false;

    if (target->prev) target->prev->next = target->next;
    else head = target->next;

    if (target->next) target->next->prev = target->prev;

    delete target;
    return true;
}

// Редагування даних
bool editEmployee(Node* head, const std::string& oldFullName, const Employee& newEmp) {
    Node* target = searchEmployee(head, oldFullName);
    if (!target) return false;

    target->data = newEmp;
    return true;
}

// Сортування методом бульбашки (зміна самих даних всередині вузлів)
void sortList(Node* head, int criteria) {
    if (!head || !head->next) return;

    bool swapped;
    Node* ptr1;
    Node* lptr = nullptr;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            bool condition = false;
            if (criteria == 1) condition = ptr1->data.fullName > ptr1->next->data.fullName;
            else if (criteria == 2) condition = ptr1->data.salary > ptr1->next->data.salary;
            else if (criteria == 3) condition = ptr1->data.yearHired > ptr1->next->data.yearHired;

            if (condition) {
                std::swap(ptr1->data, ptr1->next->data);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Збереження у файл
bool saveToFile(Node* head, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) return false;

    Node* temp = head;
    while (temp) {
        file << temp->data.fullName << '\n'
            << temp->data.position << '\n'
            << temp->data.yearHired << '\n'
            << temp->data.salary << '\n';
        temp = temp->next;
    }
    file.close();
    return true;
}

// Звільнення пам'яті
void clearList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Завантаження з файлу
bool loadFromFile(Node*& head, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return false;

    clearList(head);
    Employee emp;
    std::string yearStr, salaryStr;

    while (std::getline(file, emp.fullName)) {
        std::getline(file, emp.position);
        std::getline(file, yearStr);
        std::getline(file, salaryStr);

        try {
            emp.yearHired = std::stoi(yearStr);
            emp.salary = std::stod(salaryStr);
            addEmployee(head, emp);
        }
        catch (...) {
            return false;
        }
    }
    file.close();
    return true;
}

// Валідація цілих чисел
int getIntInput(const std::string& prompt, int min, int max) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value >= min && value <= max) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Помилка вводу. Спробуйте ще раз.\n";
    }
}

// Валідація чисел з плаваючою крапкою
double getDoubleInput(const std::string& prompt, double min, double max) {
    double value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value && value >= min && value <= max) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Помилка вводу. Спробуйте ще раз.\n";
    }
}

// Безпечне введення рядків із пробілами
std::string getStringInput(const std::string& prompt) {
    std::string value;
    std::cout << prompt;
    std::getline(std::cin, value);
    return value;
}

// Вивід одного елемента
void printEmployee(const Employee& emp) {
    std::cout << "ПІБ: " << emp.fullName
        << " | Посада: " << emp.position
        << " | Рік: " << emp.yearHired
        << " | Оклад: " << emp.salary << " грн\n";
}

// Вивід усього списку
void printList(Node* head) {
    if (!head) {
        std::cout << "Список порожній.\n";
        return;
    }
    Node* temp = head;
    while (temp) {
        printEmployee(temp->data);
        temp = temp->next;
    }
}