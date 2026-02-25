#pragma once
class Money
{
private:
    int first;
    int second;

public:
    int GetFirst() const { return first; }
    int GetSecond() const { return second; }

    bool SetFirst(int value);
    bool SetSecond(int value);

    bool Init(int value, int count);
    void Read();
    void Display() const;

    int Summa() const;
};