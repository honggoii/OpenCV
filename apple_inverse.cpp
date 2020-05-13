#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("../image/apple.jpg", IMREAD_COLOR);

	//Mat dst(src.rows, src.cols, src.type());
	Mat dst = Scalar(255, 255, 255) - src;
	/*for (int j = 0; j < src.rows; j++) {
		for (int i = 0; i < src.cols; i++) {
			Vec3b& p1 = src.at<Vec3b>(j, i);
			Vec3b& p2 = src.at<Vec3b>(j, i);

			p2[0] = 255 - p1[0];
			p2[1] = 255 - p1[1];
			p2[2] = 255 - p1[2];
		}
	}*/

	imshow("src", src);
	imshow("dst", dst);
	waitKey();

	return 0;
}