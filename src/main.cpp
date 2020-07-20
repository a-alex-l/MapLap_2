#include "opencv2/opencv.hpp"
#include "detector/Preprocessing.hpp"
#include "detector/Detector.hpp"

int main() {
    cv::Mat img = cv::imread("test_files/LineTry.png");
    cv::Mat img_gray = Preprocessing::make_black_white_image(img);
    cv::Mat img_contour = Preprocessing::find_contour_lines(img_gray);
    cv::imshow("img", img);
    cv::imshow("img_gray", img_gray);
    cv::imshow("img_contour", img_contour);
    Detector detector(img_contour);
    detector.detect();
    cv::waitKey();
    return 0;
}
