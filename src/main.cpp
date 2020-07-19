#include "opencv2/opencv.hpp"
#include "opencv2/opencv_modules.hpp"
#include "detector/Settings.hpp"
#include "detector/Preprocessing.hpp"

int main() {
    cv::Mat img = cv::imread("test_files/TestPreprocessing_1_input.png");
    cv::Mat img_gray = Preprocessing::make_black_white_image(img);
    cv::Mat img_contour = Preprocessing::find_contour_lines(img_gray);
    cv::Mat img_right = cv::imread("test_files/TestPreprocessing_1_output.png",  CV_8U);
    cv::imshow("img", img);
    cv::imshow("img_right", img_right);
    cv::imshow("img_gray", img_gray);
    cv::imshow("img_contour", img_contour);
    cv::waitKey();
    return 0;
}
