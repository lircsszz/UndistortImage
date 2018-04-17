
#include "undistort.h"
#include <iostream>
#include <cstdlib>

using namespace cv;
using namespace std;

int main()
{
	UndistortImages undistortImages;
	undistortImages.loadImage();
	undistortImages.loadParameters();
	undistortImages.undistortImages();
	system("pause");
	return 0;
}