#include<opencv2/opencv.hpp>
#include<iostream>
#include<vector>
#include<cmath>

using namespace cv;
using namespace std;

struct colors {
	int color_type;
	double time;
};

 bool my_compare(colors c1, colors c2)
{
	 return c1.color_type < c2.color_type;
}

int main()
{
	Mat src = imread("dark.jpg", cv::IMREAD_GRAYSCALE);	// ¦Ç¶¥¹Ï
	Mat src2 = imread("target.jpg", cv::IMREAD_GRAYSCALE);	// ¦Ç¶¥¹Ï
	Mat dst = Mat::zeros(src.rows, src.cols, CV_8UC1);
	Mat matching_dst = Mat::zeros(src.rows, src.cols, CV_8UC1);
	// Filling your code here

	vector<colors> pic_color;
	vector<colors> pic_color2;

	int rows = src.rows;
	int cols = src.cols;
	int channel = src.channels();

	// 1
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int color = src.at<uchar>(i, j);
			bool find = 0;
			for (int c = 0; c < pic_color.size(); c++)
			{
				if (color == pic_color[c].color_type)
				{
					find = 1;
					pic_color[c].time += 1;
					break;
				}
			}
			if (find == 0)
			{
				colors new_c;
				new_c.color_type = color;
				new_c.time = 1;
				pic_color.push_back(new_c);
			}
		}
	}

	// 2
	for (int i = 0; i < src2.rows; i++)
	{
		for (int j = 0; j < src2.cols; j++)
		{
			int color = src2.at<uchar>(i, j);
			bool find = 0;
			for (int c = 0; c < pic_color2.size(); c++)
			{
				if (color == pic_color2[c].color_type)
				{
					find = 1;
					pic_color2[c].time += 1;
					break;
				}
			}
			if (find == 0)
			{
				colors new_c;
				new_c.color_type = color;
				new_c.time = 1;
				pic_color2.push_back(new_c);
			}
		}
	}

	
	for (int c = 0; c < pic_color.size(); c++)
	{
		pic_color[c].time = pic_color[c].time / (rows * cols);
	}

	for (int c = 0; c < pic_color2.size(); c++)
	{
		pic_color2[c].time = pic_color2[c].time / (src2.rows * src2.cols);
	}

	sort(pic_color.begin(), pic_color.end(), my_compare);
	sort(pic_color2.begin(), pic_color2.end(), my_compare);

	vector <double> cdf;
	vector <double> cdf2;
	vector <int> new_color;

	double sum = 0;
	double sum2 = 0;

	for (int c = 0; c < pic_color.size(); c++)
	{
		sum += pic_color[c].time;
		cdf.push_back(sum);
	}

	for (int c = 0; c < pic_color2.size(); c++)
	{
		sum2 += pic_color2[c].time;
		cdf2.push_back(sum2);
	}

	for (int c = 0; c < pic_color.size(); c++)
	{
		new_color.push_back(round(cdf[c] * (255)));
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int color = src.at<uchar>(i, j);
			for (int c = 0; c < pic_color.size(); c++)
			{
				if (color == pic_color[c].color_type)
				{
					dst.at<uchar>(i, j) = new_color[c];
					break;
				}
			}
		}
	}

	// HW2

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int color = src.at<uchar>(i, j);
			int place = 0;
			for (int c = 0; c < pic_color.size(); c++)
			{
				if (color == pic_color[c].color_type)
				{
					place = c;
					break;
				}
			}
			int new_place = 0;
			for (int k = 0; k < cdf2.size(); k++)
			{
				if (cdf[place] <= cdf2[k])
				{
					new_place = k;
					break;
				}
			}
			matching_dst.at<uchar>(i, j) = pic_color2[new_place].color_type;
		}
	}


	imshow("src", src);
	imshow("dst", dst);
	imshow("src2", src2);
	imshow("matching_dst", matching_dst);
	waitKey();
}