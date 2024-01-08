#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include<iostream>
using namespace std;
using namespace cv;


Mat element(int erosion_size)
{
	return  getStructuringElement(cv::MORPH_ELLIPSE,
		cv::Size(2 * erosion_size + 1, 2 * erosion_size + 1),
		cv::Point(erosion_size, erosion_size));
}


int erode1(Mat eroding, int i, int j)
{

	for (int k = -20; k < 21; k++)
	{
		for (int h = -20; h < 21; h++)
		{
			int color = eroding.at<uchar>(i + k, j + h);
			if (color == 0)
			{
				return 0;
			}

		}
	}

	return 255;
}

int main()
{
	Mat img = imread("image.jpg", IMREAD_GRAYSCALE);
	//img.copyTo(target);
	double scale = 0.2;
	// 圖片太大先縮小
	resize(img, img, Size(0, 0), scale, scale);
	Mat eroding = Mat::zeros(img.rows, img.cols, img.type());
	Mat eroding_new = Mat::zeros(img.rows, img.cols, img.type());


	// do something
	Mat gray;

	for (int i = 0; i < 100; i++)
	{
		blur(img, eroding, Size(3, 3));
	}
	
	//imshow("initial_img11111", eroding);
	threshold(eroding, eroding, 50, 255, THRESH_BINARY_INV);
	int time;
	//imshow("initial_img", eroding);
	int direction = 1;
	for (int k = 0; k < 1; k++)
	{
		for (int i = 20; i < img.rows - 21; i++)
		{
			for (int j = 20; j < img.cols - 21; j++)
			{
				eroding_new.at<uchar>(i, j) = erode1(eroding, i, j);
			}
		}
	}

	
	//imshow("img", img);
	Mat labels;
	int number_labels = connectedComponents(eroding_new, labels);
	cout << "共有: " << number_labels - 1;
	//imshow("img", img);
	imshow("picture_numbers:" + to_string(number_labels - 1), eroding_new);
	//imshow("opening", opening);

	waitKey(0);
}//w("numbers:" + to_string(number_labels - 1), img);
//waitKey(0);
//}