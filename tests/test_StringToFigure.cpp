#include "catch_amalgamated.hpp"
#include "../src/FigureFactories/StringToFigure.h"

TEST_CASE("Parsing empty string throws")
{
    REQUIRE_THROWS(StringToFigure::stringToFigure(""));
}

TEST_CASE("Parsing incomplete triangle string")
{
    REQUIRE_THROWS(StringToFigure::stringToFigure("Triangle 10 20"));
}

TEST_CASE("Parsing incomplete rectangle string")
{
    REQUIRE_THROWS(StringToFigure::stringToFigure("Rectangle 10"));
}

TEST_CASE("Parsing incomplete circle string")
{
    REQUIRE_THROWS(StringToFigure::stringToFigure("Circle"));
}

TEST_CASE("Parsing ill-formed triangle string")
{
    REQUIRE_THROWS(StringToFigure::stringToFigure("triangle 10 abc -30"));
}

TEST_CASE("Parsing ill-formed rectangle string")
{
    REQUIRE_THROWS(StringToFigure::stringToFigure("rectangle 10 -19"));
}

TEST_CASE("Parsing ill-formed circle string")
{
    REQUIRE_THROWS(StringToFigure::stringToFigure("circle 10abc"));
}

TEST_CASE("Parsing triangle string with negative parameter")
{
    REQUIRE_THROWS(StringToFigure::stringToFigure("Triangle -10 15 20"));
    REQUIRE_THROWS(StringToFigure::stringToFigure("Triangle 10 -15 20"));
    REQUIRE_THROWS(StringToFigure::stringToFigure("Triangle 10 15 -20"));
}

TEST_CASE("Parsing rectangle string with negative parameter")
{
    REQUIRE_THROWS(StringToFigure::stringToFigure("Rectangle -10 15"));
    REQUIRE_THROWS(StringToFigure::stringToFigure("Rectangle 10 -15"));
}

TEST_CASE("Parsing unknown figure string")
{
    REQUIRE_THROWS(StringToFigure::stringToFigure("Mystery 10 15 6"));
}

