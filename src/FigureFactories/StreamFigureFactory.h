#pragma once
#include "FigureFactory.h"
#include <istream>
#include <memory>
class StreamFigureFactory : public FigureFactory {
    std::istream& in;
public:
    StreamFigureFactory(std::istream& input);
    virtual std::unique_ptr<Figure> create() override;
};