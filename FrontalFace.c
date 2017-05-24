#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int, char**)
{
	cv::VideoCapture cap(0); // �f�t�H���g�J�������I�[�v��
	if (!cap.isOpened())  // �����������ǂ������`�F�b�N
		return -1;
	cv::namedWindow("window1", 1);

	// ���ފ�̓ǂݍ���
	std::string cascadeName = "C:/Program Files/OpenCV/sources/data/haarcascades/haarcascade_frontalface_default.xml";
	cv::CascadeClassifier cascade;
	if (!cascade.load(cascadeName))
		return -1;

	std::vector<cv::Rect> faces;

	while (1)
	{
		cv::Mat frame;
		cv::Mat input_image;
		cv::Mat output_image;
		cap >> frame; // �J��������V�����t���[�����擾
		cvtColor(frame, input_image, CV_BGR2GRAY);//�猟�o�̓O���[��ok
		cv::equalizeHist(input_image, input_image);
		output_image = frame;     //output�̓J���[�ŁD

		//(�摜,�o�͒Z�`,�k���X�P�[��,�Œ�Z�`��,�t���O�H,�ŏ��Z�`)
		cascade.detectMultiScale(input_image, faces,
			1.3, 2,
			CV_HAAR_SCALE_IMAGE,
			cv::Size(50, 50));

		// ���ʂ̕`��
		std::vector<cv::Rect>::const_iterator r = faces.begin();
		for (; r != faces.end(); ++r) {
			cv::Point center;
			int radius;
			center.x = cv::saturate_cast<int>((r->x + r->width*0.5));
			center.y = cv::saturate_cast<int>((r->y + r->height*0.5));
			radius = cv::saturate_cast<int>((r->width + r->height)*0.25);
			cv::circle(output_image, center, radius, cv::Scalar(80, 80, 255), 3, 8, 0);

			printf("faceID%d,x=%d,y=%d,width=%d,height=%d\n", r, r->x, r->y, r->width, r->height); 
		}
		//���ɂ��邽�ߔ��]������
		flip(output_image, output_image, 1);
		imshow("window1", output_image);

		if (cv::waitKey(27) >= 0) break;

	}
	// VideoCapture �f�X�g���N�^�ɂ��C�J�����͎����I�ɏI����������܂�
	return 0;
}