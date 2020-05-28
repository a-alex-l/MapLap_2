#include "PointVector.hpp"

PointVector::PointVector(float x, float y) noexcept : x(x), y(y) {}

float PointVector::get_x() const noexcept { return x; }
float PointVector::get_y() const noexcept { return y; }

PointVector& PointVector::operator+=(const PointVector &other) {
    this->x += other.x;
    this->y += other.y;
    return *this;
}

PointVector& PointVector::operator-=(const PointVector &other) {
    this->x -= other.x;
    this->y -= other.y;
    return *this;
}

PointVector& PointVector::operator*=(float other) {
    this->x *= other;
    this->y *= other;
    return *this;
}

PointVector& PointVector::operator/=(float other) {
    this->x /= other;
    this->y /= other;
    return *this;
}

PointVector& PointVector::operator+(PointVector other) {
    return other += *this;
}

PointVector& PointVector::operator-(PointVector other) {
    return other -= *this;
}

PointVector& PointVector::operator*(float other) {
    return PointVector(*this) *= other;
}

PointVector& PointVector::operator/(float other) {
    return PointVector(*this) /= other;
}

std::ostream& operator<<(std::ostream &out, const PointVector &v) {
    return out << "(" << std::setprecision(5) << v.x << ", " << std::setprecision(5) << v.y << ")";
}