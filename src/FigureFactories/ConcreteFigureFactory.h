#pragma once
#include "AbstractFactory.h"
#include <memory>

class ConcreteFigureFactory : public AbstractFactory {
public:
    virtual std::unique_ptr<FigureFactory> create(std::string& type) override;
};