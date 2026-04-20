#ifndef DECIMAL_H
#define DECIMAL_H

#include <iostream>
#include <string>

using namespace std;

#pragma pack(push, 1)
struct DecimalPacked {
    int size;
    int count;
    unsigned char* digits;
};
#pragma pack(pop)

class Decimal {
private:
    int size;             
    int count; 
    unsigned char* digits;

    void removeLeadingZeros();

public:
    Decimal(); 
    Decimal(const string& str, int max_size = 100);
    Decimal(const Decimal& other);
    ~Decimal();

    int getSize() const;
    int getCount() const;
    void setDigit(int index, unsigned char val);
    unsigned char getDigit(int index) const;

    Decimal& operator=(const Decimal& other);
    unsigned char& operator[](int index);
    operator string() const;

    Decimal& operator++();
    Decimal operator++(int);

    Decimal& operator+=(const Decimal& other);
    Decimal& operator-=(const Decimal& other);

    friend Decimal operator+(Decimal left, const Decimal& right);
    friend Decimal operator-(Decimal left, const Decimal& right);

    friend bool operator==(const Decimal& left, const Decimal& right);
    friend bool operator!=(const Decimal& left, const Decimal& right);
    friend bool operator<(const Decimal& left, const Decimal& right);
    friend bool operator>(const Decimal& left, const Decimal& right);

    friend ostream& operator<<(ostream& os, const Decimal& d);
    friend istream& operator>>(istream& is, Decimal& d);
};

#endif