#ifndef MAPLAP2_0_LINEDETECTOR_HPP
#define MAPLAP2_0_LINEDETECTOR_HPP


#include <map>
#include <vector>

#include "opencv2/opencv.hpp"
#include "Line.hpp"

class LineDetector {
private:

    int circle_radius;
    const cv::Mat &input_contour;
    std::vector<std::pair<int, int>> black_points;
    std::map<double, std::map<double, int>> lines_parameters;
    std::vector<Line> lines;

    void find_black_points();
    void find_lines_parameters();
    void claster_lines_parameters();
    void find_lines();

    void show();

public:

    explicit LineDetector(const cv::Mat &input_contours);

    void detect();

};

#endif //MAPLAP2_0_LINEDETECTOR_HPP
