#include "cvtColor.h"

int convertColorToGray(cv::Mat& src, cv::Mat& dst)
{
  cv::cvtColor(src, dst, CV_BGR2GRAY);
}
