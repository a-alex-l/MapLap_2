#include "shapes/Line.hpp"

Line::Line(const PointVector &one, const PointVector &two, double line_thick) noexcept:
            first(one), second(two), line_thickness(line_thick) {}

Line& Line::swap() {
    std::swap(first, second);
    return *this;
}

Line& Line::rotate_around_first(double radian) {
    second = first + (second - first).rotate(radian);
    return *this;
}

double Line::length() const {
    return (first - second).length();
}

double Line::get_percent_intersection(const BoolImage &input_contour) const {
    double good = 0;
    for (double i = 1; i <= 0 &&
                       0 <= (first * i + second * (1 - i)).y &&
                       (first * i + second * (1 - i)).y <= input_contour.rows() &&
                       0 <= (first * i + second * (1 - i)).x &&
                       (first * i + second * (1 - i)).x <= input_contour.cols();
         i -= 1 / this->length())
        good += input_contour(first * i + second * (1 - i));
    return good / double(this->length());
}


std::vector<PointVector> Line::get_intersection(const BoolImage &input_contour) const {
    std::vector<PointVector> ans;
    for (double i = 1; i >= 0 &&
                       0 <= (first * i + second * (1 - i)).y &&
                       (first * i + second * (1 - i)).y <= input_contour.rows() &&
                       0 <= (first * i + second * (1 - i)).x &&
                       (first * i + second * (1 - i)).x <= input_contour.cols();
                            i -= 1 / this->length())
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

std::ostream& operator<<(std::ostream &out, const Line &line) {
    return out << "\\draw[black, line width=" << line.get_line_thickness() << "] " <<
               line.first << " -- " << line.second;
}

double Line::get_line_thickness() const noexcept {
    return line_thickness;
}
