#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int main(int argc, char *argv[])
{
	// �ϐ��錾
	Mat im;
	// �J�����̃L���v�`��
	VideoCapture cap(0);
	// �L���v�`���̃G���[����
	if (!cap.isOpened()) return -1;

	while (1) {
		// �J�����f���̎擾
		cap >> im;
		// �f���̕\��
		imshow("Camera", im);
		// �L�[���͂�����ΏI��
		if (waitKey(30) >= 0) break;
	}
	return 0;
}