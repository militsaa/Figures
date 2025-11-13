#include "FigureFactory.h"

class RandomFigureFactory : public FigureFactory {
public:
    virtual Figure* create() const override;
};