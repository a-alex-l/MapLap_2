#ifndef MAPLAP2_0_ELLIPSE_HPP
#define MAPLAP2_0_ELLIPSE_HPP

#include "PointVector.hpp"
#include "BoolImage.hpp"

class Ellipse {
private:

    long double /*A = 1*/ B = 0, C = 0, D = 0, E = 0, F = 1;
    void normalization(long double A) noexcept; // make A = 1

public:

    explicit Ellipse() = default;
    explicit Ellipse(int x1, int y1, int x2, int y2, int x3, int y3,
            double a1, double a2, double a3, double b1, double b2, double b3) noexcept;
    explicit Ellipse(long double B, long double C, long double D,
                     long double E, long double F) noexcept;

    [[nodiscard]] bool is_init() const noexcept;

    [[nodiscard]] long double get_B() const noexcept;
    [[nodiscard]] long double get_C() const noexcept;
    [[nodiscard]] long double get_D() const noexcept;
    [[nodiscard]] long double get_E() const noexcept;
    [[nodiscard]] long double get_F() const noexcept;

    bool operator<(const Ellipse &ellipse) const noexcept;

    friend std::ostream& operator<<(std::ostream &out, const Ellipse &ellipse); // for debug
};

#endif //MAPLAP2_0_ELLIPSE_HPP
