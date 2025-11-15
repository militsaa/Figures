#pragma once
#include "FigureFactory.h"
#include <memory>

class AbstractFactory {
public:
    virtual std::unique_ptr<FigureFactory> create(std::string& type) = 0;
    virtual ~AbstractFactory() = default;
};