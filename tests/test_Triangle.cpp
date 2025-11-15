#include "catch_amalgamated.hpp"
#include "../src/Figures/Triangle.h"

TEST_CASE("Triangle constructor does not throw on valid sides")
{
    REQUIRE_NOTHROW(Triangle(5, 10, 7));
}

TEST_CASE("Triangle throws on invalid sides")
{
    REQUIRE_THROWS_AS(Triangle(-5, 10, 7), std::invalid_argument);
    REQUIRE_THROWS_AS(Triangle(10, -5, 7), std::invalid_argument);
    REQUIRE_THROWS_AS(Triangle(10, 7, -5), std::invalid_argument);

    REQUIRE_THROWS_AS(Triangle(1, 2, 20), std::invalid_argument);
    REQUIRE_THROWS_AS(Triangle(10, 1, 2), std::invalid_argument);
}

TEST_CASE("Triangle constructor throws on overflow") {
    double max = 1e308;

    REQUIRE_THROWS_AS(Triangle(max, max, max), std::overflow_error);
}

TEST_CASE("Find triangle perimeter") {
    Triangle triangle(1.5, 3, 4);
    REQUIRE_NOTHROW(triangle.perimeter());
    REQUIRE(triangle.perimeter() - 8.5 < 1e-10);
};

TEST_CASE("Triangle to_string returns correct format") {
    Triangle triangle(10, 15, 20);

    REQUIRE(triangle.to_string() == "Triangle 10.00 15.00 20.00");
}

TEST_CASE("Triangle clone creates an identical but separate object")
{
    Triangle triangle(10, 15, 20);
    Figure* cloned = triangle.clone();

    REQUIRE(cloned->to_string() == triangle.to_string());

    REQUIRE(cloned != &triangle);

    delete cloned;
}

TEST_CASE("Cloning triangle through Figure*")
{
    Figure* figure = new Triangle(10, 15, 20);

    Figure* cloned = figure->clone();

    REQUIRE(cloned->to_string() == figure->to_string());
    REQUIRE(cloned != figure);

    delete figure;
    delete cloned;
}