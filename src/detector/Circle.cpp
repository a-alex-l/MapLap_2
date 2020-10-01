#include "detector/Circle.hpp"
#include "detector/Settings.hpp"

Circle::Circle(int x1, int y1, int x2, int y2, int x3, int y3) noexcept {
    double divider = 2 * (y2  - y1) * (x3 - x2) - 2 * (x2 - x1) * (y3  - y2);
    if (divider != 0) {
        double e = y2 * y2 - y1 * y1 + x2 * x2 - x1 * x1;
        double f = y3 * y3 - y1 * y1 + x3 * x3 - x1 * x1;
        center = PointVector(((x3 - x1) * e - (x2 - x1) * f) / divider,
                             ((y2 - y1) * f - (y3 - y1) * e) / divider);
        double radius2 = (center.x - x1) * (center.x - x1) + (center.y - y1) * (center.y - y1);
        radius = sqrt(radius2);
    }
}

Circle::Circle(double x1, double y1, double x2,
                double y2, double x3, double y3) noexcept :
         Circle(int(x1), int(y1), int (x2), int(y2), int(x3), int(y3)) {}       

Circle::Circle(PointVector p1, PointVector p2, PointVector p3) noexcept :
        Circle(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y) {}


double Circle::get_percent_intersection(const BoolImage &input_contour) const {
    double good = 0;
    if (0 <= center.x && center.x <= input_contour.cols() && 0 <= center.y &&
        center.y <= input_contour.rows() && 3 < radius)
        for (auto t : Settings::check_circles)
            good += input_contour(center + PointVector(radius, 0).rotate(t * M_PI));
    return good / double(Settings::check_circles.size());
}


double Circle::get_x() const      { return center.x; }
double Circle::get_y() const      { return center.y; }
double Circle::get_radius() const { return radius; }