#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void on_threshold(int pos, void* userdata) {
	Mat src = *(Mat*)userdata;

	Mat dst;
	threshold(src, dst, pos, 255, THRESH_BINARY);

	imshow("dst", dst);
}

int main(int argc, char* argv[]) {
	Mat src;

	src = imread("neutrophils.png", IMREAD_GRAYSCALE);

	imshow("src", src);

	namedWindow("dst");
	createTrackbar("Threshold", "dst", 0, 255, on_threshold, (void*)&src);
	
	waitKey();
	return 0;
}