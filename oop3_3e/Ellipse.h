#pragma once
#include "Pair.h"

class Ellipse : public Pair {
public:
    Ellipse();
    Ellipse(double a, double b);
    Ellipse(const Ellipse& e);
    ~Ellipse() override;

    bool SetFirst(double f) override;
    bool SetSecond(double s) override;

    void Init(double a, double b) override;
    void Read() override;
    void Display() const override;
    std::string toString() const override;

    double Perimeter() const;
    double Area() const;

    Ellipse& operator=(const Ellipse& e);
    operator std::string() const override;

    Ellipse& operator++();
    Ellipse operator++(int);
    Ellipse& operator--();
    Ellipse operator--(int);

    friend std::ostream& operator<<(std::ostream& out, const Ellipse& e);
    friend std::istream& operator>>(std::istream& in, Ellipse& e);
};