#include "object_detection.h"
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <chrono>
#include <iostream>

int main( int argc, char** argv )
{
    cv::VideoCapture cap("/home/lingkang/Videos/MOT17-11.mp4");
    cv::Mat frame;

    ObjectDetection det("../../pedestrian_detection/");

    while(true)
    {
        cap >> frame;
        std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
        auto recs = det.detectObject(frame);
        std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
        std::chrono::duration<double> time_used = std::chrono::duration_cast<std::chrono::duration<double>>(t2-t1);
        std::cout<<"Optical flow time: " << time_used.count() << "seconds" << std::endl;

        for(auto rec:recs)
        {
            cv::rectangle(frame, rec, cv::Scalar(0, 255, 0), 2, 1);
        }

        cv::imshow("detection", frame);
        if(cv::waitKey(1) == 27)
        {
            break;
        }
    }
}
