cmake_minimum_required(VERSION 2.8)
set(OpenCV_DIR "/home/lingkang/Documents/opencv-3.1.0/build")
project(pedestrian_detection_and_tracking)
add_definitions(-std=c++11)

add_subdirectory(pedestrian_detection)
add_subdirectory(detect_and_track)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-Wall -Wextra -pthread")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

find_package(OpenMP)
if(OpenMP_CXX_FOUND OR OPENMP_FOUND)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

#link_directories(${CMAKE_CURRENT_SOURCE_DIR}/build/detect_and_track)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/3rd_party/ncnn/build/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/detect_and_track)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/pedestrian_detection)

add_executable( main main.cpp)
target_link_libraries( main ${OpenCV_LIBS} detect_and_track)
