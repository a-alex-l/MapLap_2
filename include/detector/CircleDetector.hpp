#ifndef MAPLAP2_0_CIRCLEDETECTOR_HPP
#define MAPLAP2_0_CIRCLEDETECTOR_HPP

#include "opencv2/opencv.hpp"
#include "detector/Circle.hpp"
#include "detector/Fraction.hpp"
#include "detector/BoolImage.hpp"

class CircleDetector {
private:

    const BoolImage &input_contour;
    std::vector<std::pair<int, int>> black_points;
    std::map<Fraction, std::map<Fraction, std::map<Fraction, int>>> circles_parameters; //yxr
    std::vector<Circle> circles;

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
