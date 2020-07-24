#include "detector/CircleDetector.hpp"



void CircleDetector::find_black_points() {
    for (int i = 0; i < input_contour.rows(); i++)
        for (int j = 0; j < input_contour.cols(); j++)
            if (input_contour(i, j))
                black_points.emplace_back(i, j);
}

void CircleDetector::find_circles_parameters() {
    std::vector<Fraction> check = {Fraction(1)/10, Fraction(3)/10,
            Fraction(5)/10, Fraction(7)/10, Fraction(9)/10};
    for (int step = 0; step < black_points.size() * 100; step++) {
        int i = rand() % black_points.size(),
            j = rand() % black_points.size(),
            k = rand() % black_points.size();
        Fraction divider = 2 * (black_points[j].first  - black_points[i].first) *
                          (black_points[k].second - black_points[j].second) -
                           2 * (black_points[j].second - black_points[i].second) *
                          (black_points[k].first  - black_points[j].first);
        if (divider > 10) {
            Fraction e = black_points[j].first * black_points[j].first -
                       black_points[i].first * black_points[i].first +
                       black_points[j].second * black_points[j].second -
                       black_points[i].second * black_points[i].second;
            Fraction f = black_points[k].first * black_points[k].first -
                       black_points[i].first * black_points[i].first +
                       black_points[k].second * black_points[k].second -
                       black_points[i].second * black_points[i].second;
            Fraction center_x = ((black_points[k].second - black_points[i].second) * e -
                               (black_points[j].second - black_points[i].second) * f) / divider,
                   center_y = ((black_points[j].first - black_points[i].first) * f -
                               (black_points[k].first - black_points[i].first) * e) / divider;
            center_x.reduce(), center_y.reduce();
            Fraction radius2 =  (center_x - black_points[i].first).reduce() *
                                (center_x - black_points[i].first).reduce() +
                                (center_y - black_points[i].second).reduce() *
                                (center_y - black_points[i].second).reduce();
            radius2.reduce();
            if (0 <= center_x && center_x <= input_contour.cols() && 0 <= center_y &&
                    center_y <= input_contour.rows() && 1 < radius2 &&
                    radius2 < input_contour.cols() * input_contour.cols() +
                    input_contour.rows() + input_contour.rows())
                circles_parameters[center_x][center_y][radius2]++;
        }
    }
}

void CircleDetector::claster_cirles_parameters() {

}

void CircleDetector::find_circles() {

}

CircleDetector::CircleDetector(const BoolImage &input_contours) : input_contour(input_contours) {}

void CircleDetector::detect() {
    find_black_points();
    find_circles_parameters();

    show();
}

void CircleDetector::show() {
    std::cout << circles_parameters.size() << std::endl;
    cv::Mat img_result(cv::Size(input_contour.cols(), input_contour.rows()),
                       CV_8U, cv::Scalar(255, 255, 255));
    for (auto &i : circles_parameters) {
        for (auto &j : i.second) {
            for (auto &r : j.second) {
                std::cout << i.first << " " << j.first << " " << r.first << " " << std::endl;
                cv::circle(img_result, cv::Point(int(i.first), int(j.first)),
                        int(sqrt(r.first)), cv::Scalar(255 - r.second * 20));
            }
        }
    }
    cv::imshow("img_circles_result", img_result);
}