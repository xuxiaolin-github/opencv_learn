#include<opencv2/opencv.hpp>
using namespace cv;
 
String video_path="/home/xuxiaolin/tensorrtx_learn/tensorrtx/yolov5/build/01.avi";
int main(){
      VideoCapture cap;
      cap.open(0); //打开摄像头
  
      if(!cap.isOpened())
          return -1;
 
     Mat frame,src;
     while(1)
     {
         cap>>frame;//等价于cap.read(frame);
         Canny(frame, src, 30, 100);//canny边缘检测，去掉这一行就是纯粹的读取摄像头了
         //cvtColor(frame, frame, CV_BGR2HSV);//BGR空间转为HSV颜色空间，注意，两者不能同时对同一张图片（在此为frame）进行处理，否则报错
         if(frame.empty())
             break;
         imshow("video", frame);
         if(waitKey(50)>0)//按下任意键退出摄像头　　因电脑环境而异，有的电脑可能会出现一闪而过的情况
             break;
     }
     cap.release();
     destroyAllWindows();//关闭所有窗口

     return 0;
 }