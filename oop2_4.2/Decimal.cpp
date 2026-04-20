#include "Decimal.h"
#include <algorithm>
#include <stdexcept>

// Допоміжний метод для видалення нулів на початку числа (наприкінці масиву)
void Decimal::removeLeadingZeros() {
    while (count > 1 && digits[count - 1] == 0) {
        count--;
    }
}

// Конструктор без аргументів
Decimal::Decimal() {
    size = 100;
    count = 1;
    digits = new unsigned char[size];
    digits[0] = 0;
}

// Конструктор ініціалізації рядком
Decimal::Decimal(const string& str, int max_size) {
    size = max_size;
    digits = new unsigned char[size];
    count = 0;

    // Ігноруємо можливі нулі на початку рядка
    int start = 0;
    while (start < str.length() - 1 && str[start] == '0') {
        start++;
    }

    // Заповнюємо масив, починаючи з кінця рядка (молодші розряди спочатку)
    for (int i = str.length() - 1; i >= start; i--) {
        if (count >= size) break;
        if (str[i] >= '0' && str[i] <= '9') {
            digits[count++] = str[i] - '0';
        }
        else {
            throw invalid_argument("String contains non-digit characters.");
        }
    }
    // Якщо рядок був порожнім або складався лише з невірних символів
    if (count == 0) {
        digits[0] = 0;
        count = 1;
    }
}

// Конструктор копіювання
Decimal::Decimal(const Decimal& other) {
    size = other.size;
    count = other.count;
    digits = new unsigned char[size];
    for (int i = 0; i < count; i++) {
        digits[i] = other.digits[i];
    }
}

// Деструктор
Decimal::~Decimal() {
    delete[] digits;
}

// Методи доступу
int Decimal::getSize() const { return size; }
int Decimal::getCount() const { return count; }

// Метод запису з перевіркою
void Decimal::setDigit(int index, unsigned char val) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range.");
    }
    if (val > 9) {
        throw invalid_argument("Digit must be between 0 and 9.");
    }
    digits[index] = val;
    // Якщо ми записуємо цифру за межами поточної довжини числа
    if (index >= count) {
        for (int i = count; i < index; i++) digits[i] = 0;
        count = index + 1;
    }
    removeLeadingZeros();
}

// Метод зчитування з перевіркою
unsigned char Decimal::getDigit(int index) const {
    if (index < 0 || index >= count) return 0;
    return digits[index];
}

// Перевантаження оператора =
Decimal& Decimal::operator=(const Decimal& other) {
    if (this == &other) return *this;
    delete[] digits;
    size = other.size;
    count = other.count;
    digits = new unsigned char[size];
    for (int i = 0; i < count; i++) {
        digits[i] = other.digits[i];
    }
    return *this;
}

// Перевантаження оператора []
unsigned char& Decimal::operator[](int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of bounds.");
    }
    if (index >= count) {
        for (int i = count; i <= index; i++) digits[i] = 0;
        count = index + 1;
    }
    return digits[index]; // Не захищено від запису > 9, але надає прямий доступ
}

// Приведення до рядка
Decimal::operator string() const {
    string res = "";
    for (int i = count - 1; i >= 0; i--) {
        res += to_string(digits[i]);
    }
    return res;
}

// Інкремент префіксний
Decimal& Decimal::operator++() {
    *this += Decimal("1");
    return *this;
}

// Інкремент постфіксний
Decimal Decimal::operator++(int) {
    Decimal temp(*this);
    ++(*this);
    return temp;
}

// Складене присвоювання +=
Decimal& Decimal::operator+=(const Decimal& other) {
    int max_len = max(count, other.count);
    int carry = 0; // Перенос

    for (int i = 0; i < max_len || carry; i++) {
        if (i >= size) throw overflow_error("Decimal size limit exceeded.");
        if (i >= count) digits[count++] = 0;

        int sum = digits[i] + (i < other.count ? other.digits[i] : 0) + carry;
        digits[i] = sum % 10;
        carry = sum / 10;
    }
    return *this;
}

// Складене присвоювання -=
Decimal& Decimal::operator-=(const Decimal& other) {
    if (*this < other) throw underflow_error("Result cannot be negative.");

    int borrow = 0; // Позика
    for (int i = 0; i < count; i++) {
        int sub = digits[i] - (i < other.count ? other.digits[i] : 0) - borrow;
        if (sub < 0) {
            sub += 10;
            borrow = 1;
        }
        else {
            borrow = 0;
        }
        digits[i] = sub;
    }
    removeLeadingZeros();
    return *this;
}

// Бінарні операції (Дружні функції)
Decimal operator+(Decimal left, const Decimal& right) {
    left += right;
    return left;
}

Decimal operator-(Decimal left, const Decimal& right) {
    left -= right;
    return left;
}

// Порівняння
bool operator==(const Decimal& left, const Decimal& right) {
    if (left.count != right.count) return false;
    for (int i = 0; i < left.count; i++) {
        if (left.digits[i] != right.digits[i]) return false;
    }
    return true;
}

bool operator!=(const Decimal& left, const Decimal& right) {
    return !(left == right);
}

bool operator<(const Decimal& left, const Decimal& right) {
    if (left.count != right.count) return left.count < right.count;
    for (int i = left.count - 1; i >= 0; i--) {
        if (left.digits[i] != right.digits[i]) return left.digits[i] < right.digits[i];
    }
    return false;
}

bool operator>(const Decimal& left, const Decimal& right) {
    return right < left;
}

// Введення/Виведення
ostream& operator<<(ostream& os, const Decimal& d) {
    os << string(d);
    return os;
}

istream& operator>>(istream& is, Decimal& d) {
    string temp;
    is >> temp;
    d = Decimal(temp, d.size);
    return is;
}