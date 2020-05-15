#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	Mat dst(src.rows, src.cols, src.type());

	for (int j = 0; j < src.rows; j++) {
		for (int i = 0; i < src.cols; i++) {
			// 255�� ������ ����� �����÷ο찡�Ǿ� 0���� �ٽ� ���۵Ǵ� �ڵ�
			//dst.at<uchar>(j, i) = src.at<uchar>(j, i) + 100;
			//dst.at<uchar>(j, i) = saturate_cast<uchar>(src.at<uchar>(j, i) + 100) 
			
			int v = src.at<uchar>(j, i) + 100;
			dst.at<uchar>(j, i) = v > 255 ? 255 : v < 0 ? 0 : v;
			// v�� 255�� ������ 255
			// v�� 255�� ���������� 0���� ������ �˻� �� ������ 0
			// v�� 255�� �����ʰ� 0���ٵ� ũ�� v�� �״�� ���
		}
	}

	imshow("src", src);
	imshow("dst", dst);
	waitKey();
	return 0;
}