#ifndef MAPLAP2_0_CIRCLEDETECTOR_HPP
#define MAPLAP2_0_CIRCLEDETECTOR_HPP

#include "opencv2/opencv.hpp"
#include "detector/Circle.hpp"
#include "detector/Fraction.hpp"
#include "detector/BoolImage.hpp"
#include "detector/Settings.hpp"

class CircleDetector {
private:

    const BoolImage &input_contour;
    std::vector<std::pair<int, int>> black_points;
    std::map<Fraction, std::map<Fraction, int>> centers_parameters; //yx
    std::map<Fraction, std::map<Fraction, std::vector<int>>> circles_parameters; //yxr
    std::vector<Circle> circles;

    std::vector<Fraction> get_params(int x1, int y1, int x2, int y2, int x3, int y3);

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
