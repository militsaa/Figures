#pragma once
#include "Figure.h"

class Rectangle : public Figure {
private:
    double sideA;
    double sideB;

public:
    Rectangle(double sideA, double sideB);
    double perimeter() const override;
    Figure* clone() const override;
    virtual std::string to_string() const override;
};