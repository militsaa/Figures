#include "Figure.h"
class FigureFactory {
public:
    virtual Figure* create() = 0;
    virtual ~FigureFactory() = default;
};