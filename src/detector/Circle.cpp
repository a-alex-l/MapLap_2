#include "detector/Circle.hpp"
#include "detector/Settings.hpp"

Circle::Circle(int x1, int y1, int x2, int y2, int x3, int y3) noexcept {
    Fraction divider = 2 * (y2  - y1) * (x3 - x2) - 2 * (x2 - x1) * (y3  - y2);
    if (divider != 0) {
        Fraction e = y2 * y2 - y1 * y1 + x2 * x2 - x1 * x1;
        Fraction f = y3 * y3 - y1 * y1 + x3 * x3 - x1 * x1;
        center = PointVector(((x3 - x1) * e - (x2 - x1) * f) / divider,
                             ((y2 - y1) * f - (y3 - y1) * e) / divider);
        center.x.reduce(), center.y.reduce();
        center.x.make_base(4), center.y.make_base(4);
        Fraction radius2 = (center.x - x1).reduce() * (center.x - x1).reduce() +
                           (center.y - y1).reduce() * (center.y - y1).reduce();
        radius2.reduce(), radius2.make_base(10);
        radius = sqrt(radius2);
    }
}

Circle::Circle(Fraction x1, Fraction y1, Fraction x2,
                Fraction y2, Fraction x3, Fraction y3) noexcept :
         Circle(int(x1), int(y1), int (x2), int(y2), int(x3), int(y3)) {}

Circle::Circle(PointVector p1, PointVector p2, PointVector p3) noexcept :
        Circle(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y) {}


double Circle::get_percent_intersection(const BoolImage &image) const {
    double good = 0;
    if (0 <= center.x && center.x <= image.cols() && 0 <= center.y &&
        center.y <= image.rows() && 3 < radius)
        for (auto t : Settings::check_circles)
            good += image(center + PointVector(radius, 0).rotate(t));
    return good / double(Settings::check_circles.size());
}


Fraction Circle::get_x() const      { return center.x; }
Fraction Circle::get_y() const      { return center.y; }
Fraction Circle::get_radius() const { return radius; }