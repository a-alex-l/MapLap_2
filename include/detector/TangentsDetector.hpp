#ifndef MAPLAP2_0_TANGENTSDETECTOR_HPP
#define MAPLAP2_0_TANGENTSDETECTOR_HPP

#include <map>
#include <vector>

#include "shapes/PointVector.hpp"
#include "detector/BoolImage.hpp"
#include "detector/Settings.hpp"

class TangentsDetector {
private:

    int neighbours_count = 7;
    const BoolImage &input_contour;
    std::map<std::pair<int, int>, PointVector> tangents;

    [[nodiscard]] std::vector<std::pair<double, double>> get_neighbours(int y, int x) const;
    [[nodiscard]] double get_sum_distance(double angle,
            const std::vector<std::pair<double, double>> &neighbours) const;
    [[nodiscard]] double ternary_search(int y, int x) const;

public:

    explicit TangentsDetector(const BoolImage &input_contours, int neighbours_count = 10);

    PointVector get(int y, int x);

};

#endif //MAPLAP2_0_TANGENTSDETECTOR_HPP
