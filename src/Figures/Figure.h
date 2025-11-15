#pragma once
#include "../Utils/StringConvertible.h"

class Figure : public StringConvertible {
public:
    virtual double perimeter() const = 0;
    virtual Figure* clone() const = 0;
    virtual ~Figure() = default;
};