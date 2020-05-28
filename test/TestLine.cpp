#include "Catch.hpp"
#include "Line.hpp"

bool equal(const PointVector &a, const PointVector &b) {
    return -0.0001f < a.get_x() - b.get_x() && a.get_x() - b.get_x() < 0.001f and
           -0.0001f < a.get_y() - b.get_y() && a.get_y() - b.get_y() < 0.001f;
}

TEST_CASE("Line Swap: ((1, 2), (3, 4)) -> ((3, 4), (1, 2)).") {
    Line a(PointVector(1, 2), PointVector(3, 4)), b = a;
    a.swap();
    REQUIRE((equal(a.get_first(), b.get_second()) && equal(a.get_second(), b.get_first())));
}