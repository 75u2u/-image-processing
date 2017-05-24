#include "opencv2/opencv.hpp"

using namespace cv;

int main(int argc, char* argv[])
{
	// 画像の取得
	Mat im = imread("input.jpg");
	// 出力画像
	Mat result;
	// ルックアップテーブル作成
	float a = 20.0; // 入力パラメータ
	uchar lut[256];
	for (int i = 0; i < 256; i++)
		lut[i] = 255.0 / (1 + exp(-a*(i - 128) / 255)); //シグモイド関数

	// 輝度値の置き換え処理
	LUT(im, Mat(Size(256, 1), CV_8U, lut), result);

	// 元画像の表示
	imshow("original", im);
	// 結果画像の表示
	imshow("result", result);

	waitKey(0);
	return 0;
}
