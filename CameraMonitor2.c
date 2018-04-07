#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;

int main(int argc, char *argv[]) {

	VideoCapture cap(0);

	if (!cap.isOpened()) return -1;

	Mat input_image;
	namedWindow("monitor", 1);

	while (1) {
		Mat frame;
		cap >> frame;
		input_image = frame;
		imshow("monitor", input_image);
		if (waitKey(30) >= 0) break;
	}
	return 0;
}