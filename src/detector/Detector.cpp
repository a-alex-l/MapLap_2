#include "detector/Detector.hpp"
#include "detector/Timer.hpp"

Detector::Detector(const BoolImage &input_contours) noexcept :
           input_contour(input_contours), line_detector(input_contours),
           circle_detector(input_contours) {}

void Detector::detect() {
    detector_timer.start();
    line_detector.detect();
    circle_detector.detect();
    print_timing();
}

void Detector::print_timing() noexcept {
    detector_timer.stop();
    detector_timer.print();
}