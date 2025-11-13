#include "Figure.h"
#include <string>
class StringToFigure {
    static const int circleleArgCnt;
    static const int triangleArgCnt;
    static const int rectangleArgCnt;

    static Figure* parseCircle(const std::string& radius);
    static Figure* parseRectangle(const std::string& sideA, const std::string& sideB);
    static Figure* parseTriangle(const std::string& sideA, const std::string& sideB, const std::string& sideC);

public:
    static Figure* stringToFigure(const std::string& representation);
};