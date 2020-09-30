#ifndef MAPLAP2_0_SETTINGS_HPP
#define MAPLAP2_0_SETTINGS_HPP

#include <vector>
#include <cmath>
#include "detector/Fraction.hpp"

namespace Settings {

    extern double circle_filling;
    extern double line_filling;
    extern int count_of_attempts_find_line;
    extern int count_of_attempts_find_circle;
    extern int block_size;
    extern int black_level;
    extern std::vector<double> check_circles;
    extern std::vector<Fraction> check_lines;
};

#endif //MAPLAP2_0_SETTINGS_HPP
