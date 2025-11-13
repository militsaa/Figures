#include "Rectangle.h"
#include <stdexcept>

Rectangle::Rectangle(double sideA, double sideB) {
    if (sideA > 0 && sideB > 0) {
        this->sideA = sideA;
        this->sideB = sideB;
    }
    else
        throw std::invalid_argument("Invalid rectangle sides!");
}

double Rectangle::perimeter() const {
    return 2 * (sideA + sideB);
}

Figure* Rectangle::clone() const {
    return new Rectangle(*this);
}

std::string Rectangle::to_string() const {
    return "Rectangle " + std::to_string(sideA) + " " + std::to_string(sideB);
}
