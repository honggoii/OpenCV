#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void on_trackbar(int pos, void* userdata) {
	Mat src = *(Mat*)userdata;

	int blocksize = pos;
	if (blocksize % 2 == 0)
		blocksize--; // blocksize is possible when odd
	if (blocksize < 3)
		blocksize = 3; // blocksize minimum size

	Mat dst;
	adaptiveThreshold(src, dst, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, blocksize, 5);
	// threshold = gaussian average - 5

	imshow("dst", dst);
}

int main() {
	Mat src = imread("sudoku.jpg", IMREAD_GRAYSCALE);
	imshow("src", src);
	namedWindow("dst");
	createTrackbar("Block Size", "dst", 0, 200, on_trackbar, (void*)&src);
	waitKey();
	return 0;
}