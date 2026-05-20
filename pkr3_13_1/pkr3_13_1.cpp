#include <iostream>
#include <string>
#include "EmployeeTrie.h"

using namespace std;

// Функція для відображення меню
void displayMenu() {
    cout << "\n=========== МЕНЮ ===========\n"
        << "1. Додати службовця\n"
        << "2. Знайти службовця\n"
        << "3. Видалити службовця\n"
        << "4. Редагувати дані службовця\n"
        << "5. Переглянути всіх службовців\n"
        << "6. Зберегти у файл\n"
        << "7. Завантажити з файлу\n"
        << "0. Вихід\n"
        << "============================\n";
}

int main() {
    // Встановлення кодування UTF-8 для коректного відображення кирилиці в консолі Windows
    system("chcp 65001 > nul");

    // Створення кореня префіксного дерева
    TrieNode* root = new TrieNode();
    bool running = true;

    while (running) {
        displayMenu();
        int choice = getValidInt("Оберіть дію (0-7): ");

        switch (choice) {
        case 1: {
            Employee emp;
            emp.surname_initials = getValidString("Введіть прізвище та ініціали: ");
            emp.position = getValidString("Введіть посаду: ");
            emp.year = getValidInt("Введіть рік прийому на роботу: ");
            emp.salary = getValidDouble("Введіть оклад: ");

            insertEmployee(root, emp);
            cout << "[Успіх] Службовця додано.\n";
            break;
        }
        case 2: {
            string searchName = getValidString("Введіть прізвище для пошуку: ");
            Employee foundEmp;

            if (searchEmployee(root, searchName, foundEmp)) {
                cout << "\n[Результат пошуку]:\n";
                printEmployee(foundEmp);
            }
            else {
                cout << "[Помилка] Службовця не знайдено.\n";
            }
            break;
        }
        case 3: {
            string delName = getValidString("Введіть прізвище для видалення: ");
            Employee temp;

            // Спочатку перевіряємо, чи існує такий запис
            if (searchEmployee(root, delName, temp)) {
                deleteEmployee(root, delName);
                cout << "[Успіх] Службовця видалено.\n";
            }
            else {
                cout << "[Помилка] Службовця не знайдено.\n";
            }
            break;
        }
        case 4: {
            string editName = getValidString("Введіть прізвище для редагування: ");
            Employee currentEmp;

            if (searchEmployee(root, editName, currentEmp)) {
                cout << "Службовця знайдено. Введіть нові дані:\n";
                Employee newEmp;

                // Ключ (прізвище) залишаємо старим, щоб не ламати структуру дерева.
                // Редагуємо лише інші поля.
                newEmp.surname_initials = editName;
                newEmp.position = getValidString("Введіть нову посаду: ");
                newEmp.year = getValidInt("Введіть новий рік прийому: ");
                newEmp.salary = getValidDouble("Введіть новий оклад: ");

                editEmployee(root, editName, newEmp);
                cout << "[Успіх] Дані оновлено.\n";
            }
            else {
                cout << "[Помилка] Службовця не знайдено.\n";
            }
            break;
        }
        case 5: {
            cout << "\n--- Список всіх службовців ---\n";
            traverseAndPrint(root);
            cout << "----------------------------------------\n";
            break;
        }
        case 6: {
            string filename = getValidString("Введіть ім'я файлу для збереження (напр., data.txt): ");

            if (saveToFile(root, filename)) {
                cout << "[Успіх] Дані збережено у файл " << filename << ".\n";
            }
            else {
                cout << "[Помилка] Не вдалося відкрити файл для запису.\n";
            }
            break;
        }
        case 7: {
            string filename = getValidString("Введіть ім'я файлу для завантаження: ");

            if (loadFromFile(root, filename)) {
                cout << "[Успіх] Дані завантажено з файлу " << filename << ".\n";
            }
            else {
                cout << "[Помилка] Не вдалося відкрити файл (можливо він не існує).\n";
            }
            break;
        }
        case 0:
            running = false;
            break;
        default:
            cout << "[Помилка] Невідома команда. Будь ласка, оберіть число від 0 до 7.\n";
            break;
        }
    }

    freeTree(root);
    cout << "Програму завершено.\n";

    return 0;
}