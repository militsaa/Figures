#include "StreamFigureFactory.h"
#include "StringToFigure.h"

StreamFigureFactory::StreamFigureFactory(std::istream& input) :in(input) {}

std::unique_ptr<Figure> StreamFigureFactory::create()
{
    std::string line;
    if (!std::getline(in, line))
        throw std::runtime_error("Input stream is not in a good state.");
    return StringToFigure::stringToFigure(line);
}