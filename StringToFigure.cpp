#include "StringToFigure.h"
#include <vector>
#include "Utils.h"
#include <stdexcept>
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

const int StringToFigure::circleleArgCnt = 2;
const int StringToFigure::rectangleArgCnt = 3;
const int StringToFigure::triangleArgCnt = 4;

Circle* StringToFigure::parseCircle(const std::string& radius)
{
    double param;
    if (utils::tryParseDouble(radius, param)) {
        return new Circle(param);
    }
    else throw std::invalid_argument("Invalid string!");
}

Rectangle* StringToFigure::parseRectangle(const std::string& sideA, const std::string& sideB)
{
    double paramA, paramB;
    if (utils::tryParseDouble(sideA, paramA) && utils::tryParseDouble(sideB, paramB)) {
        return new Rectangle(paramA, paramB);
    }
    else throw std::invalid_argument("Invalid string!");
}

Triangle* StringToFigure::parseTriangle(const std::string& sideA, const std::string& sideB, const std::string& sideC)
{
    double paramA, paramB, paramC;
    if (utils::tryParseDouble(sideA, paramA) && utils::tryParseDouble(sideB, paramB) && utils::tryParseDouble(sideC, paramC)) {
        return new Triangle(paramA, paramB, paramC);
    }
    else throw std::invalid_argument("Invalid string!");
}

Figure* StringToFigure::stringToFigure(const std::string& representation)
{
    std::vector<std::string> data = utils::split(representation, ' ');
    if (data.size() < circleleArgCnt) throw std::invalid_argument("Invalid string!");
    if (data[0] == "Circle") {
        parseCircle(data[1]);
    }
    if (data[0] == "Rectangle" && data.size() == rectangleArgCnt) {
        parseRectangle(data[1], data[2]);
    }
    if (data[0] == "Triangle" && data.size() == triangleArgCnt) {
        parseTriangle(data[1], data[2], data[3]);
    }
}