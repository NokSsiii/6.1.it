#ifndef D3_H
#define D3_H

#include "D1.h"

class D3 : protected D1
{
    int d3;
public:
    D3(int x, int y, int z);
    ~D3();
    void show_D3();
};

#endif