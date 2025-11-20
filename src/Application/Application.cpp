#include "Application.h"
#include <iostream>
#include "../FigureFactories/FigureFactory.h"
#include "../FigureFactories/ConcreteFigureFactory.h"
#include <vector>
#include <fstream>
#include <limits>

void Application::listFigures(const std::vector<std::unique_ptr<Figure>>& figures)
{
    for (int i = 0; i < figures.size();i++) {
        std::cout << figures[i]->to_string() << "\n";
    }
}

void Application::saveInFile(const std::vector<std::unique_ptr<Figure>>& figures)
{
    std::cout << "Write name of the file!\n";
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
    ofs.close();
}

void Application::getPerimeter(const std::vector<std::unique_ptr<Figure>>& figures)
{
    for (int i = 0; i < figures.size(); i++) {
        try {
            std::cout << figures[i]->perimeter() << '\n';
        }
        catch (const std::exception& e) {
            std::cout << "Perimeter is too big to print!\n";
        }
    }
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
    std::cout << "Choose the input!\n";
    std::string inputType;
    std::cin >> inputType;

    ConcreteFigureFactory provider;
    std::unique_ptr<FigureFactory> factory = nullptr;

    while (factory == nullptr) {
        try {
            factory = provider.create(inputType);
        }
        catch (const std::exception& e) {
            std::cout << "Wrong creation type! Choose between Random, STDIN and  File!\n";
            std::cin >> inputType;
        }
    }

    std::cout << "How many figures do you want to create?\n";
    int n;
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max()
        , '\n');

    std::vector<std::unique_ptr<Figure>> figures;
    for (int i = 0; i < n;i++) {
        try {
            figures.push_back(factory->create());
        }
        catch (const std::exception& e) {
            std::cout << "Couldn't create figure " << i << "\n";
        }
    }

    while (true) {
        std::cout << "Write down a command!\n";
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
        else if (cmd == "save") {
            saveInFile(figures);
        }
        else if (cmd == "perimeters") {
            getPerimeter(figures);
        }
        else if (cmd == "exit") break;
        else {
            std::cout << "Invalid command!\n";
        }
    }
};