# pedestrian_detection_and_tracking
Pedestrian detection using Mobilenet SSD and tracking

[![IMAGE ALT TEXT HERE](http://img.youtube.com/vi/RvVWxufc6S8/0.jpg)](http://www.youtube.com/watch?v=RvVWxufc6S8)

## Pedestrian detection
Trained using Caffe Mobilenet SSD, details(https://github.com/zlingkang/mobilenet_ssd_pedestrian_detection)  
Then model transfered to [ncnn]() (a deeplearning framework optimized for mobile platforms)

## Tracking
An optical-flow and Kalman Filter based multiple object tracker, more details: [https://github.com/zlingkang/multi_object_tracker](https://github.com/zlingkang/multi_object_tracker)

## Usage
* Compile ncnn  
go to 3rd_party/ncnn  
`mkdir build`  
`cd build`  
`cmake ..`  
`make`  
* Compile all the rest  
in root directory  
`mkdir build`  
`cd build`  
`cmake ..`  
`make`  
* Run  
go to build/
`./main`
