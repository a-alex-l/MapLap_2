#include "Catch.hpp"
#include "shapes/PointVector.hpp"

bool equal(double a, double b) {
    return -0.0001 < a - b && a - b < 0.001;
}

TEST_CASE("PointVector Addition: (1, 2) + (3, 4) = (4, 6).") {
    PointVector a(1, 2), b(3, 4);
    REQUIRE((equal((a + b).x, 4) && equal((a + b).y, 6)));
}

TEST_CASE("PointVector Addition: (1, 2) + (0, 0) = (1, 2).") {
    PointVector a(1, 2), b(0, 0);
    REQUIRE((equal((a + b).x, 1) && equal((a + b).y, 2)));
}

TEST_CASE("PointVector Addition: (0, 0) + (3, 4) = (4, 6).") {
    PointVector a(0, 0), b(3, 4);
    REQUIRE((equal((a + b).x, 3) && equal((a + b).y, 4)));
}

TEST_CASE("PointVector Addition: (1, 2) + (30000, 40000) = (30001, 40002).") {
    PointVector a(1, 2), b(30000, 40000);
    REQUIRE((equal((a + b).x, 30001) && equal((a + b).y, 40002)));
}

TEST_CASE("PointVector Multiplication: (1, 2) * 3 = (3, 6).") {
    PointVector a(1, 2);
    REQUIRE((equal((a * 3.0).x, 3) && equal((a * 3.0).y, 6)));
}

TEST_CASE("PointVector Multiplication: (1, 2) * 0 = (0, 0).") {
    PointVector a(1, 2);
    REQUIRE((equal((a * 0.0).x, 0) && equal((a * 0.0).y, 0)));
}

TEST_CASE("PointVector Multiplication: (1, 2) * 3.5 = (3.5, 7).") {
    PointVector a(1, 2);
    REQUIRE((equal((a * 3.5).x, 3.5) && equal((a * 3.5).y, 7)));
}

TEST_CASE("PointVector Addition + Multiplication: (1, 2) * 3 + (2.3, 3) = (5.3, 9).") {
    PointVector a(1, 2), b(2.3, 3);
    REQUIRE((equal((a * 3.0 + b).x, 5.3) && equal((a * 3.0 + b).y, 9)));
}

TEST_CASE("PointVector Addition + Multiplication: ((1, 2) * 3) + (2.3, 3) = (5.3, 9).") {
    PointVector a(1, 2), b(2.3, 3);
    PointVector c = a * 3;
    REQUIRE((equal((c + b).x, 5.3) && equal((c + b).y, 9)));
}

TEST_CASE("PointVector Addition + Multiplication: [(1, 2) * 3] + (2.3, 3) = (5.3, 9).") {
    PointVector a(1, 2), b(2.3, 3);
    a *= 3;
    REQUIRE((equal((a + b).x, 5.3) && equal((a + b).y, 9)));
}

TEST_CASE("PointVector Subtraction: (1, 2) - (2.3, 3) = (-1.3, -1).") {
    PointVector a(1, 2), b(2.3, 3);
    REQUIRE((equal((a - b).x, -1.3) && equal((a - b).y, -1)));
}

TEST_CASE("PointVector Division: (1, 2) / 3 = (0.333333, 0.666666).") {
    PointVector a(1, 2);
    REQUIRE((equal((a / 3).x, 0.333333) && equal((a / 3).y, 0.666666)));
}