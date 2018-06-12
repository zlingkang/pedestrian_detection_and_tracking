#cmake_minimum_required(VERSION 2.8)

#project(pedistrian_detection)

set(CMAKE_BUILD_TYPE Release)

find_package( OpenCV REQUIRED )
#find_package(OpenCV REQUIRED core highgui imgproc)

if (NOT OpenCV_FOUND)
    message(FATAL_ERROR "opencv Not Found!")
else()
    message(STATUS "OpenCV_LIBS: ${OpenCV_LIBS}")
    message(STATUS "OpenCV_INCLUDE_DIRS: ${OpenCV_INCLUDE_DIRS}")
endif (NOT OpenCV_FOUND)

find_package(OpenMP)
if(OpenMP_CXX_FOUND OR OPENMP_FOUND)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

add_definitions(-std=c++11)

message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_BINARY_DIR}")
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../3rd_party/ncnn/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../3rd_party/ncnn/build/src)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../3rd_party/ncnn/build/src)

SET(NCNNLIB -Wl,--whole-archive ncnn -Wl,--no-whole-archive)

link_directories(
  ${OpenCV_Install}/lib
)

add_library(pedestrian_detection STATIC object_detection.cpp)
target_link_libraries(pedestrian_detection ${NCNNLIB} ${OpenCV_LIBS})

add_executable(detection_test test.cpp)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../build/pedestrian_detection)
#link_directories(${CMAKE_CURRENT_SOURCE_DIR}/build)
target_link_libraries(detection_test pedestrian_detection ${OpenCV_LIBS})

set_property(TARGET pedestrian_detection PROPERTY POSITION_INDEPENDENT_CODE ON)


