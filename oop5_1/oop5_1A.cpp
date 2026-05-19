#include "Money.h"
#include <iostream>

using namespace std;

int main()
{
    try
    {
        Money a(10, 5);
        cout << a << endl;

        Money b(3, 2); // виняток
    }
    catch (MoneyException& e)
    {
        cout << "MoneyException: " << e.what() << endl;
    }
    catch (exception& e)
    {
        cout << "std exception: " << e.what() << endl;
    }

    return 0;
}