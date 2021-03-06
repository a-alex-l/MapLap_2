#include "opencv2/opencv.hpp"
#include "detector/Preprocessing.hpp"
#include "detector/Detector.hpp"

int main() {
    cv::Mat img = cv::imread("../test/test_files/test_1_input.png");
    if (img.empty()) {
        return 1;
    }
    BoolImage img_bool = Preprocessing::make_black_white_image(img);
    BoolImage img_contour = Preprocessing::find_contour_lines(img_bool);
    //cv::imshow("img", img);
    //cv::imshow("img_bool", cv::Mat(img_bool));
    cv::imshow("img_contour", cv::Mat(img_contour));
    Detector detector(img_contour);
    detector.detect();
    cv::waitKey();
    return 0;
}
