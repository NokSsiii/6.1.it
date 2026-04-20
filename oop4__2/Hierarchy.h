#ifndef HIERARCHY_H
#define HIERARCHY_H

#include <string>
#include <iostream>

using namespace std;

// Інтерфейс (тільки абстрактні методи)
class IParent {
public:
    virtual void print() const = 0;
    virtual string getType() const = 0;
    virtual ~IParent() = default;
};

// Базовий клас (реалізація спільних полів)
class Parent : public IParent {
protected:
    string name;
    string surname;

public:
    Parent(string n, string s);
};

// Похідний клас
class Child : public Parent {
private:
    string patronymic;

public:
    Child(string n, string s, string p);

    void print() const override;
    string getType() const override;
};

#endif