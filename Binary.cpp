#include "opencv2/opencv.hpp"

using namespace cv;

int main(int argc, char* argv[]) {

	Mat img = imread("input.jpg");
	Mat gray_img;
	Mat element = Mat::ones(3, 3, CV_8UC1); //3�~3�̍s��ŗv�f�͂��ׂ�1
	cvtColor(img, gray_img, CV_BGR2GRAY);	//�O���[�X�P�[����

	Mat bin_img;
	threshold(gray_img, bin_img, 127, 255, THRESH_BINARY);	//臒l�ݒ�
	//bin_img = ~bin_img; //���]
	dilate(bin_img, bin_img, element, Point(-1, -1), 0);	//�Ō�̈����Ŗc�������񐔂�ݒ�

	imshow("result", bin_img);

	waitKey(0);
	return 0;
}
