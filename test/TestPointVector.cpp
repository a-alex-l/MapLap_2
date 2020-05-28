#include "Catch.hpp"
#include "PointVector.hpp"

bool equal(float a, float b) {
    return -0.0001f < a - b && a - b < 0.001f;
}

TEST_CASE("PointVector Sum: (1, 2) + (3, 4) = (4, 6).") {
    PointVector a(1, 2), b(3, 4);
    REQUIRE((equal((a + b).get_x(), 4) && equal((a + b).get_y(), 6)));
}

TEST_CASE("PointVector Sum: (1, 2) + (0, 0) = (1, 2).") {
    PointVector a(1, 2), b(0, 0);
    REQUIRE((equal((a + b).get_x(), 1) && equal((a + b).get_y(), 2)));
}

TEST_CASE("PointVector Sum: (0, 0) + (3, 4) = (4, 6).") {
    PointVector a(0, 0), b(3, 4);
    REQUIRE((equal((a + b).get_x(), 3) && equal((a + b).get_y(), 4)));
}

TEST_CASE("PointVector Sum: (1, 2) + (30000, 40000) = (30001, 40002).") {
    PointVector a(1, 2), b(30000, 40000);
    REQUIRE((equal((a + b).get_x(), 30001) && equal((a + b).get_y(), 40002)));
}
