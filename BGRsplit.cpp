#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Mat src = imread("candies.png"); // �÷��������� �ҷ���

	vector<Mat> bgr_planes; // Mat �ڷ����� vector ����
	split(src, bgr_planes); // �Է� ���� �и��ؼ� vecotr�� ����
	
	Mat dst;
	merge(bgr_planes, dst); // �и��� ���� ��ġ��

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