#include "Catch.hpp"
#include "shapes/Line.hpp"

TEST_CASE("Line Start") { printf("Testing Line\n"); }

TEST_CASE("Line get_first 1") {
    Line a({1, 2}, {3, 4});
    REQUIRE((a.get_first() == PointVector(1, 2)));
}

TEST_CASE("Line get_first 2") {
    Line a({1, 2}, {3, 4});
    REQUIRE((a.get_second() == PointVector(3, 4)));
}

TEST_CASE("Line == 1") {
    Line a({1, 2}, {3, 4}), b = a;
    REQUIRE((a == b));
}

TEST_CASE("Line == 2") {
    Line a({12435, 21524}, {328357196, 42431}), b = a;
    REQUIRE((a == b));
}

TEST_CASE("Line == 3") {
    Line a({134.0 / 56, 21524}, {328357196, 42431}), b = a;
    REQUIRE((a == b));
}

TEST_CASE("Line == 4") {
    Line a({134.0 / 56, 21524}, {328357196, 42431});
    Line b({134.0 / 56, 24}, {2, 4});
    REQUIRE((!(a == b)));
}

TEST_CASE("Line == 5") {
    Line a({134.0 / 56, 21524}, {328357196, 42431});
    Line b({134.0 / 56, 24}, {328357196, 42431});
    REQUIRE((!(a == b)));
}

TEST_CASE("Line != 1") {
    Line a({134.0 / 56, 21524}, {328357196, 42431});
    Line b({134.0 / 56, 24}, {328357196, 42431});
    REQUIRE((a != b));
}

TEST_CASE("Line != 2") {
    Line a({134.0 / 56, 21524}, {328357196, 42431});
    Line b({134.0 / 56, 21524}, {328357196, 42431});
    REQUIRE((!(a != b)));
}

TEST_CASE("Line swap 1") {
    Line a(PointVector(1, 2), PointVector(3, 4)), b = a;
    a.swap();
    REQUIRE((a.get_first() == b.get_second() && a.get_second() == b.get_first()));
}

TEST_CASE("Line swap 2") {
    Line a(PointVector(100.0 / 11, 2), PointVector(3, 4)), b = a;
    a.swap();
    REQUIRE((a.swap() == b));
    REQUIRE((a == b));
}

TEST_CASE("Line rotate 1") {
    Line a({0, 0}, {1, 0});
    Line b({0, 0}, {0, 1});
    a.rotate_around_first(M_PI / 2);
    REQUIRE((a == b));
}

TEST_CASE("Line rotate 2") {
    Line a({0, 0}, {1, 0});
    Line b({0, 0}, {0, 1});
    b.rotate_around_first(-M_PI / 2);
    REQUIRE((a == b));
}

TEST_CASE("Line rotate 3") {
    Line a({0, 0}, {1, 0});
    Line b({0, 0}, {-1, 0});
    b.rotate_around_first(-M_PI);
    REQUIRE((a == b));
    b.rotate_around_first(M_PI);
    a.rotate_around_first(-3 * M_PI);
    REQUIRE((a == b));
}

TEST_CASE("Line rotate 4") {
    Line a({12, 15}, {13, 15});
    Line b({12, 15}, {12, 16});
    b.rotate_around_first(-M_PI / 2);
    REQUIRE((a == b));
}

TEST_CASE("Line rotate 5") {
    Line a({1, 0}, {0, 0});
    Line b({1, 0}, {1, 1});
    b.rotate_around_first(M_PI / 2);
    REQUIRE((a == b));
}

TEST_CASE("Line length 1") {
    Line a({1, 0}, {0, 0});
    REQUIRE((a.length() == 1));
}

TEST_CASE("Line length 2") {
    Line a({11021, 12397132}, {11029, 12397138});
    REQUIRE((a.length() == 10));
}

TEST_CASE("Line End") { printf("Finished Line\n"); }