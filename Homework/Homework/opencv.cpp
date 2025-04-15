#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
	cv::Mat image = cv::imread("Lenna.png", cv::IMREAD_GRAYSCALE);
	cv::imshow("lenna window", image);
	cv::waitKey(0);
}