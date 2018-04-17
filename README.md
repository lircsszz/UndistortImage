# UndistortImage
Usage:Using this project to undistort images, compensating for lens distortion.
I have used an undistortImage class to encapsulate related member variables and methods. Use the loadImage function to load distorted images, and then use the loadParameters function to load camera inner matrix and distortion coefficients matrix, finally using the undistortImage function to call OpenCV undistort function.
