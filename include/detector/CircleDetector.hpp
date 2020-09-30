#ifndef MAPLAP2_0_CIRCLEDETECTOR_HPP
#define MAPLAP2_0_CIRCLEDETECTOR_HPP

#include "opencv2/opencv.hpp"
#include "detector/Circle.hpp"
#include "detector/Fraction.hpp"
#include "detector/BoolImage.hpp"
#include "detector/Settings.hpp"
#include "detector/Line.hpp"

class CircleDetector {
private:

    const BoolImage &input_contour;
    std::vector<std::pair<int, int>> black_points;
    std::map<Fraction, std::map<Fraction, double>> centers_parameters; //yx
    std::map<Fraction, std::map<Fraction, std::vector<int>>> circles_parameters; //yxr
    std::vector<Circle> circles;

    [[nodiscard]] Line get_tangent_in_point(int x, int y) const;
    [[nodiscard]] std::pair<Circle, double> find_circle_percent(int x, int y) const;

    void find_black_points();
    void find_circles_parameters();
    void claster_cirles_parameters();
    void find_circles();

    void show();

public:

    explicit CircleDetector(const BoolImage &input_contours);

    void detect();

};


#endif //MAPLAP2_0_CIRCLEDETECTOR_HPP
