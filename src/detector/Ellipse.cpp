#include "detector/Ellipse.hpp"
#include "detector/Settings.hpp"

Ellipse::Ellipse(int x1, int y1, int x2, int y2,
                 double a1, double b1, double a2, double b2) noexcept {
    if ((3*x1*y2 - 6*x1*y1 + 3*x2*y1) == 0 || x1 - x2 == 0 || y1 - y2 == 0)
        return;
    B = (a2*(x2 + 3*x1) + b2*(y2 + 3*y1) - 2*(a1*(x2 + x1) + b1*(y2 + y1))) / (3*(x1*(y2 - 2*y1) + x2*y1));
    A = (a1 - a2 - B*(y1 - y2)) / (2*x1 - 2*x2);
    D = x1 * (a1 - a2 - B*(y1 - y2)) / (x1 - x2) + B*y1 - a1;
    C = (b1 - b2 - B*(x1 - x2)) / (2*y1 - 2*y2);
    E = y1 * (b1 - b2 - B*(x1 - x2)) / (y1 - y2) + B*x1 - b1;
    F = A*x1*x1 + B*x1*y1 + C*y1*y1 + D*x1 + E*y1;
}

Ellipse::Ellipse(double A, double B, double C, double D, double E, double F) noexcept :
        A(A), B(B), C(C), D(D), E(E), F(F) {}


bool Ellipse::is_init() const noexcept {
    return F != 1 || A != 0 || B != 0 || C != 0 || D != 0 || E != 0;
}

double Ellipse::get_A() const noexcept { return A; }
double Ellipse::get_B() const noexcept { return B; }
double Ellipse::get_C() const noexcept { return C; }
double Ellipse::get_D() const noexcept { return D; }
double Ellipse::get_E() const noexcept { return E; }
double Ellipse::get_F() const noexcept { return F; }

std::ostream& operator<<(std::ostream &out, const Ellipse &ellipse) { // for debug
    return out << ellipse.A << "*x*x + " << ellipse.B << "*x*y + " << ellipse.C << "*y*y + "
                << ellipse.D << "*x + " << ellipse.E << "*y = " << ellipse.F;
}