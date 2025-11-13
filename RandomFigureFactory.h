#include "FigureFactory.h"
#include "RandomGenerator.h"
class RandomFigureFactory : public FigureFactory {
    const double MAX_PARAMETER_VALUE = 50;
    RandomGenerator rand;

    Figure* randomCircle();
    Figure* randomRectangle();
    Figure* randomTriangle();

public:
    virtual Figure* create() override;
};