#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// ��� �ִ밪�� ��ȯ�ϴ� �Լ�
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

    cout << "�̹����� �ִ� ��Ⱚ: " << maxIntensity << endl;

    return 0;
}
