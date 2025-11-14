#include "ConcreteFigureFactory.h"
#include "RandomFigureFactory.h"
#include "StreamFigureFactory.h"
#include <iostream>
#include <fstream>

std::unique_ptr<FigureFactory> ConcreteFigureFactory::create(std::string& type)
{
    if (type == "Random") {
        return std::make_unique<RandomFigureFactory>();
    }
    if (type == "STDIN") {
        return std::make_unique<StreamFigureFactory>(std::cin);
    }
    if (type == "File") {
        std::string fileName;
        std::cin >> fileName;
        std::ifstream in(fileName);
        return std::make_unique<StreamFigureFactory>(in);
    }
    throw std::invalid_argument("Invalid type!");
}