#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	if (src.empty()) {
		cerr << "Image load failed!" << endl;
		return 0;
	}

	imshow("src", src);

	for (int stddev = 10; stddev <= 30; stddev += 10) {
		Mat noise(src.size(), CV_32SC1);
		randn(noise, 0, stddev);

		Mat dst;
		add(src, noise, dst, Mat(), CV_8U);

		String desc = format("stddev = %d", stddev);
		putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0,
			Scalar(255), 1, LINE_AA);
		imshow("dst", dst);
		waitKey();
	}

	return 0;
}