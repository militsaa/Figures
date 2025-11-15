#pragma once
#include "Figure.h"

class Circle : public Figure {
private:
    double radius;

public:
    Circle(double radius);
    double perimeter() const override;
    Figure* clone() const override;
    virtual std::string to_string() const override;
};