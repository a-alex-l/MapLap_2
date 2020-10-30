#include "detector/Settings.hpp"

double Settings::tangents_angle_accuracy = 0.0001;
int Settings::tangents_neighbours_count_line     = 7;
int Settings::tangents_neighbours_count_ellipses = 7;
double Settings::ellipse_filling = 0.9;
double Settings::line_filling    = 0.9;
int Settings::count_of_attempts_find_line     = 10000;
int Settings::count_of_attempts_find_ellipses = 100;
int Settings::block_size = 101;
int Settings::black_level = 20;
std::vector<double> Settings::check_ellipses = {0.25, 0.4, -0.4, -0.25};
std::vector<double> Settings::check_lines    = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};