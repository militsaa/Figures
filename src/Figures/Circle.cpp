#define _USE_MATH_DEFINES
#include "Circle.h"
#include "../Utils/Utils.h"
#include <cmath>
#include <stdexcept>

Circle::Circle(double radius) {
    if (radius <= 0) {
        throw std::invalid_argument("Invalid radius!");
    }
    double per = 2 * radius * M_PI;
    if (!std::isfinite(per)) {
        throw std::overflow_error("Perimeter overflow!");
    }
    this->radius = radius;
}

double Circle::perimeter() const {
    return 2 * radius * M_PI;
}

Figure* Circle::clone() const {
    return new Circle(*this);
}

std::string Circle::to_string() const {
    return "Circle " + utils::doubleToString(radius);
}
