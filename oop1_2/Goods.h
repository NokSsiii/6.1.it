#pragma once
#include <string>
using namespace std;

class Goods
{
private:
    string name;
    string date;
    double price;
    int quantity;
    int invoiceNo;

public:
    string getName() const { return name; }
    string getDate() const { return date; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }
    int getInvoiceNo() const { return invoiceNo; }

    void setName(string);
    void setDate(string);
    bool setPrice(double);
    bool setQuantity(int);
    bool setInvoiceNo(int);

    bool Init(string name, string date, double price, int quantity, int invoiceNo);
    void Read();
    void Display() const;

    void changePrice(double newPrice);
    void increaseQuantity(int value);
    void decreaseQuantity(int value);

    double getVartist() const;
    string toString() const;
};