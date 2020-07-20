#include "detector/LineDetector.hpp"
#include <iostream>


static cv::Point get_point(double coord, double rows, double cols) {
    if (coord < 1) {
        return cv::Point(coord * cols, 0);
    } else if (coord < 2) {
        return cv::Point( cols, (coord - 1) * rows);
    } else if (coord < 3) {
        return cv::Point((3 - coord) * cols, rows);
    } else {
        return cv::Point(0, (4 - coord) * rows);
    }
}

static std::vector<double> get_coordinates(int x1, int x2,
                                           int y1, int y2,
                                           double rows, double cols) { //return <[0,4), [0,4)>
    std::vector<double> answer;
    answer.reserve(2);
    if (y2 - y1 != 0) {
        double t = double(y2) / double(y2 - y1);
        if (0 <= x1 * t + (1 - t) * x2 && x1 * t + (1 - t) * x2 < cols)
            answer.push_back((x1 * t + (1 - t) * x2) / cols);
    }
    if (x2 - x1 != 0) {
        double t = double(x2 - cols) / double(x2 - x1);
        if (0 <= y1 * t + (1 - t) * y2 && y1 * t + (1 - t) * y2 < rows)
            answer.push_back((y1 * t + (1 - t) * y2) / rows + 1);
    }
    if (y2 - y1 != 0) {
        double t = double(y2 - rows) / double(y2 - y1);
        if (0 <= x1 * t + (1 - t) * x2 && x1 * t + (1 - t) * x2 < cols)
            answer.push_back(-(x1 * t + (1 - t) * x2) / cols + 3);
    }
    if (x2 - x1 != 0) {
        double t = double(x2) / double(x2 - x1);
        if (0 <= y1 * t + (1 - t) * y2 && y1 * t + (1 - t) * y2 < rows)
            answer.push_back(-(y1 * t + (1 - t) * y2) / rows + 4);
    }
    return answer;
}

LineDetector::LineDetector(const cv::Mat &input_contours)
        : input_contour(input_contours),
            circle_radius(input_contours.rows + input_contours.cols) {}

void LineDetector::find_black_points() {
    for (int i = 0; i < input_contour.rows; i++)
        for (int j = 0; j < input_contour.cols; j++)
            if (input_contour.at<uchar>(i, j) == 0)
                black_points.emplace_back(i, j);
}

void LineDetector::find_lines_parameters() { // a * x + b * y = 1
    for (int i = 0; i < black_points.size(); i++) {
        for (int j = i + 1; j < black_points.size(); j++) {
            if (input_contour.at<uchar>(
                    (black_points[i].first  + black_points[j].first)  / 2,
                    (black_points[i].second + black_points[j].second) / 2 ) != 255) {
                std::vector<double> coords =
                        get_coordinates(black_points[i].second, black_points[j].second,
                                        black_points[i].first, black_points[j].first,
                                        input_contour.rows, input_contour.cols);
                lines_parameters[coords[0]][coords[1]]++;
            }
        }
    }
}

void LineDetector::claster_lines_parameters() {
    std::map<double, std::map<double, bool>> used_horizontal;
    std::map<double, std::map<double, bool>> used_vertical;
    std::vector<std::pair<int, std::pair<double, double>>> sorted;
}

void LineDetector::find_lines() {

}

void LineDetector::detect() {
    find_black_points();
    find_lines_parameters();
    show();
}


void LineDetector::show() {
    cv::Mat img_result(cv::Size(input_contour.cols, input_contour.rows), CV_8U, cv::Scalar(255, 255, 255));
    for (auto &i : lines_parameters) {
        for (auto &j : i.second) {
            if (j.second > 50) {
                cv::line(img_result,
                    get_point(i.first, input_contour.rows, input_contour.cols),
                    get_point(j.first, input_contour.rows, input_contour.cols),
                   cv::Scalar(0));
            }
        }
    }
    cv::imshow("img_result", img_result);
}