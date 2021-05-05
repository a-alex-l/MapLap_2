#include "detector/LineDetector.hpp"

#include "opencv2/opencv.hpp" //debug
static void show(const BoolImage &input_contour, Line l) { //debug
    static cv::Mat img_result(cv::Size(input_contour.cols(), input_contour.rows()),
                              CV_8U, cv::Scalar(255, 255, 255));
    cv::line(img_result, cv::Point(int(l.get_first().x), int(l.get_first().y)), cv::Point(int(l.get_second().x), int(l.get_second().y)), cv::Scalar(0));
    cv::imshow("img_Line_result", img_result);
    //cv::waitKey();
}

static void print(std::vector<Line> &lines) {
    for (auto line : lines)
        std::cout << line << "\n";
    std::cout.flush();
}

static Line get_line(int x1, int x2, int y1, int y2, int side) {
    std::vector<PointVector> accumulator;
    if (y2 - y1 != 0) {
        double t = double(y2) / double(y2 - y1);
        if (0 <= x1 * t + (1 - t) * x2 && x1 * t + (1 - t) * x2 < side)
            accumulator.emplace_back(0, x1 * t + (1 - t) * x2);
    }
    if (x2 - x1 != 0) {
        double t = double(x2 - side) / double(x2 - x1);
        if (0 <= y1 * t + (1 - t) * y2 && y1 * t + (1 - t) * y2 < side)
            accumulator.emplace_back(y1 * t + (1 - t) * y2, side);
    }
    if (y2 - y1 != 0) {
        double t = double(y2 - side) / double(y2 - y1);
        if (0 < x1 * t + (1 - t) * x2 && x1 * t + (1 - t) * x2 <= side)
            accumulator.emplace_back(side, x1 * t + (1 - t) * x2);
    }
    if (x2 - x1 != 0) {
        double t = double(x2) / double(x2 - x1);
        if (0 < y1 * t + (1 - t) * y2 && y1 * t + (1 - t) * y2 <= side)
            accumulator.emplace_back(y1 * t + (1 - t) * y2, 0);
    }
    return Line(accumulator[0], accumulator[1]);
}

LineDetector::LineDetector(const BoolImage &input_contours)
        : input_contour(input_contours),
          side(std::max(input_contours.rows(), input_contours.cols())),
          tangent_detector(input_contour, Settings::tangents_neighbours_count_line) {}

void LineDetector::find_black_points() {
    for (int i = 0; i < input_contour.rows(); i++)
        for (int j = 0; j < input_contour.cols(); j++)
            if (input_contour(i, j))
                black_points.emplace_back(i, j);
}

void LineDetector::find_pre_lines() {
    for (int step = 0; step < Settings::count_of_attempts_find_line; step++) {
        int i = rand() % black_points.size(), j = rand() % black_points.size();
        while(i == j) j = rand() % black_points.size();

        int good = 0;
        for (double t : Settings::check_lines)
            good += input_contour(
                    int(t * black_points[i].first + (1 - t) * black_points[j].first),
                    int(t * black_points[i].second + (1 - t) * black_points[j].second));
        if (good >= Settings::check_lines.size() * Settings::line_filling * 0.5) {
            show(input_contour, get_line(black_points[i].second, black_points[j].second,
                                         black_points[i].first, black_points[j].first, side));
            pre_lines.push_back(get_line(black_points[i].second, black_points[j].second,
                                         black_points[i].first, black_points[j].first, side));
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

void LineDetector::cluster_pre_lines() {
    std::vector<int> dsu(black_points.size(), -1); // start = -1

    std::vector<std::pair<int, std::pair<double, double>>> sorted;
}

void LineDetector::detect() {
    line_detector_timer.start();
    find_black_points();
    find_pre_lines();
    //print(pre_lines);
    cluster_pre_lines();
    print_timing();
    //print(lines);
}

void LineDetector::print_timing() noexcept {
    line_detector_timer.stop();
    line_detector_timer.print();
}

const std::vector<Line>& LineDetector::get_lines() const noexcept {
    return lines;
}
