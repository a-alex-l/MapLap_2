#define CATCH_CONFIG_MAIN
#include "Catch.hpp"
#include "opencv2/opencv.hpp"
#include "detector/Settings.hpp"
#include "detector/Detector.hpp"
#include "detector/Preprocessing.hpp"
#include "Writer.h"

TEST_CASE("Empty test!") {
    REQUIRE(true);
}

TEST_CASE("test 1. Just one line.") {
    cv::Mat line_img = cv::imread("../test/test_files/test_1_input.png");
    REQUIRE(!line_img.empty());
    BoolImage line_img_bool = Preprocessing::make_black_white_image(line_img);
    BoolImage line_img_contour = Preprocessing::find_contour_lines(line_img_bool);
    Detector detector(line_img_contour);
    detector.detect();
    Writer::write(line_img.size[1], line_img.size[0],
                  "../test/test_files/test_1_ans.txt",
                  detector.get_lines(), detector.get_ellipses());
    REQUIRE(true);
}

TEST_CASE("test 6. Just one circle.") {
    cv::Mat circle_img = cv::imread("../test/test_files/test_6_input.png");
    REQUIRE(!circle_img.empty());
    BoolImage circle_img_bool = Preprocessing::make_black_white_image(circle_img);
    BoolImage circle_img_contour = Preprocessing::find_contour_lines(circle_img_bool);
    Detector detector(circle_img_contour);
    detector.detect();
    Writer::write(circle_img.size[1], circle_img.size[0],
                  "../test/test_files/test_6_ans.txt",
                  detector.get_lines(), detector.get_ellipses());
    REQUIRE(true);
}

