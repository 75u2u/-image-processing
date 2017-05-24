#include "opencv2\opencv.hpp"
#include "Labeling.h"

#define RS 150	//赤閾値始め
#define RE 180	//赤閾値終わり
#define BS 90	//青閾値始め
#define BE 110	//青閾値終わり
#define GS 40	//緑閾値始め
#define GE 80	//緑閾値終わり
#define YS 10	//黄色閾値始め
#define YE 60	//黄色閾値終わり

using namespace cv;

int main(int argc, char* argv[]){
    // カメラ映像設定
	VideoCapture cap(0);  //カメラのキャプチャ
	if (!cap.isOpened()) return -1;  // キャプチャ失敗時のエラー処理
	// 画像オブジェクトの作成
	Mat im, hsv, r;
	
	//カメラから静止画を取得
	cap >> im;
	const int h = im.rows;	//height
	const int w = im.cols;	//width
	
	// ラベリング関連の変数
	LabelingBS labeling; //変数宣言
	RegionInfoBS *ri1;   //riにそれぞれ領域を確保
	RegionInfoBS *ri2;
	RegionInfoBS *ri3;
	RegionInfoBS *ri4;
	RegionInfoBS *ri5;
	short *mask1 = new short[w * h];  //ラベリング出力先

	//メイン処理
	while (1){
		cap >> im;	// カメラから画像を取得
		cvtColor(im, hsv, CV_BGR2HSV);	// 画像をRGBからHSVに変換
		inRange(hsv, Scalar(BS, 70, 70), Scalar(BE, 255, 255), r);  //閾値を設定しrにマスクとして格納

		// 白領域が無い場合のエラー処理
		rectangle(r, Point(0,0), Point(1, 1), Scalar(255),-1);
		rectangle(r, Point(5,0), Point(5, 0), Scalar(255),-1);
		rectangle(r, Point(10,0), Point(10, 0), Scalar(255),-1);
		rectangle(r, Point(15,0), Point(15, 0), Scalar(255),-1);
		rectangle(r, Point(20,0), Point(20, 0), Scalar(255),-1);

		//ラベリング処理
		labeling.Exec((uchar *)r.data, mask1, w, h, true, 30);
		ri1 = labeling.GetResultRegionInfo(0);
		ri2 = labeling.GetResultRegionInfo(1);
		ri3 = labeling.GetResultRegionInfo(2);
		ri4 = labeling.GetResultRegionInfo(3);
		ri5 = labeling.GetResultRegionInfo(4);

		//各ラベリング中心座標を求め円で囲う
		int x1, y1, x2, y2, x3, x4, y3, y4, x5, y5, x6, y6,x7, y7, x8, y8,x9,y9,x10,y10;
		ri1->GetMin(x1, y1);
		ri1->GetMax(x2, y2);
		circle(im, Point((x2+x1)/2, (y1+y2)/2), 10, Scalar(200,0,0), 11, 4);

		
		ri2->GetMin(x3, y3);
		ri2->GetMax(x4, y4);
		circle(im, Point((x3+x4)/2, (y3+y4)/2), 10, Scalar(200,0,0), 11, 4);

		ri3->GetMin(x5, y5);
		ri3->GetMax(x6, y6);
		circle(im, Point((x5+x6)/2, (y5+y6)/2), 10, Scalar(200,0,0), 11, 4);

		ri4->GetMin(x7, y7);
		ri4->GetMax(x8, y8);
		circle(im, Point((x7+x8)/2, (y7+y8)/2), 10, Scalar(200,0,0), 11, 4);
		int s=labeling.GetNumOfRegions();

		ri5->GetMin(x9, y9);
		ri5->GetMax(x10, y10);
		circle(im, Point((x9+x10)/2, (y9+y10)/2), 10, Scalar(200,0,0), 11, 4);
		
		//映像表示
		imshow("Camera", im);   // カメラ映像の表示
		imshow("Mask", r);		// マスク画像の作成
		if (waitKey(30) >= 0){	// 任意のキー入力があれば終了
			break;
		}
	}
	return 0;
}