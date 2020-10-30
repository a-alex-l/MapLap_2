#include "detector/Ellipse.hpp"
#include "detector/Settings.hpp"

Ellipse::Ellipse(int x1, int y1, int x2, int y2, int x3, int y3,
        double a1, double a2, double a3, double b1, double b2, double b3) noexcept {
    long double A;
    if (x1 - x2 == 0 || x3 - x2 == 0 || x1 - x3 == 0 ||
                        y1 - y2 == 0 || y3 - y2 == 0 || y1 - y3 == 0)
        return;
    if (x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2) != 0)
            B = (a1*(x3 - x2) + a2*(x1 - x3) + a3*(x2 - x1)) / (x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2));
    else    B = (b1*(y3 - y2) + b2*(y1 - y3) + b3*(y2 - y1)) / (y1*(x2 - x3) + y2*(x3 - x1) + y3*(x1 - x2));
    A = (a1 - a2 - B*(y1 - y2)) / (2*(x1 - x2));
    D = a1 - 2*A*x1 - B*y1;
    C = (b1 - b2 - B*(x1 - x2)) / (2*(y1 - y2));
    E = b1 - 2*C*y1 - B*x1;
    if (A * C < 2 * B * B) {
        A = B = C = D = E = 0;
        return;
    }
    F = A*x1*x1 + B*x1*y1 + C*y1*y1 + D*x1 + E*y1;
    normalization(A);
}

Ellipse::Ellipse(long double B, long double C, long double D, long double E, long double F) noexcept :
        B(B), C(C), D(D), E(E), F(F) {}


bool Ellipse::is_init() const noexcept {
    return F != 1 || B != 0 || C != 0 || D != 0 || E != 0;
}

void Ellipse::normalization(long double A) noexcept {
    B /= A, C /= A, D /= A, E /= A, F /= A;
}

long double Ellipse::get_B() const noexcept { return B; }
long double Ellipse::get_C() const noexcept { return C; }
long double Ellipse::get_D() const noexcept { return D; }
long double Ellipse::get_E() const noexcept { return E; }
long double Ellipse::get_F() const noexcept { return F; }

bool Ellipse::operator<(const Ellipse &ellipse) const noexcept {
    return F < ellipse.F;
}

std::ostream& operator<<(std::ostream &out, const Ellipse &ellipse) { // for debug
    out.precision(15);
    return out << "x*x + " << ellipse.B << "*x*y + " << ellipse.C << "*y*y + "
                << ellipse.D << "*x + " << ellipse.E << "*y = " << ellipse.F;
}