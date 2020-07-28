#include "detector/PointVector.hpp"

PointVector::PointVector(Fraction y, Fraction x) noexcept : x(x), y(y) {}

PointVector& PointVector::operator+=(const PointVector &other) {
    this->x += other.x;
    this->y += other.y;
    return *this;
}

PointVector& PointVector::operator*=(Fraction other) {
    this->x *= other;
    this->y *= other;
    return *this;
}

PointVector& PointVector::operator-=(const PointVector &other) {
    return *this += other * -1;
}

PointVector& PointVector::operator/=(Fraction other) {
    return *this *= 1 / other;
}

PointVector PointVector::operator+(PointVector other) const noexcept {
    return other += *this;
}

PointVector PointVector::operator-(PointVector other) const noexcept {
    return *this + other * -1;
}

PointVector PointVector::operator*(Fraction other) const noexcept {
    return PointVector(*this) *= other;
}

PointVector PointVector::operator/(Fraction other) const noexcept {
    return PointVector(*this) /= other;
}

std::ostream& operator<<(std::ostream &out, const PointVector &v) { // for debug
    return out << "(" << v.y << ", " << v.x << ")";
}

bool PointVector::operator==(const PointVector &other) const noexcept {
    return x == other.x && y == other.y;
}

bool PointVector::operator!=(const PointVector &other) const noexcept {
    return x != other.x || y != other.y;
}

PointVector PointVector::rotate(double radian) {
    return *this = PointVector(-Fraction(sin(radian)) * this->x + Fraction(cos(radian)) * this->y,
                               Fraction(cos(radian)) * this->x + Fraction(sin(radian)) * this->y);
}

Fraction PointVector::length() {
    return sqrt(x * x + y * y);
}