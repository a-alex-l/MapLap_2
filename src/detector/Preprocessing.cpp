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

cv::Mat Preprocessing::find_contour_lines(const cv::Mat &gray_image) {
    cv::Mat contour_image;
    gray_image.copyTo(contour_image);
    for (int i = 1; i + 1 < gray_image.rows; i++)
        for (int j = 1; j + 1 < gray_image.cols; j++)
            if     (gray_image.at<uchar>(i - 1, j) == 0 &&
                    gray_image.at<uchar>(i + 1, j) == 0 &&
                    gray_image.at<uchar>(i, j + 1) == 0 &&
                    gray_image.at<uchar>(i, j - 1) == 0 &&
                    gray_image.at<uchar>(i, j) == 0)
                contour_image.at<uchar>(i, j) = 255;
    return contour_image;
}