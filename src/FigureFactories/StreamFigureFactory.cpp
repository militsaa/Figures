#include "StreamFigureFactory.h"
#include "StringToFigure.h"
#include <fstream>
#include <iostream>

StreamFigureFactory::StreamFigureFactory(std::istream& input) :in(&input) {
    shouldDelete = false;
}

StreamFigureFactory::StreamFigureFactory(std::string& fileName)
{
    shouldDelete = true;
    in = new std::ifstream(fileName);
}

StreamFigureFactory::~StreamFigureFactory()
{
    if (shouldDelete)
        delete in;
}

std::unique_ptr<Figure> StreamFigureFactory::create()
{
    std::string line;
    if (!std::getline(*in, line))
        throw std::runtime_error("Input stream is not in a good state.");
    return StringToFigure::stringToFigure(line);
}