#include "detector/Settings.hpp"

double Settings::circle_filling = 0.9;
double Settings::line_filling = 0.9;
int Settings::count_of_attempts_find_line = 1000;
int Settings::count_of_attempts_find_circle = 1000;
int Settings::block_size = 101;
int Settings::black_level = 20;
std::vector<double> Settings::check_circles = {M_PI * 0.05, M_PI * 0.15, M_PI * 0.25, M_PI * 0.35,
                                     M_PI * 0.45, M_PI * 0.55, M_PI * 0.65, M_PI * 0.75,
                                     M_PI * 0.85, M_PI * 0.95};
std::vector<Fraction> Settings::check_lines = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9};