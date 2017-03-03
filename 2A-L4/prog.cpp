#include "opencv2/opencv.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv/cv.h"
#include <bits/stdc++.h>

using namespace std;
using namespace cv;

int main()
{
  Mat img=imread("../where_is_waldo.jpg");
  Mat t=imread("../waldo.jpg");

  Mat dst;
  int result_cols=img.cols-t.cols+1;
  int result_rows=img.rows-t.rows+1;
  dst.create(result_rows,result_cols,CV_32FC1);

  matchTemplate(img,t,dst,CV_TM_CCORR_NORMED);

  imshow("waldo",dst);
  waitKey(0);
}
