#include "Ellipse.h"

using namespace std;

int main()
{
    Ellipse e1;
    cout << "Ellipse : " << Ellipse::getCounter() << endl;
    cout << "Ellipse::Pair : " << Ellipse::Pair::getCounter() << endl;

    Ellipse::Pair p1;
    cout << "Ellipse::Pair +1 : " << Ellipse::Pair::getCounter() << endl;

    {
        Ellipse e2(5.0, 3.0);
        cout << "Ellipse local : " << Ellipse::getCounter() << endl;
        cout << "Ellipse::Pair local : " << Ellipse::Pair::getCounter() << endl;

        Ellipse::Pair p2;
        cout << "Ellipse::Pair local +1 : " << Ellipse::Pair::getCounter() << endl;
    }

    cout << "Ellipse : " << Ellipse::getCounter() << endl;
    cout << "Ellipse::Pair : " << Ellipse::Pair::getCounter() << endl;

    Ellipse e3;
    e3.Read();
    cout << e3 << endl;

    e3.Display();

    cout << "e3++" << endl;
    e3++;
    e3.Display();

    cout << "--e3" << endl;
    --e3;
    e3.Display();

    return 0;
}