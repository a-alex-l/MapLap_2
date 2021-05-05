#include "detector/EllipseDetector.hpp"

#include "opencv2/opencv.hpp" //debug
static void show(const BoolImage &input_contour, Ellipse l) { //debug
    static cv::Mat img_result(cv::Size(input_contour.cols(), input_contour.rows()),
                              CV_8U, cv::Scalar(255, 255, 255));
    //cv::line(img_result, cv::Point(int(l.get_first().x), int(l.get_first().y)), cv::Point(int(l.get_second().x), int(l.get_second().y)), cv::Scalar(0));
    cv::imshow("img_Ellipse_result", img_result);
    //cv::waitKey();
}

static void print(std::vector<Ellipse> &ellipses) {
    for (auto ellipse : ellipses)
        std::cout << ellipse << "\n";
    std::cout.flush();
}

void EllipseDetector::find_pre_ellipses(int y, int x,
            const std::vector<PointVector> &intersection_1) {
    for (auto i : intersection_1) {
        int y2 = int(round(i.y)), x2 = int(round(i.x));
        PointVector tangent1 = tangent_detector.get(y, x), tangent2 = tangent_detector.get(y2, x2);
        Ellipse ellipse(x, y, tangent1.x, tangent1.y, x2, y2, tangent2.x, tangent2.y);
        if (ellipse.is_init()) {
            pre_ellipses.emplace_back(ellipse);
        }
    }
}

void EllipseDetector::find_pre_ellipses(int y, int x) {
    PointVector point(y, x);
    Line tangent = Line(point, point + tangent_detector.get(point.y, point.x) *
                         (input_contour.rows() + input_contour.cols()));
    for (auto i : Settings::check_ellipses) {
        std::vector<PointVector> intersection =
                tangent.rotate_around_first( M_PI * i).get_intersection(input_contour);
        find_pre_ellipses(y, x, intersection);
    }
}

void EllipseDetector::find_black_points() {
    for (int i = 0; i < input_contour.rows(); i++)
        for (int j = 0; j < input_contour.cols(); j++)
            if (input_contour(i, j))
                black_points.emplace_back(i, j);
}

void EllipseDetector::find_pre_ellipses() {
    for (int step = 0; pre_ellipses.size() < Settings::count_of_attempts_find_ellipses; step++) {
        int i = rand() % black_points.size();
        find_pre_ellipses(int(round(black_points[i].first)),
                        int(round(black_points[i].second)));
    }
}

void EllipseDetector::cluster_pre_ellipses() {
    ellipses = pre_ellipses;
    sort(ellipses.begin(), ellipses.end());
}

EllipseDetector::EllipseDetector(const BoolImage &input_contours) :
            input_contour(input_contours),
            tangent_detector(input_contour, Settings::tangents_neighbours_count_ellipses) {

}

void EllipseDetector::print_timing() noexcept {
    ellipse_detector_timer.stop();
    ellipse_detector_timer.print();
}

void EllipseDetector::detect() {
    ellipse_detector_timer.start();
    find_black_points();
    find_pre_ellipses();
    //print(pre_ellipses);
    cluster_pre_ellipses();
    print_timing();
    //print(ellipses);
}

const std::vector<Ellipse> &EllipseDetector::get_ellipses() const noexcept {
    return ellipses;
}
