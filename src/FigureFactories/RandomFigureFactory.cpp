#include "RandomFigureFactory.h"
#include "../Figures/Circle.h"
#include "../Figures/Rectangle.h"
#include "../Figures/Triangle.h"

std::unique_ptr<Figure>  RandomFigureFactory::randomCircle()
{
    double radius = rand.getRandDouble(0.1, MAX_PARAMETER_VALUE);
    return std::make_unique<Circle>(radius);
}

std::unique_ptr<Figure> RandomFigureFactory::randomRectangle()
{
    double sideA = rand.getRandDouble(0.1, MAX_PARAMETER_VALUE);
    double sideB = rand.getRandDouble(0.1, MAX_PARAMETER_VALUE);
    return std::make_unique<Rectangle>(sideA, sideB);
}

std::unique_ptr<Figure> RandomFigureFactory::randomTriangle()
{
    double sideA = rand.getRandDouble(0.1, MAX_PARAMETER_VALUE);
    double sideB = rand.getRandDouble(0.1, MAX_PARAMETER_VALUE);
    double sideC = rand.getRandDouble(abs(sideA - sideB) + 0.1, sideA + sideB - 0.1);
    return std::make_unique<Triangle>(sideA, sideB, sideC);
}

std::unique_ptr<Figure> RandomFigureFactory::create()
{
    int type = rand.getRandInt(1, 3);
    switch (type) {
    case 1:
        return randomCircle();
        break;
    case 2:
        return randomRectangle();
        break;
    case 3:
        return randomTriangle();
        break;
    }
    return nullptr;
}