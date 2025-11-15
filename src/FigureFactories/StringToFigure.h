#pragma once
#include "../Figures/Figure.h"
#include <string>
#include <memory>
class StringToFigure {
    static const int circleleArgCnt;
    static const int triangleArgCnt;
    static const int rectangleArgCnt;

    static std::unique_ptr<Figure> parseCircle(const std::string& radius);
    static std::unique_ptr<Figure> parseRectangle(const std::string& sideA, const std::string& sideB);
    static std::unique_ptr<Figure> parseTriangle(const std::string& sideA, const std::string& sideB, const std::string& sideC);

public:
    static std::unique_ptr<Figure> stringToFigure(const std::string& representation);
};