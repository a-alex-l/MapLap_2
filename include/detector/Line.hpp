#ifndef MAPLAP2_0_LINE_HPP
#define MAPLAP2_0_LINE_HPP

#include "PointVector.hpp"
#include "BoolImage.hpp"

class Line {
private:

    PointVector first, second;
    Fraction line_thickness = 1;

public:

    explicit Line(const PointVector &one, const PointVector &two, Fraction line_thick = 1) noexcept;

    Line& swap();
    Line& rotate_around_first(double radian);

    [[nodiscard]] Fraction length() const;

    [[nodiscard]] double get_percent_intersection(const BoolImage &input_contour) const;
    [[nodiscard]] std::vector<PointVector> get_intersection(const BoolImage &input_contour) const;

    [[nodiscard]] const PointVector& get_first() const noexcept;
    [[nodiscard]] const PointVector& get_second() const noexcept;

    bool operator==(Line line) const;
    bool operator!=(Line line) const;

};


#endif //MAPLAP2_0_LINE_HPP
