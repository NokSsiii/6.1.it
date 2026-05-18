#include <iostream>
#include <Windows.h>
#include "EmployeeList.h"

void displayMenu() {
    std::cout << "\n--- МЕНЮ ---\n"
        << "1. Перегляд списку\n"
        << "2. Додати службовця\n"
        << "3. Видалити службовця\n"
        << "4. Редагувати дані\n"
        << "5. Пошук за прізвищем\n"
        << "6. Сортування списку\n"
        << "7. Зберегти у файл\n"
        << "8. Завантажити з файлу\n"
        << "0. Вихід\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Node* head = nullptr;
    int choice;

    do {
        displayMenu();
        choice = getIntInput("Оберіть дію: ", 0, 8);

        switch (choice) {
        case 1:
            printList(head);
            break;
        case 2: {
            Employee emp;
            emp.fullName = getStringInput("Введіть Прізвище та ініціали: ");
            emp.position = getStringInput("Введіть назву посади: ");
            emp.yearHired = getIntInput("Введіть рік прийому (1950-2026): ", 1950, 2026);
            emp.salary = getDoubleInput("Введіть оклад (> 0): ", 0.1, 1000000.0);
            addEmployee(head, emp);
            std::cout << "Успішно додано.\n";
            break;
        }
        case 3: {
            std::string name = getStringInput("Введіть ПІБ для видалення: ");
            if (removeEmployee(head, name)) std::cout << "Успішно видалено.\n";
            else std::cout << "Службовця не знайдено.\n";
            break;
        }
        case 4: {
            std::string oldName = getStringInput("Введіть старе ПІБ для редагування: ");
            if (searchEmployee(head, oldName)) {
                Employee newEmp;
                newEmp.fullName = getStringInput("Нове ПІБ: ");
                newEmp.position = getStringInput("Нова посада: ");
                newEmp.yearHired = getIntInput("Новий рік прийому: ", 1950, 2026);
                newEmp.salary = getDoubleInput("Новий оклад: ", 0.1, 1000000.0);
                editEmployee(head, oldName, newEmp);
                std::cout << "Дані оновлено.\n";
            }
            else {
                std::cout << "Службовця не знайдено.\n";
            }
            break;
        }
        case 5: {
            std::string name = getStringInput("Введіть ПІБ для пошуку: ");
            Node* found = searchEmployee(head, name);
            if (found) printEmployee(found->data);
            else std::cout << "Службовця не знайдено.\n";
            break;
        }
        case 6: {
            int crit = getIntInput("Сортувати за: 1 - ПІБ, 2 - Оклад, 3 - Рік прийому: ", 1, 3);
            sortList(head, crit);
            std::cout << "Список відсортовано.\n";
            break;
        }
        case 7: {
            std::string filename = getStringInput("Введіть ім'я файлу для збереження: ");
            if (saveToFile(head, filename)) std::cout << "Збережено.\n";
            else std::cout << "Помилка збереження.\n";
            break;
        }
        case 8: {
            std::string filename = getStringInput("Введіть ім'я файлу для завантаження: ");
            if (loadFromFile(head, filename)) std::cout << "Завантажено.\n";
            else std::cout << "Помилка завантаження файлу.\n";
            break;
        }
        }
    } while (choice != 0);

    clearList(head);
    return 0;
}