#ifndef MAPLAP2_0_POINT_VECTOR_HPP
#define MAPLAP2_0_POINT_VECTOR_HPP

#include <iostream>
#include "detector/Fraction.hpp"

struct PointVector {

    Fraction x = 0, y = 0;

    PointVector(Fraction y, Fraction x) noexcept;

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

    PointVector rotate(double radian);
    Fraction length();

    friend std::ostream& operator<<(std::ostream &out, const PointVector &v); // for debug
};


#endif //MAPLAP2_0_POINT_VECTOR_HPP
