#ifndef MAPLAP2_0_POINT_VECTOR_HPP
#define MAPLAP2_0_POINT_VECTOR_HPP

#include <iostream>

struct PointVector {

    double y = 0, x = 0;

    PointVector() = default;
    PointVector(double y, double x) noexcept;

    PointVector operator*(double other) const  noexcept;
    PointVector operator/(double other) const  noexcept;
    PointVector operator+(PointVector other) const  noexcept;
    PointVector operator-(PointVector other) const  noexcept;

    PointVector& operator*=(double other);
    PointVector& operator/=(double other);
    PointVector& operator+=(const PointVector &other);
    PointVector& operator-=(const PointVector &other);

    bool operator==(const PointVector &other) const  noexcept;
    bool operator!=(const PointVector &other) const  noexcept;

    PointVector rotate(double radian);
    double length();

    friend std::ostream& operator<<(std::ostream &out, const PointVector &v); // for debug
};


#endif //MAPLAP2_0_POINT_VECTOR_HPP
