#include "opencv2/opencv.hpp"

using namespace cv;

int main(int argc, char* argv[])
{
	// 画像の取得
	Mat im = imread("input.jpg");
	// 出力画像
	Mat result;

	// ガンマ値
	float gamma = 1.0;

	//　ルックアップテーブル作成
	uchar lut[256];
	double gm = 1.0 / gamma;
	for (int i = 0; i < 256; i++)
		lut[i] = pow(1.0*i / 255, gm) * 255;
	
	// 輝度値の置き換え処理
	 LUT(im, Mat(Size(256, 1), CV_8U, lut), result);

	// 元画像の表示
	imshow("original", im);
	// 結果画像の表示
	imshow("result", result);

	waitKey(0);
	return 0;
}
