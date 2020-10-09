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
    EllipseDetector circle_detector;
    Timer detector_timer = Timer("Detector work time: %f .\n");

public:

    explicit Detector(const BoolImage &input_contours) noexcept;
    ~Detector() noexcept;

    void detect();

};

#endif //MAPLAP2_0_DETECTOR_HPP
