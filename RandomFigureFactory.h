#include "FigureFactory.h"
#include "RandomGenerator.h"
class RandomFigureFactory : public FigureFactory {
    const double MAX_PARAMETER_VALUE = 50;
    RandomGenerator rand;

    std::unique_ptr<Figure> randomCircle();
    std::unique_ptr<Figure> randomRectangle();
    std::unique_ptr<Figure> randomTriangle();

public:
    virtual std::unique_ptr<Figure> create() override;
};