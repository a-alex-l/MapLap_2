#include "detector/LineDetector.hpp"
#include <iostream>

void LineDetector::find_black_points() {
    for (int i = 0; i < input_contour.rows; i++)
        for (int j = 0; j < input_contour.cols; j++)
            if (input_contour.at<uchar>(i, j) == 0)
                black_points.emplace_back(i, j);
}

void LineDetector::find_lines_parameters() {
    for (int i = 0; i < black_points.size(); i++) {
        for (int j = i + 1; j < black_points.size(); j++) {
            if     (abs(black_points[i].first  - black_points[j].first) * 2 >
                    abs(black_points[i].second - black_points[j].second)) {
                double a = double(black_points[i].second - black_points[j].second) /
                           double(black_points[i].first  - black_points[j].first);
                double b = a * double(black_points[i].first  + black_points[j].first) / 2.0 +
                               double(black_points[i].second + black_points[j].second) / 2.0;
                lines_parameters_horizontal[a][b]++;
                std::cout << "H " << a << " " << b << "\n";
            }
            if     (abs(black_points[i].second - black_points[j].second) * 2 >
                    abs(black_points[i].first  - black_points[j].first)) {
                double a = double(black_points[i].first  - black_points[j].first) /
                           double(black_points[i].second - black_points[j].second);
                double b = a * double(black_points[i].second + black_points[j].second) / 2.0 +
                               double(black_points[i].first  + black_points[j].first) / 2.0;
                lines_parameters_vertical[a][b]++;
                std::cout << "V " << a << " " << b << "\n";
            }
        }
    }
}

void LineDetector::hough_transform_find_parameters() {
    find_black_points();
    find_lines_parameters();

}