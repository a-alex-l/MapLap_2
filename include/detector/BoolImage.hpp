#ifndef MAPLAP2_0_BOOLIMAGE_HPP
#define MAPLAP2_0_BOOLIMAGE_HPP

#include "opencv2/opencv.hpp"
#include <vector>

struct BoolImage {  // false == white, true = black !

    std::vector<std::vector<bool>> data;

    BoolImage() = default;
    BoolImage(int rows, int cols);
    BoolImage(const cv::Mat &input);
    BoolImage(const BoolImage &other) = default;

    [[nodiscard]] int rows() const;
    [[nodiscard]] int cols() const;

    std::vector<bool, std::allocator<bool>>::reference operator()(int y, int x);
    bool operator()(int y, int x) const;

    explicit operator cv::Mat();

};

#endif //MAPLAP2_0_BOOLIMAGE_HPP
