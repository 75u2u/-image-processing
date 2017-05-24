#include "opencv2/opencv.hpp"

using namespace cv;

int main(int argc, char* argv[])
{
	// �摜�̎擾
	Mat im = imread("input.jpg");
	// �o�͉摜
	Mat result;

	// �K���}�l
	float gamma = 1.0;

	//�@���b�N�A�b�v�e�[�u���쐬
	uchar lut[256];
	double gm = 1.0 / gamma;
	for (int i = 0; i < 256; i++)
		lut[i] = pow(1.0*i / 255, gm) * 255;
	
	// �P�x�l�̒u����������
	 LUT(im, Mat(Size(256, 1), CV_8U, lut), result);

	// ���摜�̕\��
	imshow("original", im);
	// ���ʉ摜�̕\��
	imshow("result", result);

	waitKey(0);
	return 0;
}
