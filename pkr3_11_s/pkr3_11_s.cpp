#include <iostream>
#include <string>
#include "FlightTicket.h"
#include <windows.h>

void printMenu() {
    std::cout << "\n================ МЕНЮ ================\n"
        << "1. Додати нову заявку\n"
        << "2. Видалити заявку за ПІБ та рейсом\n"
        << "3. Вивести всі заявки\n"
        << "4. Сортувати заявки за номером рейсу\n"
        << "5. Вивести та видалити заявки за Рейсом і Датою\n"
        << "6. Зберегти дані у файл\n"
        << "7. Завантажити дані з файлу\n"
        << "0. Вихід\n"
        << "Введіть ваш вибір: ";
}

// Безпечне введення цілого числа для меню
int getValidatedChoice() {
    int choice;
    while (!(std::cin >> choice)) {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Помилка введення! Будь ласка, введіть число: ";
    }
    std::cin.ignore(10000, '\n'); // Очищення буфера
    return choice;
}

// Валідація непорожнього рядка
std::string getNonEmptyString(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (!input.empty()) return input;
        std::cout << "Помилка! Поле не може бути порожнім.\n";
    }
}

// Виведення списку на екран
void displayList(const TicketRequest* head) {
    if (!head) {
        std::cout << "Список заявок порожній.\n";
        return;
    }
    std::cout << "\n------------------------------------------------------------\n";
    std::cout << " Прізвище І.О.   | Рейс   | Дата вильоту | Пункт призначення \n";
    std::cout << "------------------------------------------------------------\n";
    while (head) {
        std::cout << " " << head->passengerName << " | "
            << head->flightNumber << " | "
            << head->departureDate << " | "
            << head->destination << "\n";
        head = head->next;
    }
    std::cout << "------------------------------------------------------------\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    // Встановлення кодування для коректного виведення в консолі (Windows)
    std::setlocale(LC_ALL, "Ukrainian");

    TicketRequest* mainList = nullptr;
    int choice;

    do {
        printMenu();
        choice = getValidatedChoice();

        switch (choice) {
        case 1: {
            TicketRequest req;
            req.passengerName = getNonEmptyString("Введіть ПІБ пасажира: ");
            req.flightNumber = getNonEmptyString("Введіть номер рейсу: ");
            req.departureDate = getNonEmptyString("Введіть дату вильоту (РРРР-ММ-ДД): ");
            req.destination = getNonEmptyString("Введіть пункт призначення: ");

            addRequest(mainList, req);
            std::cout << "Заявку успішно додано!\n";
            break;
        }
        case 2: {
            std::string name = getNonEmptyString("Введіть ПІБ для видалення: ");
            std::string flight = getNonEmptyString("Введіть номер рейсу: ");
            if (deleteRequest(mainList, name, flight)) {
                std::cout << "Заявку видалено.\n";
            }
            else {
                std::cout << "Заявку не знайдено за вказаними даними.\n";
            }
            break;
        }
        case 3:
            displayList(mainList);
            break;
        case 4:
            sortListByFlight(mainList);
            std::cout << "Список успішно відсортовано за номером рейсу.\n";
            break;
        case 5: {
            std::string flight = getNonEmptyString("Введіть потрібний номер рейсу: ");
            std::string date = getNonEmptyString("Введіть бажану дату: ");

            // Виклик логічної функції, яка НЕ друкує сама, а повертає вилучений підсписок
            TicketRequest* extracted = extractAndRemoveByFlightAndDate(mainList, flight, date);

            std::cout << "\nЗнайдені заявки (які зараз видаляються з бази):\n";
            displayList(extracted);

            clearList(extracted); // Очищення вилучених елементів з пам'яті
            break;
        }
        case 6: {
            std::string filename = getNonEmptyString("Введіть ім'я файлу для збереження: ");
            if (saveToFile(mainList, filename)) {
                std::cout << "Дані успішно збережено у файл " << filename << "\n";
            }
            else {
                std::cout << "Помилка відкриття файлу для запису!\n";
            }
            break;
        }
        case 7: {
            std::string filename = getNonEmptyString("Введіть ім'я файлу для завантаження: ");
            if (loadFromFile(mainList, filename)) {
                std::cout << "Дані успішно зчитано з файлу!\n";
            }
            else {
                std::cout << "Помилка! Не вдалося відкрити або прочитати файл.\n";
            }
            break;
        }
        case 0:
            std::cout << "Завершення роботи програми.\n";
            break;
        default:
            std::cout << "Неправильний пункт меню. Спробуйте ще раз.\n";
        }
    } while (choice != 0);

    clearList(mainList); // Звільнення динамічної пам'яті перед виходом
    return 0;
}