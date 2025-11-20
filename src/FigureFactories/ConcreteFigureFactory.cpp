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
        std::cout << "Name of the file?\n";
        std::string fileName;
        std::cin >> fileName;
        return std::make_unique<StreamFigureFactory>(fileName);
    }
    throw std::invalid_argument("Invalid type!");
}