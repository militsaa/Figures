#include "catch_amalgamated.hpp"
#include "../src/FigureFactories/StreamFigureFactory.h"
#include <../src/Figures/Triangle.h>
#include <memory>
#include <sstream>

TEST_CASE("Creating figure from stream")
{
    std::stringstream oss;
    oss << "Triangle 10 5 7\n";
    oss << "Rectangle 10 5\n";
    oss << "Circle 10\n";
    StreamFigureFactory factory(oss);
    // std::unique_ptr<Figure> triangle = factory.create();
    // std::unique_ptr<Figure> rectangle = factory.create();
    // std::unique_ptr<Figure> circle = factory.create();
    REQUIRE(factory.create()->to_string() == "Triangle 10.00 5.00 7.00");
    REQUIRE(factory.create()->to_string() == "Rectangle 10.00 5.00");
    REQUIRE(factory.create()->to_string() == "Circle 10.00");
}

TEST_CASE("Empty stream")
{
    std::stringstream oss;
    StreamFigureFactory factory(oss);
    REQUIRE_THROWS_AS(factory.create(), std::runtime_error);
}

TEST_CASE("Creating figure after throwing on wrong string")
{
    std::stringstream oss;
    oss << "Triangle 10 7\n";
    oss << "Triangle 10 7a 8\n";
    oss << "Rectangle 10 5\n";
    StreamFigureFactory factory(oss);
    REQUIRE_THROWS_AS(factory.create(), std::invalid_argument);
    REQUIRE_THROWS_AS(factory.create(), std::invalid_argument);
    REQUIRE(factory.create()->to_string() == "Rectangle 10.00 5.00");
}