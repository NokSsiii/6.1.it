#pragma once

class Object {
protected:
    static int count; // Лічильник створених об'єктів
public:
    Object();
    Object(const Object& other);
    virtual ~Object();

    static int getCount(); // Метод для отримання кількості об'єктів
};