#ifndef MAPLAP2_0_SETTINGS_HPP
#define MAPLAP2_0_SETTINGS_HPP

#include <vector>
#include <cmath>

namespace Settings {

    extern double tangents_angle_accuracy;
    extern int tangents_neighbours_count_line;
    extern int tangents_neighbours_count_ellipses;
    extern double ellipse_filling;
    extern double line_filling;
    extern int count_of_attempts_find_line;
    extern int count_of_attempts_find_ellipses;
    extern int block_size;
    extern int black_level;
    extern std::vector<double> check_ellipses;
    extern std::vector<double> check_lines;
};

#endif //MAPLAP2_0_SETTINGS_HPP
