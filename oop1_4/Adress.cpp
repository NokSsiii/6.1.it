#include "Adress.h"
#include <iostream>
using namespace std;

bool Address::SetCountry(string value)
{
    if (value != "")
    {
        country = value;
        return true;
    }
    return false;
}

bool Address::SetCity(string value)
{
    if (value != "")
    {
        city = value;
        return true;
    }
    return false;
}

bool Address::SetStreet(string value)
{
    if (value != "")
    {
        street = value;
        return true;
    }
    return false;
}

bool Address::SetBuilding(int value)
{
    if (value > 0)
    {
        building = value;
        return true;
    }
    return false;
}

bool Address::SetOrganization(string value)
{
    if (value != "")
    {
        organization = value;
        return true;
    }
    return false;
}

bool Address::Init(string c, string ci, string s, int b, string o)
{
    return SetCountry(c)
        && SetCity(ci)
        && SetStreet(s)
        && SetBuilding(b)
        && SetOrganization(o);
}

void Address::Read()
{
    string c, ci, s, o;
    int b;

    cout << "Country: ";
    cin >> c;

    cout << "City: ";
    cin >> ci;

    cout << "Street: ";
    cin >> s;

    cout << "Building: ";
    cin >> b;

    cout << "Organization: ";
    cin >> o;

    Init(c, ci, s, b, o);
}

void Address::Display() const
{
    cout << toString() << endl;
}

string Address::toString() const
{
    return "Organization: " + organization +
        ", Country: " + country +
        ", City: " + city +
        ", Street: " + street +
        ", Building: " + to_string(building);
}