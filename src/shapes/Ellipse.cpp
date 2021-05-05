#include "shapes/Ellipse.hpp"
#include "detector/Settings.hpp"

static long double square(long double x) { return x * x; }

Ellipse::Ellipse(int x1, int y1, double a1, double b1,
                 int x2, int y2, double a2, double b2) noexcept {
    long double a1b2a2b1 = a1*b2 + a2*b1;
    long double x1x2 = x1 - x2;
    long double y1y2 = y1 - y2;
    long double WH_helper = a1b2a2b1*square(a1*x1x2 + b1*y1y2)*square(a2*x1x2 + b2*y1y2);
    Y = ((a1*b2*y1 + a2*b1*y2)*x1x2 + b1*b2*(y1*y1 - y2*y2)) / (a1b2a2b1*x1x2 + 2*b1*b2*y1y2);
    X = ((a1*b2*x2 + a2*b1*x1)*y1y2 + a1*a2*(x1*x1 - x2*x2)) / (a1b2a2b1*y1y2 + 2*a1*a2*x1x2);
    W = sqrt(x1x2*WH_helper / (square(2*a1*a2*x1x2 + a1b2a2b1*y1y2)*(a1b2a2b1*x1x2 + 2*b1*b2*y1y2)));
    H = sqrt(y1y2*WH_helper / (square(2*b1*b2*y1y2 + a1b2a2b1*x1x2)*(a1b2a2b1*y1y2 + 2*a1*a2*x1x2)));
    if (!(std::isfinite(Y) && std::isfinite(X) &&
          std::isfinite(W) && std::isfinite(H)) || W < 1 || H < 1)
        Y = X = W = H = 0;
}

Ellipse::Ellipse(long double X, long double Y, long double H, long double W) noexcept :
        X(X), Y(Y), H(H), W(W) {}


bool Ellipse::is_init() const noexcept {
    return !(X == Y && Y == H && H == W && W == 0);
}


long double Ellipse::get_X() const noexcept { return X; }
long double Ellipse::get_Y() const noexcept { return Y; }
long double Ellipse::get_H() const noexcept { return H; }
long double Ellipse::get_W() const noexcept { return W; }

bool Ellipse::operator<(const Ellipse &ellipse) const noexcept {
    return H*W < ellipse.H * ellipse.W;
}

std::ostream& operator<<(std::ostream &out, const Ellipse &ellipse) { // for debug
    return out << "\\draw[black, line width=1] (" << ellipse.X << "mm, " << ellipse.Y << "mm) "
               << "ellipse (" << ellipse.W << "mm and " << ellipse.H << "mm);";
}