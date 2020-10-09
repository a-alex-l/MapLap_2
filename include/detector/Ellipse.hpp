#ifndef MAPLAP2_0_ELLIPSE_HPP
#define MAPLAP2_0_ELLIPSE_HPP

#include "PointVector.hpp"
#include "BoolImage.hpp"

class Ellipse {
private:

    double A = 0, B = 0, C = 0, D = 0, E = 0, F = 1;

public:

    explicit Ellipse() = default;
    explicit Ellipse(int x1, int y1, int x2, int y2,
                    double a1, double b1, double a2, double b2) noexcept;
    explicit Ellipse(double A, double B, double C, double D, double E, double F) noexcept;

    [[nodiscard]] bool is_init() const noexcept;

    [[nodiscard]] double get_A() const noexcept;
    [[nodiscard]] double get_B() const noexcept;
    [[nodiscard]] double get_C() const noexcept;
    [[nodiscard]] double get_D() const noexcept;
    [[nodiscard]] double get_E() const noexcept;
    [[nodiscard]] double get_F() const noexcept;

    friend std::ostream& operator<<(std::ostream &out, const Ellipse &ellipse); // for debug
};

#endif //MAPLAP2_0_ELLIPSE_HPP
