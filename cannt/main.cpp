#include<iostream>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	VideoCapture cap(0);
	double scale = 0.5;

	while (1) {
		Mat frame;
		Mat hsvMat;
		Mat detectMat;
		cap >> frame;
		Mat fframe;
		Mat dx;
		Mat dy;
		Mat output1;
		Mat output2;
		Sobel(frame, dx, CV_16SC1, 1, 0, 3);
		Sobel(frame, dy, CV_16SC1, 0, 1, 3);
		Canny(dx, dy, output1, 20, 60);
		cvtColor(frame, hsvMat, CV_BGR2GRAY);
		Canny(hsvMat, output2, 30, 90);
		imshow("p1", output1);
		imshow("p2", output2);
		waitKey(30);
	}
}