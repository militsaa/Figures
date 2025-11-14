#include "FigureFactory.h"

class AbstractFactory {
public:
    virtual FigureFactory* create(std::string& type) = 0;
    virtual ~AbstractFactory() = default;
};