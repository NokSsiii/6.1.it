#include "Hierarchy.h"

// Конструктор базового класу
Parent::Parent(string n, string s) : name(n), surname(s) {}

// Конструктор похідного класу
Child::Child(string n, string s, string p)
    : Parent(n, s), patronymic(p) {
}

// Перевизначення методу print()
void Child::print() const {
    cout << "Name: " << name
        << ", Surname: " << surname
        << ", Patronymic: " << patronymic << endl;
}

// Метод для визначення реального типу
string Child::getType() const {
    return "Child";
}