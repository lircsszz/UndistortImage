#ifndef _UNDISTORT_H
#define _UNDISTORT_H

#include<opencv2/core/core.hpp>
class UndistortImages{
	private:
	cv::Mat matrix;
	cv::Mat coeff;
	cv::Mat new_matrix;//matrix after undistort
	
	public:
	std::vector<cv::Mat>src_vec;
	std::vector<cv::Mat>dst_vec;
	cv::Mat src1,src2,src3,src4;
	cv::Mat dst1,dst2,dst3,dst4;
	void loadImage();
	void loadParameters();
	void undistortImages();
};

#endif