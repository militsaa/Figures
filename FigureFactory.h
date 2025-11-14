#include "Figure.h"
#include <memory>
class FigureFactory {
public:
    virtual std::unique_ptr<Figure> create() = 0;
    virtual ~FigureFactory() = default;
};