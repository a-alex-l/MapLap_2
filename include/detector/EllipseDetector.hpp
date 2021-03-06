#ifndef MAPLAP2_0_ELLIPSEDETECTOR_HPP
#define MAPLAP2_0_ELLIPSEDETECTOR_HPP

#include "shapes/Ellipse.hpp"
#include "BoolImage.hpp"
#include "Settings.hpp"
#include "shapes/Line.hpp"
#include "TangentsDetector.hpp"
#include "Timer.hpp"

class EllipseDetector {
private:

    const BoolImage &input_contour;
    std::vector<std::pair<int, int>> black_points;
    std::vector<Ellipse> pre_ellipses, ellipses;
    TangentsDetector tangent_detector;
    Timer ellipse_detector_timer = Timer("EllipseDetector work time: %f.\n");

    void find_pre_ellipses( int y, int x, const std::vector<PointVector> &intersection_1);
    void find_pre_ellipses(int y, int x);
    void find_black_points();
    void find_pre_ellipses();
    void cluster_pre_ellipses();
    
    void print_timing() noexcept;

public:

    explicit EllipseDetector(const BoolImage &input_contours);

    void detect();

    [[nodiscard]] const std::vector<Ellipse>& get_ellipses() const noexcept;

};


#endif //MAPLAP2_0_ELLIPSEDETECTOR_HPP
