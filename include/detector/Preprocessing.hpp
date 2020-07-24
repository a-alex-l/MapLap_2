#ifndef MAPLAP2_0_PREPROCESSING_HPP
#define MAPLAP2_0_PREPROCESSING_HPP

#include "detector/BoolImage.hpp"
#include "detector/Settings.hpp"

namespace Preprocessing {

    cv::Mat make_black_white_image(const cv::Mat &input);

    BoolImage find_contour_lines(const BoolImage &input);

}

#endif //MAPLAP2_0_PREPROCESSING_HPP
