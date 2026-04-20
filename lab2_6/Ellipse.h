#pragma once
#include <string>
#include <iostream>

using namespace std;

class Ellipse
{
private:
    static int counter;

public:
    class Pair
    {
    private:
        double a;
        double b;
        static int counter;

    public:
        double getA() const { return a; }
        double getB() const { return b; }
        void setA(double a) { this->a = a; }
        void setB(double b) { this->b = b; }
        void Init(double a, double b);
        void Display() const;
        void Read();
        double Product() const;

        Pair();
        Pair(const double a);
        Pair(const double a, const double b);
        Pair(const Pair& p);
        ~Pair(void);

        Pair& operator = (const Pair& p);
        friend ostream& operator << (ostream& out, const Pair& p);
        friend istream& operator >> (istream& in, Pair& p);
        operator string () const;

        Pair& operator ++ ();
        Pair& operator -- ();
        Pair operator ++ (int);
        Pair operator -- (int);

        static int getCounter();
    };

    Pair getPair() const { return pair; }
    void setPair(Pair pair) { this->pair = pair; }
    void Init(Pair pair);
    void Display() const;
    void Read();
    double Perimeter() const;
    double Area() const;

    Ellipse(const double a = 0, const double b = 0);
    Ellipse(const Ellipse& e);
    ~Ellipse(void);

    Ellipse& operator = (const Ellipse& e);
    friend ostream& operator << (ostream& out, const Ellipse& e);
    friend istream& operator >> (istream& in, Ellipse& e);
    operator string () const;

    Ellipse& operator ++ ();
    Ellipse& operator -- ();
    Ellipse operator ++ (int);
    Ellipse operator -- (int);

    static int getCounter();

private:
    Pair pair;
};