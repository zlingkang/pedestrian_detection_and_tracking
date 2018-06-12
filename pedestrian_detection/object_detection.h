#ifndef OBJECT_DETECTION_H
#define OBJECT_DETECTION_H

#include "opencv2/core/utility.hpp"
#include <vector>
#include <string>

struct Object{
    cv::Rect rec;
    float prob;
};

class ObjectDetection
{
    public:
        ObjectDetection(const std::string _model_path);
        std::vector<cv::Rect> detectObject(const cv::Mat& _frame);
    private:
};

#endif
