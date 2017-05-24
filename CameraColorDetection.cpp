#include "opencv2\opencv.hpp"
#include "Labeling.h"

#define RS 150	//��臒l�n��
#define RE 180	//��臒l�I���
#define BS 90	//��臒l�n��
#define BE 110	//��臒l�I���
#define GS 40	//��臒l�n��
#define GE 80	//��臒l�I���
#define YS 10	//���F臒l�n��
#define YE 60	//���F臒l�I���

using namespace cv;

int main(int argc, char* argv[]){
    // �J�����f���ݒ�
	VideoCapture cap(0);  //�J�����̃L���v�`��
	if (!cap.isOpened()) return -1;  // �L���v�`�����s���̃G���[����
	// �摜�I�u�W�F�N�g�̍쐬
	Mat im, hsv, r;
	
	//�J��������Î~����擾
	cap >> im;
	const int h = im.rows;	//height
	const int w = im.cols;	//width
	
	// ���x�����O�֘A�̕ϐ�
	LabelingBS labeling; //�ϐ��錾
	RegionInfoBS *ri1;   //ri�ɂ��ꂼ��̈���m��
	RegionInfoBS *ri2;
	RegionInfoBS *ri3;
	RegionInfoBS *ri4;
	RegionInfoBS *ri5;
	short *mask1 = new short[w * h];  //���x�����O�o�͐�

	//���C������
	while (1){
		cap >> im;	// �J��������摜���擾
		cvtColor(im, hsv, CV_BGR2HSV);	// �摜��RGB����HSV�ɕϊ�
		inRange(hsv, Scalar(BS, 70, 70), Scalar(BE, 255, 255), r);  //臒l��ݒ肵r�Ƀ}�X�N�Ƃ��Ċi�[

		// ���̈悪�����ꍇ�̃G���[����
		rectangle(r, Point(0,0), Point(1, 1), Scalar(255),-1);
		rectangle(r, Point(5,0), Point(5, 0), Scalar(255),-1);
		rectangle(r, Point(10,0), Point(10, 0), Scalar(255),-1);
		rectangle(r, Point(15,0), Point(15, 0), Scalar(255),-1);
		rectangle(r, Point(20,0), Point(20, 0), Scalar(255),-1);

		//���x�����O����
		labeling.Exec((uchar *)r.data, mask1, w, h, true, 30);
		ri1 = labeling.GetResultRegionInfo(0);
		ri2 = labeling.GetResultRegionInfo(1);
		ri3 = labeling.GetResultRegionInfo(2);
		ri4 = labeling.GetResultRegionInfo(3);
		ri5 = labeling.GetResultRegionInfo(4);

		//�e���x�����O���S���W�����߉~�ň͂�
		int x1, y1, x2, y2, x3, x4, y3, y4, x5, y5, x6, y6,x7, y7, x8, y8,x9,y9,x10,y10;
		ri1->GetMin(x1, y1);
		ri1->GetMax(x2, y2);
		circle(im, Point((x2+x1)/2, (y1+y2)/2), 10, Scalar(200,0,0), 11, 4);

		
		ri2->GetMin(x3, y3);
		ri2->GetMax(x4, y4);
		circle(im, Point((x3+x4)/2, (y3+y4)/2), 10, Scalar(200,0,0), 11, 4);

		ri3->GetMin(x5, y5);
		ri3->GetMax(x6, y6);
		circle(im, Point((x5+x6)/2, (y5+y6)/2), 10, Scalar(200,0,0), 11, 4);

		ri4->GetMin(x7, y7);
		ri4->GetMax(x8, y8);
		circle(im, Point((x7+x8)/2, (y7+y8)/2), 10, Scalar(200,0,0), 11, 4);
		int s=labeling.GetNumOfRegions();

		ri5->GetMin(x9, y9);
		ri5->GetMax(x10, y10);
		circle(im, Point((x9+x10)/2, (y9+y10)/2), 10, Scalar(200,0,0), 11, 4);
		
		//�f���\��
		imshow("Camera", im);   // �J�����f���̕\��
		imshow("Mask", r);		// �}�X�N�摜�̍쐬
		if (waitKey(30) >= 0){	// �C�ӂ̃L�[���͂�����ΏI��
			break;
		}
	}
	return 0;
}