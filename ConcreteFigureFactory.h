#include "AbstractFactory.h"

class ConcreteFigureFactory : public AbstractFactory {
public:
    virtual FigureFactory* create(std::string& type) override;
};