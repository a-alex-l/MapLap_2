#include "shapes/PointVector.hpp"
#include <cmath>

PointVector::PointVector(double y, double x) noexcept : x(x), y(y) {}

PointVector& PointVector::operator+=(const PointVector &other) {
    this->x += other.x;
    this->y += other.y;
    return *this;
}

PointVector& PointVector::operator*=(double other) {
    this->x *= other;
    this->y *= other;
    return *this;
}

PointVector& PointVector::operator-=(const PointVector &other) {
    return *this += other * -1;
}

PointVector& PointVector::operator/=(double other) {
    return *this *= 1 / other;
}

PointVector PointVector::operator+(PointVector other) const noexcept {
    return other += *this;
}

PointVector PointVector::operator-(PointVector other) const noexcept {
    return *this + other * -1;
}

PointVector PointVector::operator*(double other) const noexcept {
    return PointVector(*this) *= other;
}

PointVector PointVector::operator/(double other) const noexcept {
    return PointVector(*this) /= other;
}

std::ostream& operator<<(std::ostream &out, const PointVector &v) {
    return out << "(" << v.y << "mm, " << v.x << "mm)";
}

bool PointVector::operator==(const PointVector &other) const noexcept {
    return x == other.x && y == other.y;
}

bool PointVector::operator!=(const PointVector &other) const noexcept {
    return x != other.x || y != other.y;
}

PointVector PointVector::rotate(double radian) {
    return *this = PointVector(-sin(radian) * this->x + cos(radian) * this->y,
                               cos(radian) * this->x + sin(radian) * this->y);
}

double PointVector::length() {
    return sqrt(x * x + y * y);
}