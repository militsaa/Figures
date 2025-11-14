#include "ConcreteFigureFactory.h"
#include "RandomFigureFactory.h"
#include "StreamFigureFactory.h"
#include <iostream>
#include <fstream>

FigureFactory* ConcreteFigureFactory::create(std::string& type)
{
    if (type == "Random") {
        return new RandomFigureFactory();
    }
    if (type == "STDIN") {
        return new StreamFigureFactory(std::cin);
    }
    if (type == "File") {
        std::string fileName;
        std::cin >> fileName;
        std::ifstream in(fileName);
        return new StreamFigureFactory(in);
    }
    throw std::invalid_argument("Invalid type!");
}