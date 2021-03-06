#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
 
Mat src, gray_src, dst;
int t1_value = 50;
int max_value = 255;
const char* OUTPUT_TITLE = "Canny Result";
void Canny_Demo(int, void*);
 
 
int main()
{
	
	 src = imread("../Downloads/01.jpg");
	if (!src.data) {
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("input image", CV_WINDOW_AUTOSIZE);
	imshow("input image", src);
 
	namedWindow("canny", CV_WINDOW_AUTOSIZE);
	cvtColor(src, gray_src, CV_BGR2GRAY);
	createTrackbar("Threshold Value:", "canny", &t1_value, max_value, Canny_Demo);
	
	Canny_Demo(0, 0);
	
 
	waitKey(0);
	return 0;
}
 
void Canny_Demo(int, void*)
{
	Mat edge_output;
	blur(gray_src, gray_src, Size(3, 3), Point(-1, -1), BORDER_DEFAULT);
	Canny(gray_src, edge_output, t1_value, t1_value * 2, 3, false);
 
//	dst.create(src.size(), src.type());
//	src.copyTo(dst, edge_output);
	imshow("canny", edge_output);
	
	
	return ;
}
