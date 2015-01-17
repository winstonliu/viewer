cmake_minimum_required(VERSION 3.0.2)
project("UTX VIEWER")

set(CMAKE_VERBOSE_MAKEFILE OFF)
FIND_PACKAGE(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_subdirectory(main)
add_subdirectory(imgsrc)
