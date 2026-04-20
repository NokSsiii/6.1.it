#include "Hierarchy.h"

Parent::Parent(string n, string s) : name(n), surname(s) {}

Child::Child(string n, string s, string p) : Parent(n, s), patronymic(p) {}

void Child::print() const {
    cout << "Name: " << name << ", Surname: " << surname << ", Patronymic: " << patronymic;
}