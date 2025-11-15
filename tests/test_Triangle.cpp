#include "catch_amalgamated.hpp"
#include "../src/Figures/Triangle.h"

TEST_CASE("Find perimeter") {
    Triangle triangle(10, 15.5, 20.3);
    int perimeter = triangle.perimeter();
    REQUIRE(perimeter == 45.8);
}