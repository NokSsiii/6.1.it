#pragma once

class IsNegative
{
public:
    bool operator()(int x) const
    {
        return x < 0;
    }
};

class IsEven
{
public:
    bool operator()(int x) const
    {
        return x % 2 == 0;
    }
};