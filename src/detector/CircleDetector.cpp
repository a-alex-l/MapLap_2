#include "detector/CircleDetector.hpp"

Line CircleDetector::get_tangent_in_point(int x, int y) const {
    std::vector<PointVector> move =
            {{1, 0}, {1, 1}, {0, 1}, {-1, 1},
             {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
    PointVector now = {x, y};
    for (int i = 0; i < 2; i++)
        for (const auto & j : move)
            if (input_contour(now + j)) {
                now += j;
                break;
            }
    return Line(now, {x, y});
}

std::pair<Circle, double> CircleDetector::find_circle_percent(int x, int y) const {
    Line tangent = get_tangent_in_point(x, y);
    std::vector<PointVector>
    rotate60 = tangent.rotate_around_first(M_PI / 3.0).get_intersection(input_contour),
    rotate120 = tangent.rotate_around_first(2 * M_PI / 3.0).get_intersection(input_contour);
    double best_circle_score = 0;
    Circle ans;
    for (PointVector &i : rotate60)
        for (PointVector &j : rotate120)
            if (Circle({x, y}, i, j).get_radius() != -1 &&
                    Circle({x, y}, i, j).get_percent_intersection(input_contour)
                    > best_circle_score) {
                ans = Circle({x, y}, i, j);
                best_circle_score = ans.get_percent_intersection(input_contour);
            }
    return { ans, best_circle_score };
}

void CircleDetector::find_black_points() {
    for (int i = 0; i < input_contour.rows(); i++)
        for (int j = 0; j < input_contour.cols(); j++)
            if (input_contour(i, j))
                black_points.emplace_back(i, j);
}

void CircleDetector::find_circles_parameters() {
    for (int step = 0; step < Settings::count_of_attempts_find_circle; step++) {
        int i = rand() % black_points.size();
        std::pair<Circle, double> result =
                find_circle_percent(black_points[i].second, black_points[i].first);

        if (result.second > Settings::circle_filling) {
            centers_parameters[result.first.get_x()][result.first.get_y()] += result.second;
            circles_parameters[result.first.get_x()]
                              [result.first.get_y()].emplace_back(result.first.get_radius());
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