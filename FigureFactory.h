#include "Figure.h"
class FigureFactory {
public:
    virtual Figure* create() const = 0;
    virtual ~FigureFactory() = default;
};