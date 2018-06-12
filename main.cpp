#include "det_and_track.h"
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>

int main( int argc, char** argv )
{
    DetAndTrack dtObject;

    cv::VideoCapture cap("../MOT17-11.mp4");
    //cv::VideoCapture cap(0);
    cv::Mat frame;
    
    cap >> frame;

    dtObject.setFrame(frame);
    
    std::thread detThread(&DetAndTrack::detectionTask, &dtObject);
    std::thread trackThread(&DetAndTrack::trackTask, &dtObject);

    while(true)
    {
        cap >> frame;
        if(frame.empty())
        {
            break;
        }
        cv::Mat result = frame.clone();
        //uncomment the next line when reading from a video
        std::this_thread::sleep_for(std::chrono::milliseconds(40));
        std::vector<cv::Rect> boxes;
        std::vector<cv::Scalar> colors;

        std::cout << "set new frame.." << std::endl;
        dtObject.mutex_.lock();
        boxes = dtObject.getBox();
        colors = dtObject.getColor();
        dtObject.setFrame(frame);
        dtObject.mutex_.unlock();

        int i = 0;
        for(auto box:boxes)
        {
            cv::rectangle(result, box, colors[i], 2, 1);
            //cv::rectangle(result, box, cv::Scalar(0,0,255), 2, 1);
            i ++;
            std::cout << box << std::endl;
        }
        std::cout << "start drawing.." << std::endl;
        cv::imshow("detandtrack", result);
        if(cv::waitKey(1) == 27)
        {
            break;
        }

    }

    detThread.join();
    trackThread.join();
    return 0;
}
