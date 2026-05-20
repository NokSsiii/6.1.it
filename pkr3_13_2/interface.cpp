#include "interface.h"
#include <iostream>
#include <limits>

using namespace std;

// --- ВАЛІДАЦІЯ ---
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int getValidInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) { clearInputBuffer(); return value; }
        cout << "Помилка: введіть коректне ціле число.\n";
        clearInputBuffer();
    }
}

double getValidDouble(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value) { clearInputBuffer(); return value; }
        cout << "Помилка: введіть коректне числове значення.\n";
        clearInputBuffer();
    }
}

string getValidString(const string& prompt) {
    string value;
    cout << prompt;
    getline(cin, value);
    return value;
}

// --- ІНТЕРФЕЙС ---
void displayEmployee(const Employee& emp) {
    cout << "-----------------------------------\n";
    cout << "Прізвище та ініціали: " << emp.surnameInitials << "\n"
        << "Посада:               " << emp.position << "\n"
        << "Рік прийому:          " << emp.yearHired << "\n"
        << "Оклад:                " << emp.salary << " грн\n"
        << "-----------------------------------\n";
}

void displayAllEmployees(const HashTable& ht) {
    if (ht.size == 0) { cout << "\nТаблиця порожня.\n"; return; }
    cout << "\n=== СПИСОК УСІХ СЛУЖБОВЦІВ ===\n";
    for (int i = 0; i < ht.capacity; ++i) {
        if (ht.table[i].status == OCCUPIED) displayEmployee(ht.table[i].data);
    }
}

void handleAddEmployee(HashTable& ht) {
    Employee emp;
    emp.surnameInitials = getValidString("Введіть Прізвище та ініціали: ");
    emp.position = getValidString("Введіть посаду: ");
    emp.yearHired = getValidInt("Введіть рік прийому на роботу: ");
    emp.salary = getValidDouble("Введіть оклад (грн): ");

    if (insertEmployee(ht, emp)) cout << ">> Успішно додано!\n";
    else cout << ">> Помилка: Запис існує або таблиця заповнена.\n";
}

void handleDeleteEmployee(HashTable& ht) {
    string key = getValidString("Введіть Прізвище та ініціали: ");
    if (deleteEmployee(ht, key)) cout << ">> Успішно вилучено!\n";
    else cout << ">> Помилка: Не знайдено.\n";
}

void handleEditEmployee(HashTable& ht) {
    string key = getValidString("Введіть Прізвище для редагування: ");
    if (deleteEmployee(ht, key)) {
        cout << "Введіть нові дані:\n";
        handleAddEmployee(ht);
    }
    else cout << ">> Помилка: Не знайдено.\n";
}

void handleFindEmployee(const HashTable& ht) {
    string key = getValidString("Введіть Прізвище для пошуку: ");
    Employee emp;
    if (getEmployee(ht, key, emp)) displayEmployee(emp);
    else cout << ">> Помилка: Не знайдено.\n";
}

void handleSaveToFile(const HashTable& ht) {
    string filename = getValidString("Ім'я файлу для збереження: ");
    if (saveTableToFile(ht, filename)) cout << ">> Збережено!\n";
    else cout << ">> Помилка збереження!\n";
}

void handleLoadFromFile(HashTable& ht) {
    string filename = getValidString("Ім'я файлу для завантаження: ");
    if (loadTableFromFile(ht, filename)) cout << ">> Завантажено!\n";
    else cout << ">> Помилка завантаження!\n";
}

void showMenu() {
    cout << "\n=== МЕНЮ ===\n"
        << "1. Додати службовця\n"
        << "2. Вилучити службовця\n"
        << "3. Редагувати дані\n"
        << "4. Знайти за прізвищем\n"
        << "5. Переглянути всіх\n"
        << "6. Зберегти у файл\n"
        << "7. Завантажити з файлу\n"
        << "0. Вийти\n"
        << "============\n";
}