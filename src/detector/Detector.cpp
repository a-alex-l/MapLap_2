#include "detector/Detector.hpp"
#include "detector/Timer.hpp"

Detector::Detector(const BoolImage &input_contours) noexcept :
           input_contour(input_contours), line_detector(input_contours),
           ellipse_detector(input_contours) {}

void Detector::detect() {
    detector_timer.start();
    line_detector.detect();
    ellipse_detector.detect();
    print_timing();
}

void Detector::print_timing() noexcept {
    detector_timer.stop();
    detector_timer.print();
}

const std::vector<Line>& Detector::get_lines() const noexcept {
    return line_detector.get_lines();
}

const std::vector<Ellipse>& Detector::get_ellipses() const noexcept {
    return ellipse_detector.get_ellipses();
}
