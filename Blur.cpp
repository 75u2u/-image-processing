#include "opencv2/opencv.hpp"

using namespace cv;

int main(void)
{
	Mat im = imread("csharptan.png");    // �摜�̎擾
	blur(im, im, Size(3, 3));        // �ڂ����t�B���^
	imshow("Show image", im);	    // �摜�̕\��
	waitKey(0);                     // ���͑ҋ@
	return 0;
}
