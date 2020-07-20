#ifndef MAPLAP2_0_CIRCLEDETECTOR_HPP
#define MAPLAP2_0_CIRCLEDETECTOR_HPP

#include "opencv2/opencv.hpp"
#include "detector/Circle.hpp"

class CircleDetector {
private:

    const cv::Mat &input_contour;
    std::vector<std::pair<int, int>> black_points;

public:

    explicit CircleDetector(const cv::Mat &input_contours);

    void detect();

};


#endif //MAPLAP2_0_CIRCLEDETECTOR_HPP
