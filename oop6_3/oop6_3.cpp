#include "Integral.h"
#include <iostream>
#include <windows.h>
#include <iomanip>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try {
        cout << "=== Тестування класу Integral (Варіант 24) ===" << endl;

        string data = "1.0 2.0 3.5 4.0 5.0";
        cout << "Створення об'єкта інтеграла з рядка: \"" << data << "\"" << endl;
        Integral int1(data);
        cout << "Завантажений масив значень функцій: " << int1 << endl;

        cout << fixed << setprecision(4);
        cout << "Метод лівих прямокутників:    " << int1.leftRectangles() << endl;
        cout << "Метод правих прямокутників:   " << int1.rightRectangles() << endl;
        cout << "Метод центральних прямокутників: " << int1.centralRectangles() << endl;
        cout << "Метод трапецій:               " << int1.trapezoidal() << endl;

        double defaultResult = int1;
        cout << "Результат явного приведення до double: " << defaultResult << endl;

        cout << "\n=== Тестування операцій та винятків ===" << endl;

        Integral int2("0.5 1.0 1.5 2.0 2.5");
        cout << "Об'єкт 2: " << int2 << endl;

        int1 += int2;
        cout << "Результат виконання операції (Об'єкт 1 += Об'єкт 2): " << int1 << endl;

        cout << "\nСпроба додати об'єкти різної довжини:" << endl;
        Integral intErr("1.0 2.0 3.0");
        int1 += intErr;

    }
    catch (const std::bad_alloc& e) {
        cerr << "Критична помилка: Нестача пам'яті (bad_alloc)!" << endl;
    }
    catch (const std::runtime_error& e) {
        cerr << "Очікуваний виняток: " << e.what() << endl;
    }
    catch (...) {
        cerr << "Невідома помилка!" << endl;
    }

    cout << "\n=== Тестування дружнього введення (operator>>) ===" << endl;
    Integral intInteractive;
    cin >> intInteractive;
    cout << "Ви ввели об'єкт: " << intInteractive << endl;
    cout << "Інтеграл (метод трапецій): " << intInteractive.trapezoidal() << endl;

    cin.get();
    cin.get();
    return 0;
}