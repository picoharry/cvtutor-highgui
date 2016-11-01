// CVTutor.HighGUI.Trackbar01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

const int alpha_slider_max = 100;
int alpha_slider;
double alpha;
double beta;

Mat src1;
Mat src2;
Mat dst;


void on_trackbar(int, void*);

int main(int argc, char** argv)
{
	//src1 = imread("../../sample-data/LinuxLogo.jpg");
	//src2 = imread("../../sample-data/WindowsLogo.jpg");
	src1 = imread("../../sample-data/pic2.png");
	src2 = imread("../../sample-data/pic3.png");

	if (!src1.data) 
	{ 
		printf("Error loading src1 \n"); 
		system("pause");
		return -1;
	}
	if (!src2.data) 
	{ 
		printf("Error loading src2 \n");
		system("pause");
		return -1;
	}

	alpha_slider = 0;

	namedWindow("Linear Blend", 1);

	char TrackbarName[50];
	sprintf(TrackbarName, "Alpha x %d", alpha_slider_max);

	createTrackbar(TrackbarName, "Linear Blend", &alpha_slider, alpha_slider_max, on_trackbar);

	on_trackbar(alpha_slider, 0);

	waitKey(0);
	return 0;
}

void on_trackbar(int, void*)
{
	alpha = (double)alpha_slider / alpha_slider_max;
	beta = (1.0 - alpha);

	addWeighted(src1, alpha, src2, beta, 0.0, dst);

	imshow("Linear Blend", dst);
}
