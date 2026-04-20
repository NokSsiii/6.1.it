#ifndef D2_H
#define D2_H

#include "B.h"

class D2 : public B
{
    int d2;
public:
    D2(int x, int y);
    ~D2();
    void show_D2();
};

#endif