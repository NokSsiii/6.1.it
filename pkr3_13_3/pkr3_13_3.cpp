#include <iostream>
#include <string>
#include <limits>
#include "hashtable.h"
#include <locale>

using namespace std;

// ---------------------------------------------------------
// Функції для контролю помилок введення
// ---------------------------------------------------------

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int readInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value && value > 1900 && value <= 2100) {
            clearInputBuffer();
            return value;
        }
        cout << "Помилка вводу! Будь ласка, введіть коректний рік." << endl;
        clearInputBuffer();
    }
}

double readDouble(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= 0) {
            clearInputBuffer();
            return value;
        }
        cout << "Помилка вводу! Оклад має бути додатнім числом." << endl;
        clearInputBuffer();
    }
}

string readString(const string& prompt) {
    string value;
    cout << prompt;
    getline(cin, value);
    return value;
}

// ---------------------------------------------------------
// Функції виводу даних на екран
// ---------------------------------------------------------

void printEmployee(const Employee& emp) {
    cout << "---------------------------------" << endl;
    cout << "Прізвище та ініціали: " << emp.surnameInitials << endl;
    cout << "Посада:               " << emp.jobTitle << endl;
    cout << "Рік прийому:          " << emp.hireYear << endl;
    cout << "Оклад:                " << emp.salary << endl;
    cout << "---------------------------------" << endl;
}

void printAll(const HashTable& ht) {
    bool empty = true;
    for (int i = 0; i < ht.size; ++i) {
        HashNode* current = ht.table[i];
        while (current != nullptr) {
            printEmployee(current->data);
            current = current->next;
            empty = false;
        }
    }
    if (empty) {
        cout << "Хеш-таблиця порожня." << endl;
    }
}

// ---------------------------------------------------------
// Функції обробки дій користувача
// ---------------------------------------------------------

void handleAdd(HashTable& ht) {
    Employee emp;
    emp.surnameInitials = readString("Введіть прізвище та ініціали: ");
    emp.jobTitle = readString("Введіть посаду: ");
    emp.hireYear = readInt("Введіть рік прийому: ");
    emp.salary = readDouble("Введіть оклад: ");

    if (addEmployee(ht, emp)) {
        cout << "Службовця успішно додано!" << endl;
    }
    else {
        cout << "Помилка: Службовець з таким прізвищем вже існує." << endl;
    }
}

void handleRemove(HashTable& ht) {
    string key = readString("Введіть прізвище для видалення: ");
    if (removeEmployee(ht, key)) {
        cout << "Службовця успішно видалено." << endl;
    }
    else {
        cout << "Службовця не знайдено." << endl;
    }
}

void handleEdit(HashTable& ht) {
    string key = readString("Введіть прізвище службовця для редагування: ");
    if (findEmployeeNode(ht, key) == nullptr) {
        cout << "Службовця не знайдено." << endl;
        return;
    }

    Employee emp;
    emp.surnameInitials = key; // Ключ не змінюється
    emp.jobTitle = readString("Введіть НОВУ посаду: ");
    emp.hireYear = readInt("Введіть НОВИЙ рік прийому: ");
    emp.salary = readDouble("Введіть НОВИЙ оклад: ");

    if (editEmployee(ht, key, emp)) {
        cout << "Дані успішно оновлено!" << endl;
    }
}

void handleSearch(const HashTable& ht) {
    string key = readString("Введіть прізвище для пошуку: ");
    HashNode* node = findEmployeeNode(ht, key); // Виклик функції пошуку
    if (node != nullptr) {
        printEmployee(node->data);
    }
    else {
        cout << "Службовця не знайдено." << endl;
    }
}

// ---------------------------------------------------------
// Головне меню програми
// ---------------------------------------------------------

void runMenu(HashTable& ht) {
    int choice = 0;
    string filename;

    while (choice != 8) {
        cout << "\n=== МЕНЮ ===" << endl;
        cout << "1. Додати службовця" << endl;
        cout << "2. Видалити службовця" << endl;
        cout << "3. Редагувати дані" << endl;
        cout << "4. Знайти службовця за прізвищем" << endl;
        cout << "5. Переглянути всіх службовців" << endl;
        cout << "6. Зберегти у файл" << endl;
        cout << "7. Завантажити з файлу" << endl;
        cout << "8. Вихід" << endl;
        cout << "Ваш вибір: ";

        if (!(cin >> choice)) {
            clearInputBuffer();
            cout << "Некоректний ввід. Спробуйте ще раз." << endl;
            continue;
        }
        clearInputBuffer();

        switch (choice) {
        case 1: handleAdd(ht); break;
        case 2: handleRemove(ht); break;
        case 3: handleEdit(ht); break;
        case 4: handleSearch(ht); break;
        case 5: printAll(ht); break;
        case 6:
            filename = readString("Введіть ім'я файлу для збереження: ");
            if (saveToFile(ht, filename)) cout << "Успішно збережено!" << endl;
            else cout << "Помилка відкриття файлу для запису." << endl;
            break;
        case 7:
            filename = readString("Введіть ім'я файлу для завантаження: ");
            if (loadFromFile(ht, filename)) cout << "Успішно завантажено!" << endl;
            else cout << "Помилка відкриття файлу або файл не існує." << endl;
            break;
        case 8: cout << "Завершення роботи..." << endl; break;
        default: cout << "Невідома команда!" << endl;
        }
    }
}


int main() {
    setlocale(LC_ALL, "ukr");

    HashTable ht = createHashTable(10);

    runMenu(ht);

    destroyHashTable(ht);
    return 0;
}