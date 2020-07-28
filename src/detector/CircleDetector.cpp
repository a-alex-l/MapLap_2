#include "detector/CircleDetector.hpp"

std::vector<Fraction> CircleDetector::get_params(int x1, int y1, int x2, int y2, int x3, int y3) {
    Fraction good = 0;
    Fraction divider = 2 * (y2  - y1) * (x3 - x2) - 2 * (x2 - x1) * (y3  - y2);
    if (divider != 0) {
        Fraction e = y2 * y2 - y1 * y1 + x2 * x2 - x1 * x1;
        Fraction f = y3 * y3 - y1 * y1 + x3 * x3 - x1 * x1;
        PointVector center(((x3 - x1) * e - (x2 - x1) * f) / divider,
                           ((y2 - y1) * f - (y3 - y1) * e) / divider);
        center.x.reduce(), center.y.reduce();
        center.x.make_base(4), center.y.make_base(4);
        Fraction radius2 = (center.x - x1).reduce() * (center.x - x1).reduce() +
                           (center.y - y1).reduce() * (center.y - y1).reduce();
        radius2.reduce(), radius2.make_base(10);
        Fraction radius = sqrt(radius2);
        if (0 <= center.x && center.x <= input_contour.cols() && 0 <= center.y &&
                             center.y <= input_contour.rows() && 3 < radius)
            for (auto t : Settings::check_circles)
                good += input_contour(center + PointVector(radius, 0).rotate(t));
        return {good, center.y, center.x, radius};
    }
    return {0};
}

void CircleDetector::find_black_points() {
    for (int i = 0; i < input_contour.rows(); i++)
        for (int j = 0; j < input_contour.cols(); j++)
            if (input_contour(i, j))
                black_points.emplace_back(i, j);
}

void CircleDetector::find_circles_parameters() {
    std::vector<double> check = {M_PI * 1.0 / 6.0, M_PI * 3.0 / 6.0, M_PI * 5.0 / 6.0,
                                 M_PI * 7.0 / 6.0, M_PI * 9.0 / 6.0, M_PI * 11.0 / 6.0};
    for (int step = 0; step < black_points.size() * 30; step++) {
        int     i = rand() % black_points.size(),
                j = rand() % black_points.size(),
                k = rand() % black_points.size();
        std::vector<Fraction> results = get_params(black_points[i].second, black_points[i].first,
                                                   black_points[j].second, black_points[j].first,
                                                   black_points[k].second, black_points[k].first);
        if (results[0] >= 6) {
            centers_parameters[results[2]][results[1]] += int(results[0]);
            circles_parameters[results[2]][results[1]].emplace_back(results[3]);
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
    cv::Mat img_result(cv::Size(input_contour.cols(), input_contour.rows()),
                       CV_8U, cv::Scalar(255, 255, 255));
    for (auto &i : circles_parameters) {
        for (auto &j : i.second) {
            for (auto &r : j.second) {
                cv::circle(img_result, cv::Point(int(i.first), int(j.first)),
                           int(r), cv::Scalar(0));
            }
        }
    }
    cv::imshow("img_circles_result", img_result);
}