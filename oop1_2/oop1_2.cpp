#include <iostream>
#include "Goods.h"
using namespace std;

int main()
{
    Goods g;

    g.Read();
    g.Display();

    cout << g.toString() << endl;

    return 0;
}