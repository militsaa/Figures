#include "FigureFactory.h"

class StreamFigureFactory : public FigureFactory {
public:
    virtual Figure* create() const override;
};