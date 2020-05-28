#ifndef MAPLAP2_0_LINE_HPP
#define MAPLAP2_0_LINE_HPP

#include "PointVector.hpp"

class Line {
private:

    PointVector first, second;
    double line_thickness = 1;

public:

    explicit Line(const PointVector &one, const PointVector &two, double line_thick = 1) noexcept;

    void swap();

    [[nodiscard]] const PointVector& get_first() const noexcept;
    [[nodiscard]] const PointVector& get_second() const noexcept;

};


#endif //MAPLAP2_0_LINE_HPP
