#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat src = imread("../image/pepper.bmp");

	Mat src_ycrcb;
	cvtColor(src, src_ycrcb, COLOR_BGR2YCrCb);	// BRG->YCrCb 후 src_ycrcb에 저장

	vector<Mat> ycrcb_planes;
	split(src_ycrcb, ycrcb_planes);	// 채널 분리

	equalizeHist(ycrcb_planes[0], ycrcb_planes[0]); 

	Mat dst_ycrcb;
	merge(ycrcb_planes, dst_ycrcb);	// 분리한 채널 병합

	Mat dst;
	cvtColor(dst_ycrcb, dst, COLOR_YCrCb2BGR); // YCrCb->BGR 후 dst에 저장

	imshow("src", src);
	imshow("dst", dst);



	waitKey();
	return 0;
}