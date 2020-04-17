#include <iostream>
#include <opencv2/opencv.hpp>

cv::Mat bgr2gray(cv::Mat src)
{
	int chans = src.channels();
	cv::Mat gray;
	if (chans > 1)
		cvtColor(src, gray, cv::ColorConversionCodes::COLOR_BGR2GRAY);
	else
		src.copyTo(gray);
	return gray;
}

void sobel_detect(cv::Mat src, cv::Mat& dst)
{
	cv::Mat in_src = bgr2gray(src);
	int rows = src.rows, cols = src.cols;

	for (int r = 1; r < rows - 1; ++r)
		for (int c = 1; c < cols - 1; ++c)
		{
			float Gx = in_src.at<uchar>(r - 1, c + 1) + 2 * in_src.at<uchar>(r, c + 1) + in_src.at<uchar>(r + 1, c + 1) -
				(in_src.at<uchar>(r - 1, c - 1) + 2 * in_src.at<uchar>(r, c - 1) + in_src.at<uchar>(r + 1, c - 1));
			float Gy = in_src.at<uchar>(r - 1, c - 1) + 2 * in_src.at<uchar>(r - 1, c) + in_src.at<uchar>(r - 1, c + 1) -
				(in_src.at<uchar>(r + 1, c - 1) + 2 * in_src.at<uchar>(r + 1, c) + in_src.at<uchar>(r + 1, c + 1));
			float G = sqrt(Gx * Gx + Gy * Gy);
			if (G > 255)
				dst.at<uchar>(r, c) = 255;
			else
				dst.at<uchar>(r, c) = G;
		}
}
int main()
{
	cv::Mat src = cv::imread("test2.jpg");
	cv::Mat dst(src.rows, src.cols, CV_8UC1);
	sobel_detect(src, dst);
	cv::imshow("输出1.jpg", dst);
	cv::imwrite("输出2.jpg", dst);
	cv::waitKey(0);
	return 0;
}