#include "Catch.hpp"
#include "detector/Line.hpp"

TEST_CASE("Line Swap: ((1, 2), (3, 4)) -> ((3, 4), (1, 2)).") {
    Line a(PointVector(1, 2), PointVector(3, 4)), b = a;
    a.swap();
    REQUIRE((a.get_first() == b.get_second() && a.get_second() == b.get_first()));
}