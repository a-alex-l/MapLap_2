#include "detector/CircleDetector.hpp"



void CircleDetector::find_black_points() {
    for (int i = 0; i < input_contour.rows(); i++)
        for (int j = 0; j < input_contour.cols(); j++)
            if (input_contour(i, j))
                black_points.emplace_back(i, j);
}

void CircleDetector::find_circles_parameters() {
    std::vector<double> check = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};
    for (int step = 0; step < black_points.size() * 100; step++) {
        int i = rand() % black_points.size(),
            j = rand() % black_points.size(),
            k = rand() % black_points.size();
        int divider = 2 * (black_points[j].first  - black_points[i].first) *
                          (black_points[k].second - black_points[j].second) -
                  2 * (black_points[j].second - black_points[i].second) *
                      (black_points[k].first  - black_points[j].first);
        if (abs(divider) > 10) {
            double e = black_points[j].first * black_points[j].first -
                       black_points[i].first * black_points[i].first +
                       black_points[j].second * black_points[j].second -
                       black_points[i].second * black_points[i].second;
            double f = black_points[k].first * black_points[k].first -
                       black_points[i].first * black_points[i].first +
                       black_points[k].second * black_points[k].second -
                       black_points[i].second * black_points[i].second;
            double center_x = ((black_points[k].second - black_points[i].second) * e -
                               (black_points[j].second - black_points[i].second) * f) / divider,
                   center_y = ((black_points[j].first - black_points[i].first) * f -
                               (black_points[k].first - black_points[i].first) * e) / divider;
            double radius = sqrt((center_x - black_points[i].first) * (center_x - black_points[i].first) +
                                 (center_y - black_points[i].second) * (center_y - black_points[i].second));
            cv::Mat img_result(cv::Size(input_contour.cols(), input_contour.rows()),
                               CV_8U, cv::Scalar(255, 255, 255));
            img_result.at<uchar>(black_points[i].first, black_points[i].second) = 0;
            img_result.at<uchar>(black_points[j].first, black_points[j].second) = 0;
            img_result.at<uchar>(black_points[k].first, black_points[k].second) = 0;
            cv::circle(img_result, cv::Point(center_y, center_x), int(radius), cv::Scalar(150));
            cv::imshow("img_circles_result", img_result);
            cv::waitKey();
            circles_parameters[center_x][center_y][radius]++;
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
                cv::circle(img_result, cv::Point(i.first, j.first), int(r.first), cv::Scalar(255 - r.second * 10));
            }
        }
    }
    cv::imshow("img_circles_result", img_result);
}