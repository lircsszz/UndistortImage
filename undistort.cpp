#include <opencv2/highgui/highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include "undistort.h"
#include <iostream>

using namespace cv;
using namespace std;

void UndistortImages::loadImage()
{
	UndistortImages::src1=imread("1.png");
	UndistortImages::src2=imread("2.png");
	UndistortImages::src3=imread("3.png");
	UndistortImages::src4=imread("4.png");
	src_vec.push_back(src1);
	src_vec.push_back(src2);
	src_vec.push_back(src3);
	src_vec.push_back(src4);
	dst_vec.push_back(dst1);
	dst_vec.push_back(dst2);
	dst_vec.push_back(dst3);
	dst_vec.push_back(dst4);
	cout<<" load src success! "<<endl;
}

void UndistortImages::loadParameters()
{
	FileStorage fs("c:\\xrayA.xml",cv::FileStorage::READ);
	if(!fs.isOpened()) {
		cerr<<"Failed to open CamMatrix"<<endl;
		system("pause");
		exit(EXIT_FAILURE);
	}
	fs["camera_matrix"]>>matrix;
	fs["distortion_coefficients"]>>coeff;
	cout<<"Matrix"<<matrix<<std::endl;
	cout<<"Coeff"<<coeff<<std::endl;
	cout<<" load parameters success! "<<endl;
}

void UndistortImages::undistortImages()
{
	for(int i=0;i<4;i++)
	{
		undistort(src_vec[i],dst_vec[i],matrix,coeff,new_matrix);
		cv::imshow("src_img",src_vec[i]);
		cv::imshow("dst_img",dst_vec[i]);
		cv::waitKey();
		cv::imwrite("dst.png",dst_vec[i]);
	}
		
		cout<<"undistort success!"<<endl;
}
	