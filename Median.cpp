#include "opencv2/opencv.hpp"

using namespace cv;

int main(void)
{
	Mat im = imread("sparrow.png");    // �摜�̎擾
	medianBlur(im, im, 7);          // ���f�B�A���t�B���^
	imshow("Show image", im);       // �摜�̕\��
	waitKey(0);                     // ���͑ҋ@
	return 0;
}
