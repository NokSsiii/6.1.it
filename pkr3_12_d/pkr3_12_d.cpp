#include <iostream>
#include <Windows.h>
#include "EmployeeTree.h"

void displayMenu() {
    std::cout << "\n--- МЕНЮ (БІНАРНЕ ДЕРЕВО) ---\n"
        << "1. Перегляд дерева (в алфавітному порядку ПІБ)\n"
        << "2. Додати службовця\n"
        << "3. Видалити службовця\n"
        << "4. Редагувати дані\n"
        << "5. Пошук за прізвищем\n"
        << "6. Сортування та виведення даних (In-Place)\n"
        << "7. Балансування дерева\n"
        << "8. Зберегти у файл\n"
        << "9. Завантажити з файлу\n"
        << "0. Вихід\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Node* root = nullptr;
    int choice;

    do {
        displayMenu();
        choice = getIntInput("Оберіть дію: ", 0, 9);

        switch (choice) {
        case 1:
            if (!root) std::cout << "Дерево порожнє.\n";
            else printTreeInOrder(root);
            break;
        case 2: {
            Employee emp;
            emp.fullName = getStringInput("Введіть Прізвище та ініціали: ");
            emp.position = getStringInput("Введіть назву посади: ");
            emp.yearHired = getIntInput("Введіть рік прийому (1950-2026): ", 1950, 2026);
            emp.salary = getDoubleInput("Введіть оклад (> 0): ", 0.1, 1000000.0);
            addEmployee(root, emp);
            std::cout << "Успішно додано.\n";
            break;
        }
        case 3: {
            std::string name = getStringInput("Введіть ПІБ для видалення: ");
            if (removeEmployee(root, name)) std::cout << "Успішно видалено.\n";
            else std::cout << "Службовця не знайдено.\n";
            break;
        }
        case 4: {
            std::string oldName = getStringInput("Введіть старе ПІБ для редагування: ");
            if (searchEmployee(root, oldName)) {
                Employee newEmp;
                newEmp.fullName = getStringInput("Нове ПІБ: ");
                newEmp.position = getStringInput("Нова посада: ");
                newEmp.yearHired = getIntInput("Новий рік прийому: ", 1950, 2026);
                newEmp.salary = getDoubleInput("Новий оклад: ", 0.1, 1000000.0);
                editEmployee(root, oldName, newEmp);
                std::cout << "Дані оновлено.\n";
            }
            else {
                std::cout << "Службовця не знайдено.\n";
            }
            break;
        }
        case 5: {
            std::string name = getStringInput("Введіть ПІБ для пошуку: ");
            Node* found = searchEmployee(root, name);
            if (found) printEmployee(found->data);
            else std::cout << "Службовця не знайдено.\n";
            break;
        }
        case 6: {
            int crit = getIntInput("Сортувати за: 1 - ПІБ, 2 - Оклад, 3 - Рік прийому: ", 1, 3);
            sortAndPrint(root, crit);
            break;
        }
        case 7:
            balanceTree(root);
            std::cout << "Дерево успішно збалансовано (Алгоритм DSW).\n";
            break;
        case 8: {
            std::string filename = getStringInput("Введіть ім'я файлу для збереження: ");
            if (saveToFile(root, filename)) std::cout << "Збережено.\n";
            else std::cout << "Помилка збереження.\n";
            break;
        }
        case 9: {
            std::string filename = getStringInput("Введіть ім'я файлу для завантаження: ");
            if (loadFromFile(root, filename)) std::cout << "Завантажено та збалансовано.\n";
            else std::cout << "Помилка завантаження файлу.\n";
            break;
        }
        }
    } while (choice != 0);

    clearTree(root);
    return 0;
}