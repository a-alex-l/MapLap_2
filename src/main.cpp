#include <iostream>

#include "PointVector.hpp"
#include "opencv2/opencv.hpp"

int main() {
    PointVector a(1, 2), b(25, 3);
    PointVector c = a;
    std::cout << a << " + " << b << " = " << a + b << "\n";
    std::cout << a << " - " << b << " = " << a - b << "\n";
    std::cout << a << " * " << 4.8 << " = " << a * 4.8f << "\n";
    std::cout << a << " * " << 4.8 << " + " << b << " = " << a * 4.8f + b << "\n";

    return 0;
}
