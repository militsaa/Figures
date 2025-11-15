#pragma once
#include "FigureFactory.h"
#include "../Utils/RandomGenerator.h"
#include <memory>
class RandomFigureFactory : public FigureFactory {
    const double MAX_PARAMETER_VALUE = 2000;
    RandomGenerator rand;

    std::unique_ptr<Figure> randomCircle();
    std::unique_ptr<Figure> randomRectangle();
    std::unique_ptr<Figure> randomTriangle();

public:
    virtual std::unique_ptr<Figure> create() override;
};