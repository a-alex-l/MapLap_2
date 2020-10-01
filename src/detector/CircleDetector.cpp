#include "detector/CircleDetector.hpp"


std::vector<std::pair<Circle, double>> CircleDetector::find_circles(PointVector point,
            const std::vector<PointVector> &first, const std::vector<PointVector> &second,
            std::vector<std::pair<Circle, double>> &ans) {
    for (int i = 0, j = 0; i < first.size(); i++) {
        while (j < second.size() && (point - second[j]).length()
                                    /(point - first[i]).length() < 0.8) j++;
        if (j == second.size()) break;
        for (int k = j; k < second.size() && (point - first[i]).length()
                                             /(point - second[k]).length() < 0.8; k++) {
            if (Circle(point, first[i], second[k]).get_percent_intersection(input_contour)
                    >= Settings::circle_filling * 0.5) {
                ans.emplace_back(Circle(point, first[i], second[k]),
                    Circle(point, first[i], second[k]).get_percent_intersection(input_contour));
            }
        }
    }
    return ans;
}

std::vector<std::pair<Circle, double>> CircleDetector::find_circles_percent(PointVector point) {
    std::vector<std::pair<Circle, double>> ans;
    Line tangent = Line(point, point +
            tangent_detector.get(point.y, point.x) * 1000);
    std::vector<PointVector>
    rotate60 = tangent.rotate_around_first(M_PI / 3.0).get_intersection(input_contour),
    rotate120 = tangent.rotate_around_first(2 * M_PI / 3.0).get_intersection(input_contour);
    find_circles(point, rotate60, rotate120, ans);
    rotate60 = tangent.rotate_around_first(-M_PI / 3.0).get_intersection(input_contour),
    rotate120 = tangent.rotate_around_first(-2 * M_PI / 3.0).get_intersection(input_contour);
    find_circles(point, rotate60, rotate120, ans);
    return ans;
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
        std::vector<std::pair<Circle, double>> result =
                find_circles_percent(PointVector(black_points[i].first, black_points[i].second));

        for (const std::pair<Circle, double> &circle : result) {
            centers_parameters[circle.first.get_y()][circle.first.get_x()] += circle.second;
            circles_parameters[circle.first.get_y()]
                              [circle.first.get_x()].emplace_back(circle.first.get_radius());
        }
    }
}

void CircleDetector::claster_cirles_parameters() {

}

void CircleDetector::find_circles() {

}

CircleDetector::CircleDetector(const BoolImage &input_contours) :
            input_contour(input_contours),
            tangent_detector(input_contour, Settings::tangents_neighbours_count_circle) {}

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
                cv::circle(img_result, cv::Point(int(j.first), int(i.first)),
                           int(r), cv::Scalar(0));
            }
        }
    }
    cv::imshow("img_circles_result", img_result);
}