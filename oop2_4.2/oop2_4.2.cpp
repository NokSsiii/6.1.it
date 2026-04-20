#include <iostream>
#include "Decimal.h"

using namespace std;

// Звичайна структура для порівняння розмірів (без pragma pack)
struct DecimalUnpacked {
    int size;
    int count;
    unsigned char* digits;
};

int main() {
    cout << "=== Class Size Demonstration ===" << endl;
    cout << "Class size without #pragma pack(1): " << sizeof(DecimalUnpacked) << " bytes" << endl;
    cout << "Class size with #pragma pack(1):    " << sizeof(DecimalPacked) << " bytes" << endl;
    cout << "----------------------------------" << endl;

    try {
        // 1. Демонстрація конструкторів
        Decimal d1; // Конструктор за замовчуванням
        Decimal d2("1234567890987654321"); // Ініціалізація рядком
        Decimal d3(d2); // Конструктор копіювання

        cout << "d1 (default): " << d1 << endl;
        cout << "d2 (string): " << d2 << endl;
        cout << "d3 (copy of d2): " << d3 << endl;

        // 2. Методи запису з перевіркою
        d1.setDigit(0, 5);
        d1.setDigit(1, 2);
        cout << "\nd1 after setDigit(0,5) and (1,2): " << d1 << endl; // Має бути 25, оскільки індекс 0 - це одиниці (наймолодший розряд)

        // 3. Операції присвоювання та введення
        Decimal d4;
        cout << "\nEnter a large positive number for d4: ";
        cin >> d4;
        cout << "You entered: " << d4 << endl;

        // 4. Арифметичні операції
        Decimal sum = d2 + d4;
        cout << "\nSum (d2 + d4): " << sum << endl;

        if (d2 > d4) {
            Decimal diff = d2 - d4;
            cout << "Difference (d2 - d4): " << diff << endl;
        }
        else {
            cout << "d4 is greater than or equal to d2, skipping subtraction (to avoid underflow)." << endl;
        }

        // 5. Використання оператора індексування та унарних операцій
        cout << "\nd4 before increment: " << d4 << endl;
        d4++;
        cout << "d4 after postfix ++: " << d4 << endl;

        cout << "Second digit (tens) of d4 (using []): " << (int)d4[1] << endl;

        // 6. Масив об'єктів
        cout << "\n=== Array of Objects ===" << endl;
        Decimal arr[3] = { Decimal("100"), Decimal("200"), Decimal("300") };
        for (int i = 0; i < 3; i++) {
            cout << "arr[" << i << "] = " << arr[i] << endl;
        }

    }
    catch (const exception& e) {
        cerr << "\nError: " << e.what() << endl;
    }

    return 0;
}