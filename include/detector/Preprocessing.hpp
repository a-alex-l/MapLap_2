#ifndef MAPLAP2_0_PREPROCESSING_HPP
#define MAPLAP2_0_PREPROCESSING_HPP

#include "opencv2/opencv.hpp"
#include "opencv2/opencv_modules.hpp"
#include "Settings.hpp"

namespace Preprocessing {

    cv::Mat make_black_white_image(const cv::Mat &input);

    cv::Mat find_contour_lines(const cv::Mat &gray_image);

}

#endif //MAPLAP2_0_PREPROCESSING_HPP
