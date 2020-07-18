#include "detector/Line.hpp"

Line::Line(const PointVector &one, const PointVector &two, double line_thick) noexcept:
            first(one), second(two), line_thickness(line_thick) {}

void Line::swap() {
    std::swap(first, second);
}

const PointVector& Line::get_first() const noexcept  { return first; }
const PointVector& Line::get_second() const noexcept { return second; }
