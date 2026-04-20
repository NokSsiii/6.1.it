#ifndef D1_H
#define D1_H

#include "B.h"

class D1 : private B
{
    int d1;
public:
    D1(int x, int y);
    ~D1();
    void show_D1();
};

#endif