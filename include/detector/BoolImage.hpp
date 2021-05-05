#ifndef MAPLAP2_0_BOOLIMAGE_HPP
#define MAPLAP2_0_BOOLIMAGE_HPP

#include "opencv2/opencv.hpp"
#include "shapes/PointVector.hpp"
#include <vector>

class BoolImage {  // false == white, true = black !
private:

    std::vector<bool, std::allocator<bool>>::reference get_link(int y, int x);
    bool get_copy(int y, int x) const;

public:

    std::vector<std::vector<bool>> data;

    BoolImage() = default;
    BoolImage(int rows, int cols);
    BoolImage(const cv::Mat &input);
    BoolImage(const BoolImage &other) = default;

    [[nodiscard]] int rows() const;
    [[nodiscard]] int cols() const;

    bool operator==(const BoolImage &other) const noexcept;
    bool operator!=(const BoolImage &other) const noexcept;

    std::vector<bool, std::allocator<bool>>::reference operator()(int y, int x);
    bool operator()(int y, int x) const;
    std::vector<bool, std::allocator<bool>>::reference operator()(const PointVector &point);
    bool operator()(const PointVector &point) const;

    explicit operator cv::Mat();

};

#endif //MAPLAP2_0_BOOLIMAGE_HPP
