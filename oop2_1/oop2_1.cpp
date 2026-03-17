#include <iostream>
#include "Goods.h"

using namespace std;

#pragma pack(push, 1)
struct GoodsPacked {
    double first;
    unsigned int second;
};
#pragma pack(pop)

int main() {
    cout << "--- Size Demonstration ---" << endl;
    cout << "Size of Goods (unpacked): " << sizeof(Goods) << " bytes" << endl;
    cout << "Size of GoodsPacked: " << sizeof(GoodsPacked) << " bytes" << endl;
    cout << "--------------------------\n" << endl;

    cout << "1. Constructors:" << endl;
    Goods g1;
    cout << "Default (g1): " << g1 << endl;

    Goods g2(15.5, 5);
    cout << "Initialization (g2): " << g2 << endl;

    Goods g3 = g2;
    cout << "Copy (g3 = g2): " << g3 << endl;

    Goods g4 = makeGoods(25.0, 10);
    cout << "makeGoods() (g4): " << g4 << "\n" << endl;

    cout << "2. Cost calculation:" << endl;
    cout << "Cost of g4: " << g4.cost() << "\n" << endl;

    cout << "3. Prefix/Postfix operations on g4:" << endl;
    cout << "Initial: " << g4 << endl;

    cout << "++g4: " << ++g4 << endl;
    cout << "--g4: " << --g4 << endl;

    cout << "g4++: " << g4++ << endl;
    cout << "State after g4++: " << g4 << endl;

    cout << "g4--: " << g4-- << endl;
    cout << "State after g4--: " << g4 << "\n" << endl;

    cout << "4. Keyboard input:" << endl;
    Goods g5;
    cin >> g5;
    cout << "You entered: " << g5 << endl;
    cout << "Total cost: " << g5.cost() << "\n" << endl;

    cout << "5. Array of objects:" << endl;
    Goods arr[3] = {
        Goods(10.0, 2),
        Goods(12.5, 4),
        Goods()
    };

    for (int i = 0; i < 3; i++) {
        cout << "Item [" << i << "]: " << arr[i] << " | Cost: " << arr[i].cost() << endl;
    }

    return 0;
}