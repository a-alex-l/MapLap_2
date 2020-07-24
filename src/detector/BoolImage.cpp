#include "detector/BoolImage.hpp"

BoolImage::BoolImage(int rows, int cols) {
    data.resize(rows, std::vector<bool>(cols, false));
}

BoolImage::BoolImage(const cv::Mat &input) {
    data.resize(input.rows, std::vector<bool>(input.cols, false));
    for (int i = 0; i < input.rows; i++)
        for (int j = 0; j < input.cols; j++)
            data[i][j] = !bool(input.at<uchar>(i, j));
}

int BoolImage::rows() const {
    return data.size();
}

int BoolImage::cols() const {
    if (data.empty()) return 0;
    return data[0].size();
}

std::vector<bool, std::allocator<bool>>::reference BoolImage::operator()(int y, int x) {
    return data[y][x];
}

bool BoolImage::operator()(int y, int x) const {
    return data[y][x];
}


BoolImage::operator cv::Mat() {
    cv::Mat answer(this->rows(), this->cols(), CV_8U, cv::Scalar(255));
    for (int i = 0; i < this->rows(); i++)
        for (int j = 0; j < this->cols(); j++)
            if ((*this)(i, j))
                answer.at<uchar>(i, j) = 0;
    return answer;
}

bool BoolImage::operator==(const BoolImage &other) const noexcept {
    return data == other.data;
}

bool BoolImage::operator!=(const BoolImage &other) const noexcept {
    return data != other.data;
}