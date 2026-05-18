#include <iostream>
#include <string>
#include <Windows.h>
#include "FlightTree.h"

void printMenu() {
    std::cout << "\n========== МЕНЮ (ЧИСТЕ ДЕРЕВО) ==========\n"
        << "1. Додати нову заявку\n"
        << "2. Видалити конкретну заявку\n"
        << "3. Вивести всі заявки (Сортований In-order вигляд)\n"
        << "4. Балансувати дерево (Без масивів!)\n"
        << "5. Вивести та видалити заявки за Рейсом і Датою\n"
        << "6. Зберегти у файл\n"
        << "7. Завантажити з файлу\n"
        << "0. Вихід\n"
        << "Введіть вибір: ";
}

int getValidatedChoice() {
    int choice;
    while (!(std::cin >> choice)) {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Помилка! Введіть число: ";
    }
    std::cin.ignore(10000, '\n');
    return choice;
}

std::string getNonEmptyString(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (!input.empty()) return input;
        std::cout << "Поле не може бути порожнім!\n";
    }
}

// Чистий рекурсивний друк без проміжних контейнерів
void printTreeInOrder(TreeNode* root) {
    if (!root) return;
    printTreeInOrder(root->left);
    std::cout << " " << root->data.passengerName << " | "
        << root->data.flightNumber << " | "
        << root->data.departureDate << " | "
        << root->data.destination << "\n";
    printTreeInOrder(root->right);
}

void displayTree(TreeNode* root) {
    if (!root) {
        std::cout << "Дерево порожнє.\n";
        return;
    }
    std::cout << "\n------------------------------------------------------------\n";
    std::cout << " Прізвище І.О.   | Рейс   | Дата вильоту | Пункт призначення \n";
    std::cout << "------------------------------------------------------------\n";
    printTreeInOrder(root);
    std::cout << "------------------------------------------------------------\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    TreeNode* mainTree = nullptr;
    int choice;

    do {
        printMenu();
        choice = getValidatedChoice();

        switch (choice) {
        case 1: {
            TicketRequest req;
            req.passengerName = getNonEmptyString("ПІБ пасажира: ");
            req.flightNumber = getNonEmptyString("Номер рейсу: ");
            req.departureDate = getNonEmptyString("Дата (РРРР-ММ-ДД): ");
            req.destination = getNonEmptyString("Пункт призначення: ");
            insertNode(mainTree, req);
            std::cout << "Успішно додано.\n";
            break;
        }
        case 2: {
            TicketRequest req;
            req.passengerName = getNonEmptyString("ПІБ: ");
            req.flightNumber = getNonEmptyString("Рейс: ");
            req.departureDate = getNonEmptyString("Дата: ");
            bool success = false;
            mainTree = removeNode(mainTree, req, success);
            if (success) std::cout << "Успішно видалено.\n";
            else std::cout << "Заявку не знайдено.\n";
            break;
        }
        case 3:
            displayTree(mainTree);
            break;
        case 4:
            balanceTree(mainTree);
            std::cout << "Дерево збалансовано in-place за допомогою покажчиків!\n";
            break;
        case 5: {
            std::string flight = getNonEmptyString("Введіть номер рейсу: ");
            std::string date = getNonEmptyString("Введіть дату: ");

            // Отримуємо нове окреме дерево з вилученими елементами
            TreeNode* extracted = extractAndRemoveByFlightAndDate(mainTree, flight, date);

            std::cout << "\nВилучені заявки:";
            displayTree(extracted);

            clearTree(extracted); // Очищуємо пам'ять вилучених заявок
            break;
        }
        case 6: {
            std::string filename = getNonEmptyString("Ім'я файлу для збереження: ");
            if (saveToFile(mainTree, filename)) std::cout << "Збережено.\n";
            else std::cout << "Помилка файлу.\n";
            break;
        }
        case 7: {
            std::string filename = getNonEmptyString("Ім'я файлу для завантаження: ");
            if (loadFromFile(mainTree, filename)) std::cout << "Завантажено.\n";
            else std::cout << "Помилка читання.\n";
            break;
        }
        case 0:
            std::cout << "Вихід.\n";
            break;
        default:
            std::cout << "Невірний пункт.\n";
        }
    } while (choice != 0);

    clearTree(mainTree);
    return 0;
}