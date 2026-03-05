#include <iostream>
#include "Adress.h"
using namespace std;

void Menu()
{
    cout << endl;
    cout << "1. Create address\n";
    cout << "2. Show address\n";
    cout << "3. Change country\n";
    cout << "4. Change city\n";
    cout << "5. Change street\n";
    cout << "6. Change building\n";
    cout << "7. Change organization\n";
    cout << "0. Exit\n";
    cout << "Choice: ";
}

int main()
{
    Address addr;
    int choice;
    string str;
    int num;

    do
    {
        Menu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            addr.Read();
            break;

        case 2:
            addr.Display();
            break;

        case 3:
            cout << "New country: ";
            cin >> str;
            addr.SetCountry(str);
            break;

        case 4:
            cout << "New city: ";
            cin >> str;
            addr.SetCity(str);
            break;

        case 5:
            cout << "New street: ";
            cin >> str;
            addr.SetStreet(str);
            break;

        case 6:
            cout << "New building: ";
            cin >> num;
            addr.SetBuilding(num);
            break;

        case 7:
            cout << "New organization: ";
            cin >> str;
            addr.SetOrganization(str);
            break;
        }

    } while (choice != 0);

    return 0;
}