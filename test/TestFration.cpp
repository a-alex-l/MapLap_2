#include "Catch.hpp"
#include "detector/Fraction.hpp"

TEST_CASE("Fraction Start") { printf("Testing Fraction\n"); }

TEST_CASE("Fraction == 1") {
    Fraction a(3, 4), b(6, 8);
    REQUIRE(a == b);
}

TEST_CASE("Fraction == 2") {
    Fraction a(3 * 8, 4 * 8), b(6 * 123, 8 * 123);
    REQUIRE(a == b);
}

TEST_CASE("Fraction get_numerator 1") {
    Fraction a(3, 4);
    REQUIRE(a.get_numerator() == 3);
}

TEST_CASE("Fraction get_numerator 2") {
    Fraction a(12321, 4);
    REQUIRE(a.get_numerator() == 12321);
}

TEST_CASE("Fraction get_denominator 1") {
    Fraction a(3, 4);
    REQUIRE(a.get_denominator() == 4);
}

TEST_CASE("Fraction get_denominator 2") {
    Fraction a(12321, 152);
    REQUIRE(a.get_denominator() == 152);
}

TEST_CASE("Fraction reduce 1") {
    Fraction a(3, 4), b(6, 8);
    b.reduce();
    REQUIRE(a.get_numerator() == b.get_numerator());
    REQUIRE(a.get_denominator() == b.get_denominator());
}

TEST_CASE("Fraction reduce 2") {
    Fraction a(3, 4), b(6, 8);
    b.reduce();
    REQUIRE(a.get_numerator() == b.get_numerator());
    REQUIRE(a.get_denominator() == b.get_denominator());
}

TEST_CASE("Fraction + 1") {
    Fraction a(3, 4), b(7, 8);
    REQUIRE(a + b == Fraction(13, 8));
}

TEST_CASE("Fraction + 2") {
    Fraction a(3, 4), b(7, 4);
    REQUIRE(a + b == Fraction(5, 2));
}

TEST_CASE("Fraction + 3") {
    Fraction a(13, 8), b(5, 4);
    REQUIRE(a + b == Fraction(23, 8));
}

TEST_CASE("Fraction * 1") {
    Fraction a(3, 4), b(7, 8);
    REQUIRE(a * b == Fraction(3 * 7, 4 * 8));
}

TEST_CASE("Fraction * 2") {
    Fraction a(312, 4), b(7, 8);
    REQUIRE(a * b == Fraction(312 * 7, 4 * 8));
}

TEST_CASE("Fraction * 3") {
    Fraction a(3, 1), b(7, 8);
    REQUIRE(a * b == Fraction(3 * 7, 8));
}

TEST_CASE("Fraction * 4") {
    Fraction a(0, 10000000000000000), b(7, 8);
    REQUIRE(a * b == Fraction(0, 1));
}

TEST_CASE("Fraction * 5") {
    Fraction a(-1, 1), b(7, 8);
    REQUIRE(a * b == Fraction(-7, 8));
}

TEST_CASE("Fraction * 6") {
    Fraction a(-1, 1), b(7, 8);
    REQUIRE(a * b == Fraction(-7, 8));
}

TEST_CASE("Fraction * 7") {
    Fraction a(-8, 1), b(-7, 8);
    REQUIRE(a * b == Fraction(7, 1));
}

TEST_CASE("Fraction / 1") {
    Fraction a(-8, 1), b(-7, 8);
    REQUIRE(a / b == Fraction(64, 7));
}

TEST_CASE("Fraction / 2") {
    Fraction a(0, 1), b(19, 8);
    REQUIRE(a / b == Fraction(0, 1));
}

TEST_CASE("Fraction / 3") {
    Fraction a(20, 1), b(19, 8);
    REQUIRE(a / b == Fraction(20 * 8, 19));
}

TEST_CASE("Fraction / 4") {
    Fraction a(3, 4), b(3, 4);
    REQUIRE(a / b == Fraction(1, 1));
}

TEST_CASE("Fraction make_base 1") {
    Fraction a(3, 4), b(1, 100);
    REQUIRE((a + b).make_base(10) == Fraction(8, 10));
}

TEST_CASE("Fraction make_base 2") {
    Fraction a(3, 4), b(1, 100);
    REQUIRE((a - b).make_base(10) == Fraction(7, 10));
}

TEST_CASE("Fraction make_base 3") {
    Fraction a(3, 4);
    REQUIRE(a.make_base(10) == Fraction(7, 10));
}

TEST_CASE("Fraction make_base 4") {
    Fraction a(8, 10);
    REQUIRE(a.make_base(10) == Fraction(8, 10));
}

TEST_CASE("Fraction < 1") {
    Fraction a(8, 10), b(81, 100);
    REQUIRE(a < b);
}

TEST_CASE("Fraction < 2") {
    Fraction a(8, 10), b(7, 8);
    REQUIRE(a < b);
}

TEST_CASE("Fraction < 3") {
    Fraction a(-8, 10), b(0, 8);
    REQUIRE(a < b);
}

TEST_CASE("Fraction < 4") {
    Fraction a(0, 1), b(1, 1000000000000000000);
    REQUIRE(a < b);
}

TEST_CASE("Fraction < 5") {
    Fraction a(0, 1), b(-1, 1000000000000000000);
    REQUIRE((!(a < b)));
}

TEST_CASE("Fraction < 6") {
    Fraction a(-1, 1), b(-1, 1000000000000000000);
    REQUIRE((!(b < a)));
}

TEST_CASE("Fraction < 7") {
    Fraction a(-1, 1), b(-1, 1);
    REQUIRE((!(b < a)));
}

TEST_CASE("Fraction <= 1") {
    Fraction a(8, 10), b(81, 100);
    REQUIRE(a <= b);
}

TEST_CASE("Fraction <= 2") {
    Fraction a(8, 10), b(7, 8);
    REQUIRE(a <= b);
}

TEST_CASE("Fraction <= 3") {
    Fraction a(-8, 10), b(0, 8);
    REQUIRE(a <= b);
}

TEST_CASE("Fraction <= 4") {
    Fraction a(0, 1), b(1, 1000000000000000000);
    REQUIRE(a <= b);
}

TEST_CASE("Fraction <= 5") {
    Fraction a(0, 1), b(-1, 1000000000000000000);
    REQUIRE((!(a <= b)));
}

TEST_CASE("Fraction <= 6") {
    Fraction a(-1, 1), b(-1, 1000000000000000000);
    REQUIRE((!(b <= a)));
}

TEST_CASE("Fraction <= 7") {
    Fraction a(-1, 1), b(-1, 1);
    REQUIRE(b <= a);
}

TEST_CASE("Fraction Fraction(double) 1") {
    Fraction a(0.5);
    REQUIRE(a == Fraction(1, 2));
}

TEST_CASE("Fraction Fraction(double) 2") {
    Fraction a(0.05);
    REQUIRE(a == Fraction(5, 100));
}

TEST_CASE("Fraction Fraction(double) 3") {
    Fraction a(0.333333);
    REQUIRE(a == Fraction(33333, 100000));
}

TEST_CASE("Fraction Fraction(double) 4") {
    Fraction a(0.666666);
    REQUIRE(a == Fraction(66666, 100000));
}

TEST_CASE("Fraction Fraction(double) 5") {
    Fraction a(-1.0);
    REQUIRE(a == Fraction(-1, 1));
}

TEST_CASE("Fraction End") { printf("Finished Fraction\n"); }