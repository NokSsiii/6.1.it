#ifndef D4_H
#define D4_H

#include "D1.h"
#include "D2.h"
#include "B.h"

class D4 : public D1, protected B, protected D2
{
    int d4;
public:
    D4(int x, int d1_val, int b_d1_val, int b_direct_val, int d2_val, int b_d2_val);
    ~D4();
    void show_D4();
};

#endif