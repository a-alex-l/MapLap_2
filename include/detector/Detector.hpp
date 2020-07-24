#ifndef MAPLAP2_0_DETECTOR_HPP
#define MAPLAP2_0_DETECTOR_HPP

#include "opencv2/opencv.hpp"
#include "LineDetector.hpp"
#include "CircleDetector.hpp"
#include "detector/BoolImage.hpp"

class Detector {
private:

    const BoolImage &input_contour;
    LineDetector line_detector;
    CircleDetector circle_detector;

public:

    explicit Detector(const BoolImage &input_contours);

    void detect();

};

#endif //MAPLAP2_0_DETECTOR_HPP
