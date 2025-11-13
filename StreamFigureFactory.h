#include "FigureFactory.h"
#include <iostream>
class StreamFigureFactory : public FigureFactory {
    std::istream& in;
public:
    StreamFigureFactory(std::istream& input);
    virtual Figure* create() override;
};