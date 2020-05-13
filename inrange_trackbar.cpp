#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

//int lower_hue = 40, upper_hue = 80;
int lower_hue, upper_hue;
Mat src, src_hsv, mask;

void on_hue_changed(int, void*) {
	Scalar lowerb(lower_hue, 100, 0);
	Scalar upperb(upper_hue, 255, 255);
	inRange(src_hsv, lowerb, upperb, mask);
	// R 160~179
	// G 40~80
	// B 100~140

	imshow("mask", mask);
}

int main(int argc, char* argv[]) {
	src = imread("candies.png");

	cvtColor(src, src_hsv, COLOR_BGR2HSV); // BGR->HSV 후 src_hsv에 저장

	imshow("src", src);

	namedWindow("mask");
	createTrackbar("Lower Hue", "mask", &lower_hue, 179, on_hue_changed);
	createTrackbar("Upper Hue", "mask", &upper_hue, 179, on_hue_changed);
	on_hue_changed(0, 0);

	waitKey();
	return 0;
}