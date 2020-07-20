#include "detector/Detector.hpp"

Detector::Detector(const cv::Mat &input_contours) :
        input_contour(input_contours),
        line_detector(input_contours),
        circle_detector(input_contours) {}

void Detector::detect() {
    line_detector.detect();
    circle_detector.detect();
}