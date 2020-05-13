#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat src = imread("../image/pepper.bmp");

	Mat src_ycrcb;
	cvtColor(src, src_ycrcb, COLOR_BGR2YCrCb);	// BRG->YCrCb �� src_ycrcb�� ����

	vector<Mat> ycrcb_planes;
	split(src_ycrcb, ycrcb_planes);	// ä�� �и�

	equalizeHist(ycrcb_planes[0], ycrcb_planes[0]); 

	Mat dst_ycrcb;
	merge(ycrcb_planes, dst_ycrcb);	// �и��� ä�� ����

	Mat dst;
	cvtColor(dst_ycrcb, dst, COLOR_YCrCb2BGR); // YCrCb->BGR �� dst�� ����

	imshow("src", src);
	imshow("dst", dst);



	waitKey();
	return 0;
}