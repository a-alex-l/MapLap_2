#ifndef MAPLAP2_0_LINE_HPP
#define MAPLAP2_0_LINE_HPP

#include "PointVector.hpp"
#include "BoolImage.hpp"

class Line {
private:

    PointVector first = {0, 0}, second = {0, 0};
    double line_thickness = 1;

public:

    explicit Line() = default;
    explicit Line(const PointVector &one, const PointVector &two, double line_thick = 1) noexcept;

    Line& swap();
    Line& rotate_around_first(double radian);

    [[nodiscard]] double length() const;

    [[nodiscard]] double get_percent_intersection(const BoolImage &input_contour) const;
    [[nodiscard]] std::vector<PointVector> get_intersection(const BoolImage &input_contour) const;

    [[nodiscard]] const PointVector& get_first() const noexcept;
    [[nodiscard]] const PointVector& get_second() const noexcept;

    bool operator==(Line line) const;
    bool operator!=(Line line) const;

};


#endif //MAPLAP2_0_LINE_HPP
