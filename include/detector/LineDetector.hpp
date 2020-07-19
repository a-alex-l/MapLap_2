#ifndef MAPLAP2_0_LINEDETECTOR_HPP
#define MAPLAP2_0_LINEDETECTOR_HPP


#include <map>
#include <vector>

#include "opencv2/opencv.hpp"
#include "Line.hpp"

class LineDetector {
private:

    const cv::Mat &input_contour;
    std::vector<std::pair<int, int>> black_points;
    std::map<double, std::map<double, int>> lines_parameters_horizontal;
    std::map<double, std::map<double, int>> lines_parameters_vertical;
    std::vector<Line> lines;

    void find_black_points();
    void find_lines_parameters();
    void hough_transform_find_parameters();


public:

    LineDetector(const cv::Mat &input_contours);

};

#endif //MAPLAP2_0_LINEDETECTOR_HPP
