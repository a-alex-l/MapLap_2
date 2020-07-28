#include "Catch.hpp"
#include "detector/PointVector.hpp"

bool equal(const PointVector &a, const PointVector &b) {
    return (a - b).length() < 0.00001;
}

TEST_CASE("PointVector Start") { printf("Testing PointVector\n"); }

TEST_CASE("PointVector Addition: (1, 2) + (3, 4) = (4, 6).") {
    PointVector a(1, 2), b(3, 4);
    REQUIRE(((a + b).y == 4 && (a + b).x == 6));
}

TEST_CASE("PointVector Addition: (1, 2) + (0, 0) = (1, 2).") {
    PointVector a(1, 2), b(0, 0);
    REQUIRE(((a + b).y == 1 && (a + b).x == 2));
}

TEST_CASE("PointVector Addition: (0, 0) + (3, 4) = (4, 6).") {
    PointVector a(0, 0), b(3, 4);
    REQUIRE(((a + b).y == 3 && (a + b).x == 4));
}

TEST_CASE("PointVector Addition: (1, 2) + (30000, 40000) = (30001, 40002).") {
    PointVector a(1, 2), b(30000, 40000);
    REQUIRE(((a + b).y == 30001 && (a + b).x == 40002));
}

TEST_CASE("PointVector Multiplication: (1, 2) * 3 = (3, 6).") {
    PointVector a(1, 2);
    REQUIRE(((a * 3).y == 3 && (a * 3).x == 6));
}

TEST_CASE("PointVector Multiplication: (1, 2) * 0 = (0, 0).") {
    PointVector a(1, 2);
    REQUIRE(((a * 0).y == 0 && (a * 0).x == 0));
}

TEST_CASE("PointVector Multiplication: (1, 2) * 3.5 = (3.5, 7).") {
    PointVector a(1, 2);
    REQUIRE(((a * Fraction(7, 2)).y == Fraction(7, 2) && (a * Fraction(7, 2)).x == 7));
}

TEST_CASE("PointVector Addition + Multiplication: (1, 2) * 3 + (2.3, 3) = (5.3, 9).") {
    PointVector a(1, 2), b(Fraction(23, 10), 3);
    REQUIRE(((a * 3 + b).y == Fraction(53, 10) && (a * 3 + b).x == 9));
}

TEST_CASE("PointVector Addition + Multiplication: ((1, 2) * 3) + (2.3, 3) = (5.3, 9).") {
    PointVector a(1, 2), b(Fraction(23, 10), 3);
    PointVector c = a * 3;
    REQUIRE(((c + b).y == Fraction(53, 10) && (c + b).x == 9));
}

TEST_CASE("PointVector Addition + Multiplication: [(1, 2) * 3] + (2.3, 3) = (5.3, 9).") {
    PointVector a(1, 2), b(Fraction(23, 10), 3);
    a *= 3;
    REQUIRE(((a + b).y == Fraction(53, 10) && (a + b).x == 9));
}

TEST_CASE("PointVector Subtraction: (1, 2) - (2.3, 3) = (-1.3, -1).") {
    PointVector a(1, 2), b(Fraction(23, 10), 3);
    REQUIRE(((a - b).y == Fraction(-13, 10) && (a - b).x == -1));
}

TEST_CASE("PointVector Division: (1, 2) / 3 = (1/3, 2/3).") {
    PointVector a(1, 2);
    REQUIRE(((a / 3).y == Fraction(1, 3) && (a / 3).x == Fraction(2, 3)));
}

TEST_CASE("PointVector Rotation: (1, 0).rotate(PI/2) = (0, 1).") {
    PointVector a(1, 0);
    a.rotate(M_PI / 2.0);
    REQUIRE(equal(a, PointVector(0, 1)));
}

TEST_CASE("PointVector Rotation: (1, 2).rotate(PI/2) = (-2, 1).") {
    PointVector a(1, 2);
    a.rotate(M_PI / 2.0);
    REQUIRE(equal(a, PointVector(-2, 1)));
}

TEST_CASE("PointVector Rotation: (1, 2).rotate(-PI/2) = (2, -1).") {
    PointVector a(1, 2);
    a.rotate(-M_PI / 2.0);
    REQUIRE(equal(a, PointVector(2, -1)));
}

TEST_CASE("PointVector Rotation: (1, 2).rotate(-PI) = (-1, -2).") {
    PointVector a(1, 2);
    a.rotate(-M_PI);
    REQUIRE(equal(a, PointVector(-1, -2)));
}

TEST_CASE("PointVector Rotation: (1, 2).rotate(1600 * PI) = (1, 2).") {
    PointVector a(1, 2);
    REQUIRE(equal(a.rotate(1600 * M_PI), PointVector(1, 2)));
    REQUIRE(equal(a, PointVector(1, 2)));
}

TEST_CASE("PointVector Rotation: (1, 0).rotate(1) = (-14283/12500, 192207/100000).") {
    PointVector a(1, 2);
    a.rotate(1);
    REQUIRE(equal(a, PointVector(Fraction(-14283, 12500), Fraction(192207, 100000))));
}

TEST_CASE("PointVector Rotation: (1, 0).rotate(-1) = (-14283/12500, -192207/100000).") {
    PointVector a(1, 2);
    a.rotate(-1);
    REQUIRE(equal(a, PointVector(Fraction(55581, 25000), Fraction(23913, 100000))));
}

TEST_CASE("PointVector End") { printf("Finished PointVector\n"); }