#include "Figure.h"
#include <string>
class StringToFigure {
    static const int circleleArgCnt;
    static const int triangleArgCnt;
    static const int rectangleArgCnt;

    static Circle* parseCircle(const std::string& radius);
    static Rectangle* parseRectangle(const std::string& sideA, const std::string& sideB);
    static Triangle* parseTriangle(const std::string& sideA, const std::string& sideB, const std::string& sideC);

public:
    static Figure* stringToFigure(const std::string& representation);
};