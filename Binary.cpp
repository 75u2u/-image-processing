#include "opencv2/opencv.hpp"

using namespace cv;

int main(int argc, char* argv[]) {

	Mat img = imread("input.jpg");
	Mat gray_img;
	Mat element = Mat::ones(3, 3, CV_8UC1); //3×3の行列で要素はすべて1
	cvtColor(img, gray_img, CV_BGR2GRAY);	//グレースケール化

	Mat bin_img;
	threshold(gray_img, bin_img, 127, 255, THRESH_BINARY);	//閾値設定
	//bin_img = ~bin_img; //反転
	dilate(bin_img, bin_img, element, Point(-1, -1), 0);	//最後の引数で膨張処理回数を設定

	imshow("result", bin_img);

	waitKey(0);
	return 0;
}
