#ifndef MAPLAP2_0_LINEDETECTOR_HPP
#define MAPLAP2_0_LINEDETECTOR_HPP


#include <map>
#include <vector>

#include "opencv2/opencv.hpp"
#include "detector/Line.hpp"
#include "detector/Fraction.hpp"
#include "detector/BoolImage.hpp"

class LineDetector {
private:

    int side;
    const BoolImage &input_contour;
    std::vector<std::pair<int, int>> black_points;
    std::map<Fraction, std::map<Fraction, int>> lines_parameters;
    std::vector<Line> lines;

    void find_black_points();
    void find_lines_parameters();
    void claster_lines_parameters();
    void find_lines();

    void show();

public:

    explicit LineDetector(const BoolImage &input_contours);

    void detect();

};

#endif //MAPLAP2_0_LINEDETECTOR_HPP
