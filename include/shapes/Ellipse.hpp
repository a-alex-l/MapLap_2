#ifndef MAPLAP2_0_ELLIPSE_HPP
#define MAPLAP2_0_ELLIPSE_HPP

#include "PointVector.hpp"
#include "detector/BoolImage.hpp"

class Ellipse {
private:

    long double X = 0, Y = 0, H = 0, W = 0;

public:

    explicit Ellipse() = default;
    explicit Ellipse(int x1, int y1, double a1, double b1,
                     int x2, int y2, double a2, double b2) noexcept;
    explicit Ellipse(long double X, long double Y, long double H, long double W) noexcept;

    [[nodiscard]] bool is_init() const noexcept;

    [[nodiscard]] long double get_X() const noexcept;
    [[nodiscard]] long double get_Y() const noexcept;
    [[nodiscard]] long double get_H() const noexcept;
    [[nodiscard]] long double get_W() const noexcept;

    bool operator<(const Ellipse &ellipse) const noexcept;

    friend std::ostream& operator<<(std::ostream &out, const Ellipse &ellipse);
};

#endif //MAPLAP2_0_ELLIPSE_HPP
