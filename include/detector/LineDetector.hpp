#ifndef MAPLAP2_0_LINEDETECTOR_HPP
#define MAPLAP2_0_LINEDETECTOR_HPP

#include <map>
#include <vector>

#include "shapes/Line.hpp"
#include "BoolImage.hpp"
#include "Settings.hpp"
#include "TangentsDetector.hpp"
#include "Timer.hpp"

class LineDetector {
private:

    int side;
    const BoolImage &input_contour;
    std::vector<std::pair<int, int>> black_points;
    std::vector<Line> pre_lines, lines;
    TangentsDetector tangent_detector;
    Timer line_detector_timer = Timer("LineDetector work time:    %f.\n");

    void find_black_points();
    void find_pre_lines();
    void cluster_pre_lines();

    void print_timing() noexcept;

public:

    explicit LineDetector(const BoolImage &input_contours);

    void detect();

    [[nodiscard]] const std::vector<Line>& get_lines() const noexcept;

};

#endif //MAPLAP2_0_LINEDETECTOR_HPP
