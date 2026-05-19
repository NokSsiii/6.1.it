#pragma once
#include "List.h"
#include <string>
#include <iostream>
#include <new>

class Integral {
private:
    List y_values;

public:
    // Обов'язкові конструктори та канонічна форма
    Integral() throw(std::bad_alloc);
    Integral(List::iterator first, List::iterator last) throw(std::bad_alloc);
    Integral(const std::string& str) throw(std::bad_alloc); // Конструктор ініціалізації літерним рядком
    Integral(const Integral& other) throw(std::bad_alloc);
    ~Integral();

    Integral& operator=(const Integral& other);
    Integral& operator+=(const Integral& other); // Операція з двома масивами (перевірка розмірів)

    // Операції перетворення типів
    operator std::string() const; // Перетворення в рядок
    operator double() const;      // Перетворення в double (обчислює інтеграл за замовчуванням)

    // Методи чисельного інтегрування
    double leftRectangles() const;
    double rightRectangles() const;
    double centralRectangles() const;
    double trapezoidal() const;

    // Дружні функції введення-виведення
    friend std::ostream& operator<<(std::ostream& os, const Integral& obj);
    friend std::istream& operator>>(std::istream& is, Integral& obj);
};