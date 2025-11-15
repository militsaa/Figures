#pragma once
#include "Figure.h"

class Triangle : public Figure {
private:
    double sideA;
    double sideB;
    double sideC;

public:
    Triangle(double sideA, double sideB, double sideC);
    double perimeter() const override;
    Figure* clone() const override;
    virtual std::string to_string() const override;
};