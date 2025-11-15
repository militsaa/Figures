#include "catch_amalgamated.hpp"
#include "../src/Figures/Rectangle.h"

TEST_CASE("Rectangle constructor does not throw on valid sides")
{
    REQUIRE_NOTHROW(Rectangle(5, 10.5));
}

TEST_CASE("Rectangle throws on invalid sides")
{
    REQUIRE_THROWS_AS(Rectangle(0, 10), std::invalid_argument);
    REQUIRE_THROWS_AS(Rectangle(3, -5), std::invalid_argument);
}

TEST_CASE("Rectangle constructor throws on overflow perimeter") {
    double max = 1e308;

    REQUIRE_THROWS_AS(Rectangle(max, max), std::overflow_error);
}

TEST_CASE("Find rectangle perimeter") {
    Rectangle rectangle(4.5, 3);
    REQUIRE_NOTHROW(rectangle.perimeter());
    REQUIRE(rectangle.perimeter() - 15 < 1e-10);
};

TEST_CASE("Rectangle to_string returns correct format") {
    Rectangle rectangle(10, 20);

    REQUIRE(rectangle.to_string() == "Rectangle 10.00 20.00");
}

TEST_CASE("Rectangle clone creates an identical but separate object")
{
    Rectangle rectangle(10, 15);
    Figure* cloned = rectangle.clone();

    REQUIRE(cloned->to_string() == rectangle.to_string());

    REQUIRE(cloned != &rectangle);

    delete cloned;
}

TEST_CASE("Cloning rectangle through Figure*")
{
    Figure* figure = new Rectangle(10, 15);

    Figure* cloned = figure->clone();

    REQUIRE(cloned->to_string() == figure->to_string());
    REQUIRE(cloned != figure);

    delete figure;
    delete cloned;
}

