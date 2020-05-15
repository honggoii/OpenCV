#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
Mat getGrayHistImage(const Mat& hist);

int main() {
	Mat src = imread("hawkes.bmp", IMREAD_GRAYSCALE);

	/* calc histogram */

	Mat hist; 
	int channels[] = { 0 }; // grayscale
	int dims = 1; // 1����
	const int histSize[] = { 256 }; // 256���� ��
	float graylevel[] = { 0,256 }; // 0~255
	const float* ranges[] = { graylevel };

	calcHist(&src, 1, channels, noArray(), hist, dims, histSize, ranges);

	Mat hist_img = getGrayHistImage(hist);
	
	imshow("src", src);
	imshow("srcHist", hist_img);
	waitKey();
	return 0;
}

Mat getGrayHistImage(const Mat& hist)
{
	CV_Assert(hist.type() == CV_32FC1);
	CV_Assert(hist.size() == Size(1, 256));
	/* draw histogram */
	double histMax;
	minMaxLoc(hist, 0, &histMax); // ����� hist ��Ŀ��� �ִ밪�� histMax�� ����

	Mat imgHist(100, 256, CV_8UC1, Scalar(255)); // ������� �ʱ�ȭ�� 256x100 ũ���� ���� ����
	for (int i = 0; i < 256; i++) {
		line(imgHist, Point(i, 100),
			Point(i, 100 - cvRound(hist.at<float>(i, 0) * 100 / histMax)), Scalar(0));
	}

	return imgHist;
}