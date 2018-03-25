#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

int main(int argc, char* argv[]) {

	const char *imagename = argc > 1 ? argv[1] : "input.jpg";
	Mat img = imread(imagename, 0);
	if (!img.data) return -1;

	Mat tmp_img;
	Mat sobel_img;
	Sobel(img, tmp_img, CV_32F, 1, 1);
	convertScaleAbs(tmp_img, sobel_img, 1, 0);

	Mat laplacian_img;
	Laplacian(img, tmp_img, CV_32F, 3);
	convertScaleAbs(tmp_img, laplacian_img, 1, 0);

	Mat canny_img;
	Canny(img, canny_img, 50, 200);

	namedWindow("Original(Grayscale)", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);
	namedWindow("Sobel", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);
	namedWindow("Laplacian", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);
	namedWindow("Canny", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);
	imshow("Original(Grayscale)", img);
	imshow("Sobel", sobel_img);
	imshow("Laplacian", laplacian_img);
	imshow("Canny", canny_img);
	
	waitKey(0);
	return 0;
}
