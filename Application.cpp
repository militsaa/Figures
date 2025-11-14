#include "Application.h"
#include <iostream>
#include "FigureFactory.h"
#include "ConcreteFigureFactory.h"
#include <vector>
#include <fstream>
#include <iomanip> 

void Application::listFigures(const std::vector<std::unique_ptr<Figure>>& figures)
{
    for (int i = 0; i < figures.size();i++) {
        std::cout << figures[i]->to_string() << "\n";
    }
}

void Application::saveInFile(const std::vector<std::unique_ptr<Figure>>& figures)
{
    std::string fileName;
    std::cin >> fileName;
    std::ofstream ofs(fileName);
    if (!ofs) {
        std::cout << "File cannot be open!\n";
        return;
    }
    for (int i = 0;i < figures.size();i++) {
        ofs << figures[i]->to_string() << "\n";
    }
    //close?
}

void Application::deleteAtIndex(std::vector<std::unique_ptr<Figure>>& figures)
{
    std::cout << "Index to delete: ";
    int idx;
    std::cin >> idx;
    if (idx >= 0 && idx < figures.size()) {
        figures.erase(figures.begin() + idx);
    }
    else {
        std::cout << "Invalid index!\n";
    }
}

void Application::cloneIndex(std::vector<std::unique_ptr<Figure>>& figures)
{
    std::cout << "Index to clone: ";
    int idx;
    std::cin >> idx;
    if (idx >= 0 && idx < figures.size()) {
        figures.push_back(std::unique_ptr<Figure>(figures[idx]->clone()));
    }
    else {
        std::cout << "Invalid index!\n";
    }
}

void Application::run()
{
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Choose the input!\n";
    std::string inputType;
    std::cin >> inputType;

    ConcreteFigureFactory provider;
    std::unique_ptr<FigureFactory> factory = provider.create(inputType);

    std::cout << "How many figures do you want to load?\n";
    int n;
    std::cin >> n;

    std::vector<std::unique_ptr<Figure>> figures;
    for (int i = 0; i < n;i++) {
        try {
            figures.push_back(factory->create());
            break;
        }
        catch (const std::exception& e) {
            std::cout << "Couldn't create figure " << i << "\n";
        }
    }

    while (true) {
        std::string cmd;
        std::cin >> cmd;
        if (cmd == "list") {
            listFigures(figures);
        }
        else if (cmd == "clone") {
            cloneIndex(figures);
        }
        else if (cmd == "delete") {
            deleteAtIndex(figures);
        }
        else if (cmd == "safe") {
            saveInFile(figures);
        }
        else if (cmd == "exit") break;
    }
};