#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// 밝기 최대값을 반환하는 함수
int findMaxIntensity(const Mat& grayImg)
{
    int maxVal = 0;

    for (int i = 0; i < grayImg.rows; i++)
    {
        for (int j = 0; j < grayImg.cols; j++)
        {
            int pixel = grayImg.at<uchar>(i, j);
            if (pixel > maxVal)
            {
                maxVal = pixel;
            }
        }
    }
    return maxVal;
}

int main() {
    Mat img = imread("Lenna.png", IMREAD_GRAYSCALE);
    int maxIntensity = findMaxIntensity(img);

    cout << "이미지의 최대 밝기값: " << maxIntensity << endl;

    return 0;
}
