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
#include <opencv2/opencv.hpp>

using namespace cv;
using std::cout;
using std::endl;
using std::string;

//
// For compressing
//
void SVD_Compress(const cv::Mat& inputImg, cv::Mat& outputImg, double compressRatio)
{
	cv::Mat input;
	cv::Mat U, W, V;
	inputImg.convertTo(input, CV_32FC1);
	cv::SVD::compute(input, W, U, V);

	// W is a one-dimension vector which contains the singular values
	// initialize a new 0-empty matrix of W
	cv::Mat w = Mat::zeros(Size(W.rows, W.rows), CV_32FC1);

	int len = compressRatio * W.rows;
	for (int i = 0; i < len; i++) {
		// copy the diagonal element from W to w
		// only the pre-length element will be copied
		w.ptr<float>(i)[i] = W.ptr<float>(i)[0];
	}

	cout << W << endl;

	// form the image again using the compressed matrix
	cv::Mat result = U * w * V;
	result.convertTo(outputImg, CV_8UC1);
}

int main()
{
	string img("imgs/self.jpg");
	// source image
	cv::Mat source = imread(img, 0);
	cv::Mat origin = imread(img, 0);
	// result image
	cv::Mat result;

	// compressing
	SVD_Compress(source, result, 0.1);

	cv::imshow("origin", origin);
	cv::imshow("compressed", result);
	waitKey(0);
}

