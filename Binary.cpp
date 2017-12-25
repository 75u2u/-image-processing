#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char* argv[]) {

	Mat img = imread("input.jpg");
	if (img.empty()) return -1;
	Mat gray_img;
	//3×3の行列で要素はすべて1
	Mat element = Mat::ones(3, 3, CV_8UC1);
	
	//グレースケール化
	cvtColor(img, gray_img, CV_BGR2GRAY);

	Mat bin_img;
	//閾値設定
	threshold(gray_img, bin_img, 127, 255, THRESH_BINARY);

	//bin_img = ~bin_img; //反転
	
	//最後の引数で膨張処理回数を設定
	dilate(bin_img, bin_img, element, Point(-1, -1), 0);
	//画像表示
	namedWindow("result", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);
	imshow("result", bin_img);

	waitKey(0);
	return 0;
}
