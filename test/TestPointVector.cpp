#include "Catch.hpp"
#include "detector/PointVector.hpp"

TEST_CASE("PointVector Addition: (1, 2) + (3, 4) = (4, 6).") {
    PointVector a(1, 2), b(3, 4);
    REQUIRE(((a + b).get_x() == 4 && (a + b).get_y() == 6));
}

TEST_CASE("PointVector Addition: (1, 2) + (0, 0) = (1, 2).") {
    PointVector a(1, 2), b(0, 0);
    REQUIRE(((a + b).get_x() == 1 && (a + b).get_y() == 2));
}

TEST_CASE("PointVector Addition: (0, 0) + (3, 4) = (4, 6).") {
    PointVector a(0, 0), b(3, 4);
    REQUIRE(((a + b).get_x() == 3 && (a + b).get_y() == 4));
}

TEST_CASE("PointVector Addition: (1, 2) + (30000, 40000) = (30001, 40002).") {
    PointVector a(1, 2), b(30000, 40000);
    REQUIRE(((a + b).get_x() == 30001 && (a + b).get_y() == 40002));
}

TEST_CASE("PointVector Multiplication: (1, 2) * 3 = (3, 6).") {
    PointVector a(1, 2);
    REQUIRE(((a * 3).get_x() == 3 && (a * 3).get_y() == 6));
}

TEST_CASE("PointVector Multiplication: (1, 2) * 0 = (0, 0).") {
    PointVector a(1, 2);
    REQUIRE(((a * 0).get_x() == 0 && (a * 0).get_y() == 0));
}

TEST_CASE("PointVector Multiplication: (1, 2) * 3.5 = (3.5, 7).") {
    PointVector a(1, 2);
    REQUIRE(((a * Fraction(7, 2)).get_x() == Fraction(7, 2) && (a * Fraction(7, 2)).get_y() == 7));
}

TEST_CASE("PointVector Addition + Multiplication: (1, 2) * 3 + (2.3, 3) = (5.3, 9).") {
    PointVector a(1, 2), b(Fraction(23, 10), 3);
    REQUIRE(((a * 3 + b).get_x() == Fraction(53, 10) && (a * 3 + b).get_y() == 9));
}

TEST_CASE("PointVector Addition + Multiplication: ((1, 2) * 3) + (2.3, 3) = (5.3, 9).") {
    PointVector a(1, 2), b(Fraction(23, 10), 3);
    PointVector c = a * 3;
    REQUIRE(((c + b).get_x() == Fraction(53, 10) && (c + b).get_y() == 9));
}

TEST_CASE("PointVector Addition + Multiplication: [(1, 2) * 3] + (2.3, 3) = (5.3, 9).") {
    PointVector a(1, 2), b(Fraction(23, 10), 3);
    a *= 3;
    REQUIRE(((a + b).get_x() == Fraction(53, 10) && (a + b).get_y() == 9));
}

TEST_CASE("PointVector Subtraction: (1, 2) - (2.3, 3) = (-1.3, -1).") {
    PointVector a(1, 2), b(Fraction(23, 10), 3);
    REQUIRE(((a - b).get_x() == Fraction(-13, 10) && (a - b).get_y() == -1));
}

TEST_CASE("PointVector Division: (1, 2) / 3 = (1/3, 2/3).") {
    PointVector a(1, 2);
    REQUIRE(((a / 3).get_x() == Fraction(1, 3) && (a / 3).get_y() == Fraction(2, 3)));
}