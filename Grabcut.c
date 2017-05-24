#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;

int main()
{
	// Open another image
	cv::Mat image;
	image = cv::imread("input.jpg");

	// define bounding rectangle 
	cv::Rect rectangle(50, 70, image.cols - 150, image.rows - 180);

	cv::Mat result; // segmentation result (4 possible values)
	cv::Mat bgModel, fgModel; // the models (internally used)

	// GrabCut segmentation
	cv::grabCut(image,    // input image
		result,   // segmentation result
		rectangle,// rectangle containing foreground 
		bgModel, fgModel, // models
		1,        // number of iterations
		cv::GC_INIT_WITH_RECT); // use rectangle
	cout << "じょうずにやけました～" << endl;
	// Get the pixels marked as likely foreground
	cv::compare(result, cv::GC_PR_FGD, result, cv::CMP_EQ);
	// Generate output image
	cv::Mat foreground(image.size(), CV_8UC3, cv::Scalar(255, 255, 255));
	image.copyTo(foreground, result); // bg pixels not copied

	// draw rectangle on original image
	cv::rectangle(image, rectangle, cv::Scalar(255, 255, 255), 1);
	cv::namedWindow("Image");
	cv::imshow("Image", image);

	// display result
	cv::namedWindow("Segmented Image");
	cv::imshow("Segmented Image", foreground);


	cv::waitKey();
	return 0;
}