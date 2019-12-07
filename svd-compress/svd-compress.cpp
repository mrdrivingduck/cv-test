// ************************************************************************************
//
// The project of the course Matrix Theory
//
// Author: mrdrivingduck @Nanjing
//
// Reference: https://www.cnblogs.com/didea/p/6044321.html
// Config: https://blog.csdn.net/kiripeng/article/details/89099675
//
// ************************************************************************************

#include <iostream>
#include <string>
#include <sstream>
#include <opencv2/opencv.hpp>

using namespace cv;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

//
// For compressing
//
void SVD_Compress(const cv::Mat& inputImg, cv::Mat& U, cv::Mat& W, cv::Mat& Vt)
{
	cv::Mat input;
	inputImg.convertTo(input, CV_32FC1);
	cv::SVD::compute(input, W, U, Vt);

	cout << W << endl;
}

void display(cv::Mat& U, cv::Mat& W, cv::Mat& Vt, double compressRatio) {
	// W is a one-dimension vector which contains the singular values
	// initialize a new 0-empty matrix of W
	cv::Mat w = Mat::zeros(Size(W.rows, W.rows), CV_32FC1);
	cv::Mat output;

	int len = compressRatio * W.rows;
	for (int i = 0; i < len; i++) {
		// copy the diagonal element from W to w
		// only the pre-length element will be copied
		w.ptr<float>(i)[i] = W.ptr<float>(i)[0];
	}

	// form the image again using the compressed matrix
	cv::Mat result = U * w * Vt;
	result.convertTo(output, CV_8UC1);

	stringstream ss;
	ss << compressRatio;
	cv::imshow("compressed " + ss.str(), output);
	waitKey(0);
}

int main()
{
	// source image
	string img("imgs/duck.jpg");
	cv::Mat source = imread(img, 0);
	cv::Mat origin = imread(img, 0);

	cv::Mat U;
	cv::Mat Vt;
	cv::Mat W;
	SVD_Compress(source, U, W, Vt);

	// ratios
	double ratios[] = { 0.9, 0.5, 0.3, 0.2, 0.15, 0.1, 0.05, 0.02 };
	// compressing
	for (int i = 0; i < sizeof(ratios) / sizeof(ratios[0]); i++) {
		display(U, W, Vt, ratios[i]);
	}

	// origin image
	cv::imshow("origin", origin);
	waitKey(0);
}

