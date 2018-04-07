#include <opencv/cv.h>
#include <opencv/highgui.h>


void Trackbar(int val);

IplImage* img;
IplImage* originalimg;

int main(int argc, char *argv[]) {

	char image[] = "input.jpg";
	img = cvLoadImage(image, CV_LOAD_IMAGE_COLOR);
	originalimg = cvLoadImage(image, CV_LOAD_IMAGE_COLOR);

	cvNamedWindow("RGBchanger", CV_WINDOW_AUTOSIZE);
	cvShowImage("RGBchanger", img);
	cvCreateTrackbar("Move it", "RGBchanger", 0, 1000, Trackbar);
	cvWaitKey(0);
	cvDestroyWindow("RGBchanger");
	cvReleaseImage(&img);

	return 0;
}

uchar p[3];
int x, y;

void Trackbar(int val) {
	int val2 = val * 2;

	for (y = 0; y < img->height; y++) {
		for (x = 0; x < img->width; x++) {
			p[0] = img->imageData[img->widthStep * y + x * 3];        // B
			p[1] = img->imageData[img->widthStep * y + x * 3 + 1];    // G
			p[2] = img->imageData[img->widthStep * y + x * 3 + 2];    // R
			img->imageData[img->widthStep * y + x * 3] = originalimg->imageData[img->widthStep * y + (x + val) * 3];
			img->imageData[img->widthStep * y + x * 3 + 1] = originalimg->imageData[img->widthStep * y + (x + val / 3) * 3 + 1];
			img->imageData[img->widthStep * y + x * 3 + 2] = originalimg->imageData[img->widthStep * y + (x + val / 2) * 3 + 2];
		}
	}
	cvShowImage("RGBchanger", img);
}