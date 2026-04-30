#ifndef MONEY_H
#define MONEY_H

#include "Array.h"

class Money : public Array {
private:
    void trim();

public:
    Money();
    Money(int size, int initialValue = 0);

    void setElement(int index, int value) override;
    void setDigit(int index, int value);
    int getDigit(int index) const;

    std::string toString() const override;

    bool operator<(const Money& other) const;
    bool operator==(const Money& other) const;

    Money operator+(const Money& other) const;
    Money operator-(const Money& other) const;

    Money& operator+=(const Money& other);
    Money& operator-=(const Money& other);
    Money& operator=(const Money& other);

    friend std::istream& operator>>(std::istream& is, Money& m);
    friend std::ostream& operator<<(std::ostream& os, const Money& m);
};

#endif