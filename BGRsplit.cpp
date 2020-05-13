#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat src = imread("candies.png"); // 컬러영상으로 불러옴

	vector<Mat> bgr_planes; // Mat 자료형의 vector 생성
	split(src, bgr_planes); // 입력 영상 분리해서 vecotr에 넣음
	
	Mat dst;
	merge(bgr_planes, dst); // 분리된 영상 합치기

	imshow("src", src);
	imshow("B_plane", bgr_planes[0]);
	imshow("G_plane", bgr_planes[1]);
	imshow("R_plane", bgr_planes[2]);
	imshow("Merge", dst);

	resizeWindow("src", 350, 350);
	resizeWindow("B_plane", 350, 350);
	resizeWindow("G_plane", 350, 350);
	resizeWindow("R_plane", 350, 350);
	resizeWindow("Merge", 350, 350);
	waitKey();
	return 0;
}