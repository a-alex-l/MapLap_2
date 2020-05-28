#include "Line.hpp"

Line::Line(const PointVector &one, const PointVector &two) noexcept: first(one), second(two) {}

void Line::swap() {
    std::swap(first, second);
}

const PointVector& Line::get_first() const noexcept { return first; }
const PointVector& Line::get_second() const noexcept { return second; }
