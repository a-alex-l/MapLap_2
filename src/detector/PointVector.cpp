#include "detector/PointVector.hpp"

PointVector::PointVector(double x, double y) noexcept : x(x), y(y) {}

double PointVector::get_x() const noexcept { return x; }
double PointVector::get_y() const noexcept { return y; }

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

PointVector& PointVector::operator/=(double other)  {
    return *this *= 1 / other;
}

PointVector PointVector::operator+(PointVector other) const noexcept  {
    return other += *this;
}

PointVector PointVector::operator-(PointVector other) const noexcept  {
    return *this + other * -1;
}

PointVector PointVector::operator*(double other) const noexcept  {
    return PointVector(*this) *= other;
}

PointVector PointVector::operator/(double other) const noexcept  {
    return PointVector(*this) /= other;
}

std::ostream& operator<<(std::ostream &out, const PointVector &v) { // for debug
    return out << "(" << std::setprecision(5) << v.x << ", "
                      << std::setprecision(5) << v.y << ")";
}