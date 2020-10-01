#ifndef MAPLAP2_0_CIRCLEDETECTOR_HPP
#define MAPLAP2_0_CIRCLEDETECTOR_HPP

#include "detector/Circle.hpp"
#include "detector/BoolImage.hpp"
#include "detector/Settings.hpp"
#include "detector/Line.hpp"
#include "detector/TangentsDetector.hpp"

class CircleDetector {
private:

    const BoolImage &input_contour;
    std::vector<std::pair<int, int>> black_points;
    std::map<double, std::map<double, double>> centers_parameters; //yx
    std::map<double, std::map<double, std::vector<int>>> circles_parameters; //yxr
    std::vector<Circle> circles;
    TangentsDetector tangent_detector;

    std::vector<std::pair<Circle, double>> find_circles(PointVector point,
                    const std::vector<PointVector> &first, const std::vector<PointVector> &second,
                    std::vector<std::pair<Circle, double>> &ans);
    [[nodiscard]] std::vector<std::pair<Circle, double>> find_circles_percent(PointVector point);

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
