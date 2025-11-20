#pragma once
#include "FigureFactory.h"
#include <istream>
#include <memory>
class StreamFigureFactory : public FigureFactory {
    std::istream* in;
    bool shouldDelete;

public:
    StreamFigureFactory(std::istream& input);
    StreamFigureFactory(std::string& fileName);
    virtual ~StreamFigureFactory();

    virtual std::unique_ptr<Figure> create() override;
};