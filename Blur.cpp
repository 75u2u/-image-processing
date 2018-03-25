#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char* argv[]) {
	Mat img = imread("input.jpg");
	
	blur(img, img, Size(3, 3));
	
	namedWindow("result", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);
	imshow("result", img);
	
	waitKey(0);
	return 0;
}
