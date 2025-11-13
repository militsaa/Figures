#include "RandomFigureFactory.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

Figure* RandomFigureFactory::randomCircle()
{
    int radius = rand.getRandDouble(0.1, MAX_PARAMETER_VALUE);
    return new Circle(radius);
}

Figure* RandomFigureFactory::randomRectangle()
{
    int sideA = rand.getRandDouble(0.1, MAX_PARAMETER_VALUE);
    int sideB = rand.getRandDouble(0.1, MAX_PARAMETER_VALUE);
    return new Rectangle(sideA, sideB);
}

Figure* RandomFigureFactory::randomTriangle()
{
    int sideA = rand.getRandDouble(0.1, MAX_PARAMETER_VALUE);
    int sideB = rand.getRandDouble(0.1, MAX_PARAMETER_VALUE);
    int sideC = rand.getRandDouble(abs(sideA - sideB) + 0.1, sideA + sideB - 0.1);
    return new Triangle(sideA, sideB, sideC);
}

Figure* RandomFigureFactory::create()
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
}