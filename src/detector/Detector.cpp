#include "detector/Detector.hpp"

#include <chrono>

Detector::Detector(const BoolImage &input_contours) :
           input_contour(input_contours),
            line_detector(input_contours),
            circle_detector(input_contours) {}

void Detector::detect() {
    auto start = std::chrono::steady_clock::now();
    line_detector.detect();
    auto transfer = std::chrono::steady_clock::now();
    std::chrono::duration<double> line_seconds = transfer - start;
    printf("Line done in: %f\n", line_seconds.count());
    fflush(stdout);
    circle_detector.detect();
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> circle_seconds = end - transfer;
    printf("Circle done in: %f\n", circle_seconds.count());
    printf("Done in: %f\n", line_seconds.count() + circle_seconds.count());
}