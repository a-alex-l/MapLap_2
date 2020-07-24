#ifndef MAPLAP2_0_POINT_VECTOR_HPP
#define MAPLAP2_0_POINT_VECTOR_HPP

#include <iostream>
#include "detector/Fraction.hpp"

class PointVector {
private:

    Fraction x = 0, y = 0;

public:

    PointVector(Fraction x, Fraction y) noexcept;

    PointVector operator*(Fraction other) const noexcept;
    PointVector operator/(Fraction other) const noexcept;
    PointVector operator+(PointVector other) const noexcept;
    PointVector operator-(PointVector other) const noexcept;

    PointVector& operator*=(Fraction other);
    PointVector& operator/=(Fraction other);
    PointVector& operator+=(const PointVector &other);
    PointVector& operator-=(const PointVector &other);

    bool operator==(const PointVector &other) const noexcept;
    bool operator!=(const PointVector &other) const noexcept;

    [[nodiscard]] Fraction get_x() const noexcept;
    [[nodiscard]] Fraction get_y() const noexcept;

    friend std::ostream& operator<<(std::ostream &out, const PointVector &v); // for debug
};


#endif //MAPLAP2_0_POINT_VECTOR_HPP
