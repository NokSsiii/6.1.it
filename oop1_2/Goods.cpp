#include "Goods.h"
#include <iostream>
using namespace std;

void Goods::setName(string value)
{
    name = value;
}

void Goods::setDate(string value)
{
    date = value;
}

bool Goods::setPrice(double value)
{
    if (value > 0)
    {
        price = value;
        return true;
    }
    else
    {
        price = -value;
        return false;
    }
}

bool Goods::setQuantity(int value)
{
    if (value >= 0)
    {
        quantity = value;
        return true;
    }
    else
    {
        quantity = 0;
        return false;
    }
}

bool Goods::setInvoiceNo(int value)
{
    if (value > 0)
    {
        invoiceNo = value;
        return true;
    }
    else
    {
        invoiceNo = 0;
        return false;
    }
}

bool Goods::Init(string name, string date, double price, int quantity, int invoiceNo)
{
    setName(name);
    setDate(date);
    return setPrice(price) && setQuantity(quantity) && setInvoiceNo(invoiceNo);
}

void Goods::Read()
{
    string name;
    string date;
    double price;
    int quantity;
    int invoiceNo;

    cout << " name = ? "; cin >> name;
    cout << " date = ? "; cin >> date;

    do
    {
        cout << " price = ? "; cin >> price;
        cout << " quantity = ? "; cin >> quantity;
        cout << " invoiceNo = ? "; cin >> invoiceNo;
    } while (!Init(name, date, price, quantity, invoiceNo));
}

void Goods::Display() const
{
    cout << " name = " << name << endl;
    cout << " date = " << date << endl;
    cout << " price = " << price << endl;
    cout << " quantity = " << quantity << endl;
    cout << " invoiceNo = " << invoiceNo << endl;
}

void Goods::changePrice(double newPrice)
{
    setPrice(newPrice);
}

void Goods::increaseQuantity(int value)
{
    if (value > 0)
        quantity += value;
}

void Goods::decreaseQuantity(int value)
{
    if (value > 0 && quantity >= value)
        quantity -= value;
}

double Goods::getVartist() const
{
    return price * quantity;
}

string Goods::toString() const
{
    return "Total cost = " + to_string(getVartist());
}