#include "detector/Preprocessing.hpp"

cv::Mat Preprocessing::make_black_white_image(const cv::Mat &input) {
    cv::Mat gray_image_input = input, gray_image_output;
    cv::cvtColor(input, gray_image_input, cv::COLOR_RGB2GRAY);
    cv::adaptiveThreshold(gray_image_input, gray_image_output, 255,
                          cv::ADAPTIVE_THRESH_GAUSSIAN_C,
                          cv::THRESH_BINARY,
                          Settings::block_size,
                          Settings::black_level);
    return gray_image_output;
}

BoolImage Preprocessing::find_contour_lines(const BoolImage &input) {
    BoolImage contour_image(input);
    for (int i = 1; i + 1 < input.rows(); i++)
        for (int j = 1; j + 1 < input.cols(); j++)
            if     (input(i - 1, j) &&
                    input(i + 1, j) &&
                    input(i, j + 1) &&
                    input(i, j - 1) &&
                    input(i, j))
                contour_image(i, j) = false;
    return contour_image;
}