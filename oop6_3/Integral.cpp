#include "Integral.h"
#include <sstream>
#include <iomanip>

Integral::Integral() throw(std::bad_alloc) : y_values() {}

Integral::Integral(List::iterator first, List::iterator last) throw(std::bad_alloc) : y_values(first, last) {}

Integral::Integral(const std::string& str) throw(std::bad_alloc) : y_values() {
    std::stringstream ss(str);
    double val;
    while (ss >> val) {
        y_values.push_back(val);
    }
}

Integral::Integral(const Integral& other) throw(std::bad_alloc) : y_values(other.y_values) {}

Integral::~Integral() {}

Integral& Integral::operator=(const Integral& other) {
    if (this != &other) {
        y_values = other.y_values;
    }
    return *this;
}

Integral& Integral::operator+=(const Integral& other) {
    if (this->y_values.lenght() != other.y_values.lenght()) {
        throw std::runtime_error("Помилка: Розміри масивів значень мають бути однаковими для додавання!");
    }
    List::iterator itThis = this->y_values.begin();
    List::iterator itOther = other.y_values.begin();
    while (itThis != this->y_values.end()) {
        *itThis += *itOther;
        ++itThis;
        ++itOther;
    }
    return *this;
}

Integral::operator std::string() const {
    std::stringstream ss;
    ss << "[";
    for (List::iterator it = y_values.begin(); it != y_values.end(); ) {
        ss << *it;
        if (++it != y_values.end()) ss << ", ";
    }
    ss << "]";
    return ss.str();
}

Integral::operator double() const {
    return trapezoidal(); // За замовчуванням повертає значення за методом трапецій
}

double Integral::leftRectangles() const {
    size_t n = y_values.lenght() - 1;
    if (n < 1) return 0.0;

    double a = *y_values.begin();
    List tmp = y_values;
    double b = tmp.back();
    double h = (b - a) / n;

    double sum = 0.0;
    List::iterator it = y_values.begin();
    for (size_t i = 0; i < n; ++i) {
        sum += *it;
        ++it;
    }
    return sum * h;
}

double Integral::rightRectangles() const {
    size_t n = y_values.lenght() - 1;
    if (n < 1) return 0.0;

    double a = *y_values.begin();
    List tmp = y_values;
    double b = tmp.back();
    double h = (b - a) / n;

    double sum = 0.0;
    List::iterator it = y_values.begin();
    ++it;
    for (size_t i = 1; i <= n; ++i) {
        sum += *it;
        ++it;
    }
    return sum * h;
}

double Integral::centralRectangles() const {
    size_t n = y_values.lenght() - 1;
    if (n < 1) return 0.0;

    double a = *y_values.begin();
    List tmp = y_values;
    double b = tmp.back();
    double h = (b - a) / n;

    double sum = 0.0;
    List::iterator it = y_values.begin();
    for (size_t i = 0; i < n; ++i) {
        double y_curr = *it;
        ++it;
        double y_next = *it;
        sum += (y_curr + y_next) / 2.0; // Апроксимація центральної точки
    }
    return sum * h;
}

double Integral::trapezoidal() const {
    size_t n = y_values.lenght() - 1;
    if (n < 1) return 0.0;

    double a = *y_values.begin();
    List tmp = y_values;
    double b = tmp.back();
    double h = (b - a) / n;

    List::iterator it = y_values.begin();
    double y0 = *it;
    ++it;
    double sum = 0.0;
    for (size_t i = 1; i < n; ++i) {
        sum += *it;
        ++it;
    }
    double yn = *it;
    return h * ((y0 + yn) / 2.0 + sum);
}

std::ostream& operator<<(std::ostream& os, const Integral& obj) {
    os << std::string(obj);
    return os;
}

std::istream& operator>>(std::istream& is, Integral& obj) {
    obj.y_values.clear();
    size_t count;
    std::cout << "Введіть кількість точок (n + 1): ";
    if (is >> count) {
        std::cout << "Введіть значення y_i через пробіл: ";
        for (size_t i = 0; i < count; ++i) {
            double val;
            if (is >> val) {
                obj.y_values.push_back(val);
            }
        }
    }
    return is;
}