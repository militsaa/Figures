#include "Triangle.h"
#include "../Utils/Utils.h"

#include <stdexcept>
#include <algorithm>
#include <cmath>

Triangle::Triangle(double sideA, double sideB, double sideC) {
    if (sideA <= 0 || sideB <= 0 || sideC <= 0 || (sideA + sideB + sideC) / 2 <= std::max({ sideA, sideB, sideC })) {
        throw std::invalid_argument("Invalid triangle sides!");
    }
    double per = sideA + sideB + sideC;
    if (!std::isfinite(per)) {
        throw std::overflow_error("Perimeter overflow!");
    }
    this->sideA = sideA;
    this->sideB = sideB;
    this->sideC = sideC;
}

double Triangle::perimeter() const {
    return  sideA + sideB + sideC;
}

Figure* Triangle::clone() const {
    return new Triangle(*this);
}

std::string Triangle::to_string() const {
    return "Triangle " + utils::doubleToString(sideA) + " " + utils::doubleToString(sideB) + " " + utils::doubleToString(sideC);
}
