#include "catch_amalgamated.hpp"
#include "../src/Figures/Circle.h"

TEST_CASE("Circle constructor does not throw on valid sides")
{
    REQUIRE_NOTHROW(Circle(5));
}

TEST_CASE("Circle throws on invalid sides")
{
    REQUIRE_THROWS_AS(Circle(0), std::invalid_argument);
    REQUIRE_THROWS_AS(Circle(-5), std::invalid_argument);
}

TEST_CASE("Circle constructor throws on overflow perimeter") {
    double max = 1e308;

    REQUIRE_THROWS_AS(Circle(max), std::overflow_error);
}

TEST_CASE("Find circle perimeter") {
    Circle circle(5.5);
    REQUIRE_NOTHROW(circle.perimeter());
    REQUIRE(circle.perimeter() - 95.03 < 1e-10);
};

TEST_CASE("Circle to_string returns correct format") {
    Circle circle(10);

    REQUIRE(circle.to_string() == "Circle 10.00");
}

TEST_CASE("Circle clone creates an identical but separate object")
{
    Circle circle(10);
    Figure* cloned = circle.clone();

    REQUIRE(cloned->to_string() == circle.to_string());

    REQUIRE(cloned != &circle);

    delete cloned;
}

TEST_CASE("Cloning circle through Figure*")
{
    Figure* figure = new Circle(10);

    Figure* cloned = figure->clone();

    REQUIRE(cloned->to_string() == figure->to_string());
    REQUIRE(cloned != figure);

    delete figure;
    delete cloned;
}

