#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat calcGrayHist(const Mat& img);
Mat getGrayHistImage(const Mat& hist);

int main() {
	Mat src = imread("hawkes.bmp", IMREAD_GRAYSCALE);

	Mat dst;
	equalizeHist(src, dst);

	imshow("src", src);
	imshow("srcHist", getGrayHistImage(calcGrayHist(src)));

	imshow("dst", dst);
	imshow("dstHist", getGrayHistImage(calcGrayHist(dst)));
	waitKey();
	return 0;
}

Mat calcGrayHist(const Mat& img)
{
	CV_Assert(img.type() == CV_8UC1);

	/* calc histogram */
	Mat hist;
	int channels[] = { 0 }; // grayscale
	int dims = 1; // 1차원
	const int histSize[] = { 256 }; // 256개의 빈
	float graylevel[] = { 0,256 }; // 0~255
	const float* ranges[] = { graylevel };

	calcHist(&img, 1, channels, noArray(), hist, dims, histSize, ranges);

	return hist;
}

Mat getGrayHistImage(const Mat& hist)
{
	CV_Assert(hist.type() == CV_32FC1);
	CV_Assert(hist.size() == Size(1, 256));

	/* draw histogram */
	double histMax;
	minMaxLoc(hist, 0, &histMax); // 계산한 hist 행렬에서 최대값을 histMax에 저장

	Mat imgHist(100, 256, CV_8UC1, Scalar(255)); // 흰색으로 초기화한 256x100 크기의 영상 생성
	for (int i = 0; i < 256; i++) {
		line(imgHist, Point(i, 100),
			Point(i, 100 - cvRound(hist.at<float>(i, 0) * 100 / histMax)), Scalar(0));
	}

	return imgHist;
}