#ifndef MAPLAP2_0_LINEDETECTOR_HPP
#define MAPLAP2_0_LINEDETECTOR_HPP

#include <map>
#include <vector>

#include "detector/Line.hpp"
#include "detector/BoolImage.hpp"
#include "detector/Settings.hpp"
#include "detector/TangentsDetector.hpp"

class LineDetector {
private:

    int side;
    const BoolImage &input_contour;
    std::vector<std::pair<int, int>> black_points;
    std::map<double, std::map<double, int>> lines_parameters;
    std::vector<Line> lines;
    TangentsDetector tangent_detector;

    void find_black_points();
    void find_lines_parameters();
    void claster_lines_parameters();
    void find_lines();

    void show();

public:

    explicit LineDetector(const BoolImage &input_contours);

    void detect();

};

#endif //MAPLAP2_0_LINEDETECTOR_HPP
