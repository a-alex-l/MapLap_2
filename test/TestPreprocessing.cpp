#include "Catch.hpp"
#include "detector/Preprocessing.hpp"

bool equal(const cv::Mat &a, const cv::Mat &b) {
    if (!(a.rows == b.rows && a.cols == b.cols))
        return false;
    for (int i = 0; i < a.rows; i++)
        for (int j = 0; j < a.cols; j++)
            if (a.at<uchar>(i, j) != b.at<uchar>(i, j))
                return false;
    return true;
}

TEST_CASE("Preprocessing make_black_white_image 1") {
    cv::Mat img = cv::imread("test_files/TestPreprocessing_Make_Black_White_Image_1_input.png");
    cv::Mat img_gray = Preprocessing::make_black_white_image(img);
    cv::Mat img_right;
    cv::cvtColor(
        cv::imread("test_files/TestPreprocessing_Make_Black_White_Image_1_output.png"),
        img_right,cv::COLOR_RGB2GRAY);
    REQUIRE(equal(img_gray, img_right));
}

TEST_CASE("Preprocessing find_contour_lines 1.") {
    cv::Mat img = cv::imread("test_files/TestPreprocessing_Find_Contour_Lines_1_input.png");
    cv::Mat img_gray = Preprocessing::make_black_white_image(img);
    cv::Mat img_contour = Preprocessing::find_contour_lines(img_gray);
    cv::Mat img_right;
    cv::cvtColor(
            cv::imread("test_files/TestPreprocessing_Find_Contour_Lines_1_output.png"),
            img_right,cv::COLOR_RGB2GRAY);
    REQUIRE(equal(img_contour, img_right));
}

TEST_CASE("Preprocessing find_contour_lines 2.") {
    cv::Mat img = cv::imread("test_files/TestPreprocessing_Find_Contour_Lines_2_input.png");
    cv::Mat img_gray = Preprocessing::make_black_white_image(img);
    cv::Mat img_contour = Preprocessing::find_contour_lines(img_gray);
    cv::Mat img_right;
    cv::cvtColor(
            cv::imread("test_files/TestPreprocessing_Find_Contour_Lines_2_output.png"),
            img_right,cv::COLOR_RGB2GRAY);
    REQUIRE(equal(img_contour, img_right));
}

TEST_CASE("Preprocessing find_contour_lines 3.") {
    cv::Mat img = cv::imread("test_files/TestPreprocessing_Find_Contour_Lines_3_input.png");
    cv::Mat img_gray = Preprocessing::make_black_white_image(img);
    cv::Mat img_contour = Preprocessing::find_contour_lines(img_gray);
    cv::Mat img_right;
    cv::cvtColor(
            cv::imread("test_files/TestPreprocessing_Find_Contour_Lines_3_output.png"),
            img_right,cv::COLOR_RGB2GRAY);
    REQUIRE(equal(img_contour, img_right));
}

TEST_CASE("Preprocessing find_contour_lines 4.") {
    cv::Mat img = cv::imread("test_files/TestPreprocessing_Find_Contour_Lines_4_input.png");
    cv::Mat img_gray = Preprocessing::make_black_white_image(img);
    cv::Mat img_contour = Preprocessing::find_contour_lines(img_gray);
    cv::Mat img_right;
    cv::cvtColor(
            cv::imread("test_files/TestPreprocessing_Find_Contour_Lines_4_output.png"),
            img_right,cv::COLOR_RGB2GRAY);
    REQUIRE(equal(img_contour, img_right));
}


TEST_CASE("Preprocessing blur_contour_lines 1.") {
    cv::Mat img = cv::imread("test_files/TestPreprocessing_Blur_Contour_Lines_1_input.png");
    cv::Mat img_gray = Preprocessing::make_black_white_image(img);
    cv::Mat img_contour = Preprocessing::find_contour_lines(img_gray);
    cv::Mat img_blured_contour = Preprocessing::blur_contour_lines(img_contour);
    cv::Mat img_right;
    cv::cvtColor(
            cv::imread("test_files/TestPreprocessing_Blur_Contour_Lines_1_output.png"),
            img_right,cv::COLOR_RGB2GRAY);
    REQUIRE(equal(img_blured_contour, img_right));
}