#ifndef MAPLAP2_0_CIRCLE_HPP
#define MAPLAP2_0_CIRCLE_HPP

#include "PointVector.hpp"
#include "BoolImage.hpp"

class Circle {
private:

    PointVector center = {0, 0};
    double radius = -1, line_thickness = 1;

public:

    explicit Circle() = default;
    explicit Circle(int x1, int y1, int x2, int y2, int x3, int y3) noexcept;
    explicit Circle(double x1, double y1, double x2,
                    double y2, double x3, double y3) noexcept;
    explicit Circle(PointVector p1, PointVector p2, PointVector p3) noexcept;

    [[nodiscard]] double get_percent_intersection(const BoolImage &image) const;

    [[nodiscard]] double get_x() const;
    [[nodiscard]] double get_y() const;
    [[nodiscard]] double get_radius() const;

};

#endif //MAPLAP2_0_CIRCLE_HPP
