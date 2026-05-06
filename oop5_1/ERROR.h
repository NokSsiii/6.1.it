#pragma once
#include <stdexcept>
#include <string>

using namespace std;

// базовий власний виняток
class MyException
{
protected:
    string message;

public:
    MyException(string msg) : message(msg) {}
    virtual string what() const { return message; }
};

// спеціалізований виняток
class MoneyException : public logic_error
{
public:
    MoneyException(const string& msg)
        : logic_error(msg) {
    }
};