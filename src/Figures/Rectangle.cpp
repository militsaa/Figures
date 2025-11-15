#include "Rectangle.h"
#include "../Utils/Utils.h"
#include <stdexcept>
#include <cmath>

Rectangle::Rectangle(double sideA, double sideB) {
    if (sideA <= 0 || sideB <= 0) {
        throw std::invalid_argument("Invalid rectangle sides!");
    }
    double per = 2 * (sideA + sideB);
    if (!std::isfinite(per)) {
        throw std::overflow_error("Perimeter overflow!");
    }
    this->sideA = sideA;
    this->sideB = sideB;
}

double Rectangle::perimeter() const {
    return 2 * (sideA + sideB);
}

Figure* Rectangle::clone() const {
    return new Rectangle(*this);
}

std::string Rectangle::to_string() const {
    return "Rectangle " + utils::doubleToString(sideA) + " " + utils::doubleToString(sideB);
}
