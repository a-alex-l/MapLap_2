#ifndef MAPLAP2_0_POINT_VECTOR_HPP
#define MAPLAP2_0_POINT_VECTOR_HPP

#include <iostream> // for debug
#include <iomanip> // for debug

class PointVector {
private:

    double x = 0, y = 0;

public:

    PointVector(double x, double y) noexcept;

    PointVector operator*(double other) const noexcept;
    PointVector operator/(double other) const noexcept;
    PointVector operator+(PointVector other) const noexcept;
    PointVector operator-(PointVector other) const noexcept;

    PointVector& operator*=(double other);
    PointVector& operator/=(double other);
    PointVector& operator+=(const PointVector &other);
    PointVector& operator-=(const PointVector &other);

    [[nodiscard]] double get_x() const noexcept;
    [[nodiscard]] double get_y() const noexcept;

    friend std::ostream& operator<<(std::ostream &out, const PointVector &v); // for debug
};


#endif //MAPLAP2_0_POINT_VECTOR_HPP
