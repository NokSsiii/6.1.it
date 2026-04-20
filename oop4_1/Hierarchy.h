#ifndef HIERARCHY_H
#define LHIERARCHY_H

#include <string>
#include <iostream>

using namespace std;

class Parent {
protected:

    string name;
    string surname;

public:
    Parent(string n, string s);
    virtual ~Parent() = default;

    virtual void print() const = 0;
};

class Child : public Parent {
private:
    string patronymic;

public:
    Child(string n, string s, string p);
    void print() const override;
};

#endif