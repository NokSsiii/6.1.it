#include <iostream>
#include <string>
#include <map>
#include <limits>
#define NOMINMAX
#include <Windows.h> 

using namespace std;

// Структура для зберігання даних про друга
struct Friend {
    string lastName;
    string firstName;
    string phoneNumber;
    int birthDate[3]; // [0] - день, [1] - місяць, [2] - рік
};

// Підпрограма для безпечного вводу цілих чисел із перевіркою діапазону та типу
int getValidInt(int minVal, int maxVal) {
    int value;
    while (true) {
        cin >> value;
        // Якщо введено не число або число поза діапазоном
        if (cin.fail() || value < minVal || value > maxVal) {
            cin.clear(); // Скидаємо прапорець помилки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищуємо буфер
            cout << "Помилка! Введіть значення від " << minVal << " до " << maxVal << ": ";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

// Підпрограма для додавання запису в колекцію
void addRecord(map<int, Friend>& phoneBook) {
    Friend temp;
    cout << "Введіть прізвище: ";
    cin >> temp.lastName;
    cout << "Введіть ім'я: ";
    cin >> temp.firstName;
    cout << "Введіть номер телефону: ";
    cin >> temp.phoneNumber;

    cout << "Дата народження - День (1-31): ";
    temp.birthDate[0] = getValidInt(1, 31);
    cout << "Дата народження - Місяць (1-12): ";
    temp.birthDate[1] = getValidInt(1, 12);
    cout << "Дата народження - Рік (1900-2026): ";
    temp.birthDate[2] = getValidInt(1900, 2026);

    // Використовуємо поточний розмір як унікальний ключ
    int pos = phoneBook.size();
    phoneBook.insert({ pos, temp });

    cout << "--- Запис успішно додано! ---" << endl;
}

// Підпрограма для перегляду всієї колекції
void displayAll(const map<int, Friend>& phoneBook) {
    if (phoneBook.empty()) {
        cout << "Колекція наразі порожня!" << endl;
        return;
    }

    for (map<int, Friend>::const_iterator it = phoneBook.begin(); it != phoneBook.end(); ++it) {
        cout << "-----------------------" << endl;
        cout << "Прізвище: " << it->second.lastName << endl;
        cout << "Ім'я: " << it->second.firstName << endl;
        cout << "Телефон: " << it->second.phoneNumber << endl;
        cout << "Дата народження: "
            << it->second.birthDate[0] << "."
            << it->second.birthDate[1] << "."
            << it->second.birthDate[2] << endl;
    }
    cout << "-----------------------" << endl;
}

// Підпрограма для пошуку та виведення інформації за прізвищем
void searchByLastName(const map<int, Friend>& phoneBook) {
    if (phoneBook.empty()) {
        cout << "Колекція порожня! Немає де шукати." << endl;
        return;
    }

    string targetName;
    cout << "Введіть прізвище для пошуку: ";
    cin >> targetName;

    bool isFound = false;
    for (map<int, Friend>::const_iterator it = phoneBook.begin(); it != phoneBook.end(); ++it) {
        if (it->second.lastName == targetName) {
            if (!isFound) {
                cout << "\n--- Знайдені записи ---" << endl;
            }
            cout << "Прізвище: " << it->second.lastName << endl;
            cout << "Ім'я: " << it->second.firstName << endl;
            cout << "Телефон: " << it->second.phoneNumber << endl;
            cout << "Дата народження: "
                << it->second.birthDate[0] << "."
                << it->second.birthDate[1] << "."
                << it->second.birthDate[2] << endl;
            cout << "-----------------------" << endl;
            isFound = true;
        }
    }

    if (!isFound) {
        cout << "Людей з прізвищем '" << targetName << "' не знайдено." << endl;
    }
}

int main() {
    // Встановлення кодування для коректного відображення кирилиці
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    map<int, Friend> myPhoneBook;
    int menuChoice;

    do {
        cout << "\n========== МЕНЮ ==========" << endl;
        cout << "[1] Додати запис" << endl;
        cout << "[2] Відобразити всі записи" << endl;
        cout << "[3] Пошук за прізвищем" << endl;
        cout << "[0] Вийти" << endl;
        cout << "Ваш вибір: ";

        menuChoice = getValidInt(0, 3);

        switch (menuChoice) {
        case 1:
            addRecord(myPhoneBook);
            break;
        case 2:
            displayAll(myPhoneBook);
            break;
        case 3:
            searchByLastName(myPhoneBook);
            break;
        case 0:
            cout << "Завершення роботи програми..." << endl;
            break;
        }
    } while (menuChoice != 0);

    return 0;
}