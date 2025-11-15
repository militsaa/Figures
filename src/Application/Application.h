#pragma once
#include <vector>
#include <memory>
#include "../Figures/Figure.h"

class Application {
    void listFigures(const std::vector<std::unique_ptr<Figure>>& figures);
    void saveInFile(const std::vector<std::unique_ptr<Figure>>& figures);
    void getPerimeter(const std::vector<std::unique_ptr<Figure>>& figures);
    void deleteAtIndex(std::vector<std::unique_ptr<Figure>>& figures);
    void cloneIndex(std::vector<std::unique_ptr<Figure>>& figures);
public:
    void run();
};