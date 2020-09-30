#include "detector/LineDetector.hpp"
#include <iostream>


static cv::Point get_point(Fraction coord, int side) {
    if (coord < 1)      return cv::Point(int(coord * side), int(0));
    else if (coord < 2) return cv::Point(int(side), int((coord - 1) * side));
    else if (coord < 3) return cv::Point(int((3 - coord) * side), int(side));
    else                return cv::Point(int(0), int((4 - coord) * side));
}

static std::vector<Fraction> get_coordinates(int x1, int x2,
                                           int y1, int y2,
                                           int side) { //return <[0,4), [0,4)>
    std::vector<Fraction> answer;
    answer.reserve(2);
    if (y2 - y1 != 0) {
        Fraction t = Fraction(y2) / Fraction(y2 - y1);
        t.reduce();
        if (0 <= x1 * t + (1 - t) * x2 && x1 * t + (1 - t) * x2 < side)
            answer.emplace_back((x1 * t + (1 - t) * x2) / side);
    }
    if (x2 - x1 != 0) {
        Fraction t = Fraction(x2 - side) / Fraction(x2 - x1);
        t.reduce();
        if (0 <= y1 * t + (1 - t) * y2 && y1 * t + (1 - t) * y2 < side)
            answer.emplace_back((y1 * t + (1 - t) * y2) / side + 1);
    }
    if (y2 - y1 != 0) {
        Fraction t = Fraction(y2 - side) / Fraction(y2 - y1);
        t.reduce();
        if (0 < x1 * t + (1 - t) * x2 && x1 * t + (1 - t) * x2 <= side)
            answer.emplace_back((-x1 * t + (t - 1) * x2) / side + 3);
    }
    if (x2 - x1 != 0) {
        Fraction t = Fraction(x2) / Fraction(x2 - x1);
        t.reduce();
        if (0 < y1 * t + (1 - t) * y2 && y1 * t + (1 - t) * y2 <= side)
            answer.emplace_back((-y1 * t + (t - 1) * y2) / side + 4);
    }
    return answer;
}

LineDetector::LineDetector(const BoolImage &input_contours)
        : input_contour(input_contours),
          side(std::max(input_contours.rows(), input_contours.cols())) {}

void LineDetector::find_black_points() {
    for (int i = 0; i < input_contour.rows(); i++)
        for (int j = 0; j < input_contour.cols(); j++)
            if (input_contour(i, j))
                black_points.emplace_back(i, j);
}

void LineDetector::find_lines_parameters() {
    for (int step = 0; step < Settings::count_of_attempts_find_line; step++) {
        int i = rand() % black_points.size(), j = rand() % black_points.size();
        while(i == j) j = rand() % black_points.size();

        int good = 0;
        for (Fraction t : Settings::check_lines)
            good += input_contour(
                    int(t * black_points[i].first + (1 - t) * black_points[j].first),
                    int(t * black_points[i].second + (1 - t) * black_points[j].second));
        if (good >= Settings::check_lines.size() * Settings::line_filling) {
            std::vector<Fraction> coords =
                    get_coordinates(black_points[i].second, black_points[j].second,
                                    black_points[i].first, black_points[j].first, side);
            coords[0].reduce(), coords[1].reduce();
            lines_parameters[coords[0]][coords[1]] += good;
        }
    }
}

static void merge(int a, int b, std::vector<int> &dsu) {
    if (rand() & 1U) dsu[a] = b;
    else             dsu[b] = a;
}

static int find(int a, std::vector<int> &dsu) {
    if (dsu[a] == -1) return a;
    return dsu[a] = find(dsu[a], dsu);
}

void LineDetector::claster_lines_parameters() {
    std::vector<int> dsu(black_points.size(), -1); // start = -1

    std::vector<std::pair<int, std::pair<Fraction, Fraction>>> sorted;
}

void LineDetector::find_lines() {

}

void LineDetector::detect() {
    find_black_points();
    find_lines_parameters();

    show();
}


void LineDetector::show() {
    cv::Mat img_result(cv::Size(input_contour.cols(), input_contour.rows()),
            CV_8U, cv::Scalar(255, 255, 255));
    cv::Mat img(cv::Size(900, 900),
            CV_8U, cv::Scalar(255, 255, 255));
    for (auto &i : lines_parameters) {
        for (auto &j : i.second) {
            cv::line(img_result, get_point(i.first, side),
                        get_point(j.first, side), cv::Scalar(0));
            img.at<uchar>(int(i.first * 200 + 50), int(j.first * 200 + 50)) =
                    std::max(int(img.at<uchar>(int(i.first * 200 + 50), int(j.first * 200 + 50)))
                        - j.second, 0);
        }
    }
    cv::imshow("img_line_result", img_result);
    cv::imshow("img_line_status", img);
}