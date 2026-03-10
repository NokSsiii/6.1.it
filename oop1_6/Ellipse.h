#pragma once
#include <string>

class Ellipse
{
public:
    class Pair
    {
    private:
        double a;
        double b;

    public:
        double getA() const { return a; }
        double getB() const { return b; }

        void setA(double a);
        void setB(double b);

        double Product() const;

        void Init(double a, double b);
        void Display() const;
        void Read();
        std::string toString() const;
    };

private:
    Pair semiAxes;

public:
    Ellipse::Pair getSemiAxes() const { return semiAxes; }
    void setSemiAxes(Ellipse::Pair axes) { this->semiAxes = axes; }

    double Perimeter() const;
    double Area() const;

    void Init(Ellipse::Pair axes);
    void Display() const;
    void Read();
    std::string toString() const;
};