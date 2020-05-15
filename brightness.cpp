#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	Mat dst(src.rows, src.cols, src.type());

	for (int j = 0; j < src.rows; j++) {
		for (int i = 0; i < src.cols; i++) {
			// 255의 범위를 벗어나면 오버플로우가되어 0부터 다시 시작되는 코드
			//dst.at<uchar>(j, i) = src.at<uchar>(j, i) + 100;
			//dst.at<uchar>(j, i) = saturate_cast<uchar>(src.at<uchar>(j, i) + 100) 
			
			int v = src.at<uchar>(j, i) + 100;
			dst.at<uchar>(j, i) = v > 255 ? 255 : v < 0 ? 0 : v;
			// v가 255를 넘으면 255
			// v가 255를 넘지않으면 0보다 작은지 검사 후 작으면 0
			// v가 255를 넘지않고 0보다도 크면 v값 그대로 사용
		}
	}

	imshow("src", src);
	imshow("dst", dst);
	waitKey();
	return 0;
}