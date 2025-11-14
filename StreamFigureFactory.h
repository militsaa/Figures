#include "FigureFactory.h"
#include <istream>
class StreamFigureFactory : public FigureFactory {
    std::istream& in;
public:
    StreamFigureFactory(std::istream& input);
    virtual std::unique_ptr<Figure> create() override;
};