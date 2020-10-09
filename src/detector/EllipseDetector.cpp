#include "detector/EllipseDetector.hpp"

static void print(std::vector<Ellipse> &ellipses) {
    for (auto ellipse : ellipses)
        std::cout << ellipse << "\n";
    std::cout.flush();
}

void EllipseDetector::find_pre_ellipses(int y, int x, const std::vector<PointVector> &intersection) {
    for (auto i : intersection) {
        int y2 = int(round(i.y)), x2 = int(round(i.x));
        PointVector tangent1 = tangent_detector.get(y, x), tangent2 = tangent_detector.get(y2, x2);
        Ellipse ellipse(x, y, x2, y2, tangent1.x, tangent1.y, tangent2.x, tangent2.y);
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
                tangent.rotate_around_first(M_PI * i).get_intersection(input_contour);
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
    for (int step = 0; step < Settings::count_of_attempts_find_ellipses; step++) {
        int i = rand() % black_points.size();
        find_pre_ellipses(int(round(black_points[i].first)),
                        int(round(black_points[i].second)));
    }
}

void EllipseDetector::claster_pre_ellipses() {
    ellipses = pre_ellipses;
}

EllipseDetector::EllipseDetector(const BoolImage &input_contours) :
            input_contour(input_contours),
            tangent_detector(input_contour, Settings::tangents_neighbours_count_ellipses) {

}

EllipseDetector::~EllipseDetector() {
    ellipse_detector_timer.stop();
    ellipse_detector_timer.print();
}

void EllipseDetector::detect() {
    find_black_points();
    find_pre_ellipses();
    print(pre_ellipses);
    claster_pre_ellipses();
    print(ellipses);
}