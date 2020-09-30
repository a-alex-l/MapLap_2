#include "detector/Line.hpp"

Line::Line(const PointVector &one, const PointVector &two, Fraction line_thick) noexcept:
            first(one), second(two), line_thickness(line_thick) {}

Line& Line::swap() {
    std::swap(first, second);
    return *this;
}

Line& Line::rotate_around_first(double radian) {
    second = first + (second - first).rotate(radian);
    return *this;
}

Fraction Line::length() const {
    return (first - second).length();
}

double Line::get_percent_intersection(const BoolImage &input_contour) const {
    double good = 0;
    for (double i = 0; i <= 1; i += double(1 / this->length()))
        good += input_contour(first * i + second * (1 - i));
    return good / double(this->length());
}


std::vector<PointVector> Line::get_intersection(const BoolImage &input_contour) const {
    std::vector<PointVector> ans;
    for (double i = 0; i <= 1; i += double(1 / this->length()))
        if (input_contour(first * i + second * (1 - i)))
            ans.push_back(first * i + second * (1 - i));
    return ans;
}


const PointVector& Line::get_first() const noexcept  { return first; }
const PointVector& Line::get_second() const noexcept { return second; }


bool Line::operator==(Line line) const {
    return first == line.first && second == line.second;
}

bool Line::operator!=(Line line) const {
    return !(*this == line);
}
