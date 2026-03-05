#pragma once
#include <string>
using namespace std;

class Address
{
private:
    string country;
    string city;
    string street;
    int building;
    string organization;

public:
    string GetCountry() const { return country; }
    string GetCity() const { return city; }
    string GetStreet() const { return street; }
    int GetBuilding() const { return building; }
    string GetOrganization() const { return organization; }

    bool SetCountry(string value);
    bool SetCity(string value);
    bool SetStreet(string value);
    bool SetBuilding(int value);
    bool SetOrganization(string value);

    bool Init(string country, string city, string street, int building, string organization);
    void Read();
    void Display() const;
    string toString() const;
};