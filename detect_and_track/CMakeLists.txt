#cmake_minimum_required(VERSION 2.8)
#set(OpenCV_DIR "/home/lingkang/Documents/opencv-3.1.0/build")
#project(optical_flow_tracker)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra -pthread")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
find_package(Threads REQUIRED)
add_definitions(-std=c++11)

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../3rd_party/ncnn/build/src)
#link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../build/pedestrian_detection)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../pedestrian_detection)

add_library( detect_and_track SHARED lk_tracker.cpp munkres.cpp det_and_track.cpp)
target_link_libraries( detect_and_track ${OpenCV_LIBS} pedestrian_detection)
