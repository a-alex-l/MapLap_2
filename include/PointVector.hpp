#ifndef MAPLAP2_0_POINT_VECTOR_HPP
#define MAPLAP2_0_POINT_VECTOR_HPP

#include <iostream> //for debug
#include <iomanip> // for debug

class PointVector {
private:

    float x = 0, y = 0;

public:

    PointVector(float x, float y) noexcept;

    PointVector& operator+(PointVector other);
    PointVector& operator-(PointVector other);
    PointVector& operator*(float other);
    PointVector& operator/(float other);

    PointVector& operator+=(const PointVector &other);
    PointVector& operator-=(const PointVector &other);
    PointVector& operator*=(float other);
    PointVector& operator/=(float other);

    [[nodiscard]] float get_x() const noexcept;
    [[nodiscard]] float get_y() const noexcept;

    friend std::ostream& operator<<(std::ostream &out, const PointVector &v);
};


#endif //MAPLAP2_0_POINT_VECTOR_HPP
