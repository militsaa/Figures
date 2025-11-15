#define _USE_MATH_DEFINES
#include "Circle.h"
#include <cmath>
#include <stdexcept>

Circle::Circle(double radius) {
    if (radius > 0)
        this->radius = radius;
    else
        throw std::invalid_argument("Invalid radius!");
}

double Circle::perimeter() const {
    return 2 * radius * M_PI;
}

Figure* Circle::clone() const {
    return new Circle(*this);
}

std::string Circle::to_string() const {
    return "Circle " + std::to_string(radius);
}
