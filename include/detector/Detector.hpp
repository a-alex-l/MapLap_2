#ifndef MAPLAP2_0_DETECTOR_HPP
#define MAPLAP2_0_DETECTOR_HPP

#include "opencv2/opencv.hpp"
#include "LineDetector.hpp"
#include "EllipseDetector.hpp"
#include "BoolImage.hpp"
#include "Timer.hpp"

class Detector {
private:

    const BoolImage &input_contour;
    LineDetector line_detector;
    EllipseDetector ellipse_detector;
    Timer detector_timer = Timer("Detector work time:        %f.\n");

    void print_timing() noexcept;

public:

    explicit Detector(const BoolImage &input_contours) noexcept;

    void detect();

    [[nodiscard]] const std::vector<Line>& get_lines() const noexcept;
    [[nodiscard]] const std::vector<Ellipse>& get_ellipses() const noexcept;

};

#endif //MAPLAP2_0_DETECTOR_HPP
