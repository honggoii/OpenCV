#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat src, src_ycrcb, mask;
	src = imread("kyeong.jpg");
	mask = imread("mask.jpg",IMREAD_GRAYSCALE);
	cvtColor(src, src_ycrcb, COLOR_BGR2YCrCb); // BGR to YCrCb in src_ycrcb

	Mat hist;
	int channels[] = { 1,2 };
	int histSize[] = { 128,128 };
	float cr_range[] = { 0,256 };
	float cb_range[] = { 0,256 };
	const float* ranges[] = { cr_range,cb_range };
	calcHist(&src_ycrcb, 1, channels, mask, hist, 2, histSize, ranges);

	Mat search, search_ycrcb;
	search = imread("search.jpg");
	cvtColor(search, search_ycrcb, COLOR_BGR2YCrCb);

	Mat backproj;
	calcBackProject(&search_ycrcb, 1, channels, hist, backproj, ranges, 1, true);

	imshow("search", search);
	imshow("backproject", backproj);

	waitKey();
	return 0;
}