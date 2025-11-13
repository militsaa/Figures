#include "Triangle.h"
#include <stdexcept>
#include <algorithm>

Triangle::Triangle(double sideA, double sideB, double sideC) {
    if (sideA > 0 && sideB > 0 && sideC > 0 && (sideA + sideB + sideC) / 2 > std::max({ sideA, sideB, sideC })) {
        this->sideA = sideA;
        this->sideB = sideB;
        this->sideC = sideC;
    }
    else
        throw std::invalid_argument("Invalid triangle sides!");
}

double Triangle::perimeter() const {
    return sideA + sideB + sideC;
}

Figure* Triangle::clone() const {
    return new Triangle(*this);
}

std::string Triangle::to_string() const {
    return "Triangle " + std::to_string(sideA) + " " + std::to_string(sideB) + " " + std::to_string(sideC);
}
