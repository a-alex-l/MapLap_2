#ifndef MAPLAP2_0_LINE_HPP
#define MAPLAP2_0_LINE_HPP

#include "PointVector.hpp"

class Line {
private:

    PointVector first, second;

public:

    explicit Line(const PointVector &one, const PointVector &two) noexcept;

    void swap();

    [[nodiscard]] const PointVector& get_first() const noexcept;
    [[nodiscard]] const PointVector& get_second() const noexcept;

};


#endif //MAPLAP2_0_LINE_HPP
