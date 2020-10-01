#include "detector/TangentsDetector.hpp"

#include <queue>
#include "opencv2/opencv.hpp"

static void show(const BoolImage &input_contour, int y1, int x1, int y2, int x2) { //debug
    static cv::Mat img_result(cv::Size(input_contour.cols(), input_contour.rows()),
                       CV_8U, cv::Scalar(255, 255, 255));
    cv::line(img_result, cv::Point(x1, y1), cv::Point(x2, y2), cv::Scalar(0));
    cv::circle(img_result, cv::Point((x1 + x2) / 2, (y1 + y2) / 2), 3, cv::Scalar(0));
    cv::imshow("img_Tangent_result", img_result);
    //cv::waitKey();
}

TangentsDetector::TangentsDetector(const BoolImage &input_contours, int neighbours_count)
    : input_contour(input_contours), neighbours_count(neighbours_count) {}


PointVector TangentsDetector::get(int y, int x) {
    if (tangents.find({y, x}) != tangents.end()) {
        return tangents[{y, x}];
    }
    double tangent_angle = ternary_search(y, x);
    show(input_contour, y + sin(tangent_angle) * 10, x + cos(tangent_angle) * 10,
            y - sin(tangent_angle) * 10, x - cos(tangent_angle) * 10);
    return tangents[{y, x}] = PointVector(cos(tangent_angle), sin(tangent_angle));
}


double TangentsDetector::ternary_search(int y, int x) const {
    std::vector<std::pair<double, double>> length_angle = get_neighbours(y, x);
    double least = M_PI, greatest = 0;
    for (std::pair<double, double> &i : length_angle) {
        if (i.second < 0) i.second += M_PI;
        least = std::min(least, i.second);
        greatest = std::max(greatest, i.second);
    }
    while (greatest - least > Settings::tangents_angle_accuracy) {
        double mid_llg = (least * 2 + greatest * 1) / double(3);
        double mid_lgg = (least * 1 + greatest * 2) / double(3);
        if     (  get_sum_distance(mid_llg, length_angle)
                < get_sum_distance(mid_lgg, length_angle))
            greatest = mid_lgg;
        else
            least = mid_llg;
    }
    return (greatest + least) / double(2);
}


std::vector<std::pair<double, double>> TangentsDetector::get_neighbours(int y, int x) const {
    static std::vector<std::pair<int, int>> move =
            {{1, 0}, {1, 1}, {0, 1}, {-1, 1},
             {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
    std::queue<std::pair<int, int>> que;
    que.push({y, x});
    std::vector<std::pair<double, double>> answer;
    std::map<std::pair<int, int>, bool> used;
    for (int step = 0; step < neighbours_count * 3 && answer.size() < neighbours_count; step++) {
        std::pair<int, int> point = que.front();
        if (step * 2 > neighbours_count)
            answer.emplace_back((PointVector(y, x) - PointVector(point.first, point.second)).length(),
                          atan2(y - point.first, x - point.second));
        que.pop();
        for (const std::pair<int, int> &i : move) {
            std::pair<int, int> new_point = {i.first + point.first, i.second + point.second};
            if (input_contour(new_point.first, new_point.second)
                    && used.find(new_point) == used.end())
                que.push(new_point);
        }
    }
    return answer;
}


double TangentsDetector::get_sum_distance(double angle,
                const std::vector<std::pair<double, double>> &neighbours) const {
    double answer = 0;
    for (const std::pair<double, double> &i : neighbours)
        answer += fabs(sin(angle - i.second)) * i.first;
}