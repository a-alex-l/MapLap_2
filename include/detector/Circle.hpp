#ifndef MAPLAP2_0_CIRCLE_HPP
#define MAPLAP2_0_CIRCLE_HPP

#include "PointVector.hpp"
#include "BoolImage.hpp"

class Circle {
private:

    PointVector center = {0, 0};
    Fraction radius = -1, line_thickness = 1;

public:

    explicit Circle() = default;
    explicit Circle(int x1, int y1, int x2, int y2, int x3, int y3) noexcept;
    explicit Circle(Fraction x1, Fraction y1, Fraction x2,
                    Fraction y2, Fraction x3, Fraction y3) noexcept;
    explicit Circle(PointVector p1, PointVector p2, PointVector p3) noexcept;

    [[nodiscard]] double get_percent_intersection(const BoolImage &image) const;

    [[nodiscard]] Fraction get_x() const;
    [[nodiscard]] Fraction get_y() const;
    [[nodiscard]] Fraction get_radius() const;

};

#endif //MAPLAP2_0_CIRCLE_HPP
