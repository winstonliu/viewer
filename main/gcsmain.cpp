#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

#include <csignal>
#include <thread>
#include <opencv2/opencv.hpp>

//Libraries
#include "filesource.h"
#include "imagepacket.h"

#define MAX_WAIT_TIME 5000

uavimage impacket;

void makeTarget(int event, int x, int y, int, void*){
	if( event != cv::EVENT_LBUTTONDOWN )      return;

	std::cout<<"Target Noted!"<<std::endl;
}

int main(){
	cv::Mat jpg, image;
	char option;
	bool image_ok;
	int button;
	std::vector<unsigned char> buffer;
	ImageSource* src;

	std::cout<<"Open from files [1], or stream [2]" <<std::endl;
	std::cin >> option;


	cv::namedWindow("main", cv::WINDOW_AUTOSIZE);

	if(option=='1'){
		src = new FileSource();	
		cv::setMouseCallback("main",makeTarget,0);
	}
	else
		src = new FileSource();
	//
 	
	image_ok = src->getImage(buffer);		
	while(image_ok){
		jpg = cv::Mat(buffer);
		image = cv::imdecode(jpg,1);
		cv::imshow("main", image);
	
		button = cv::waitKey(MAX_WAIT_TIME);
		if(button == 'q' && option != '1' ) {
			std::cout<<"Remember image"<<std::endl;
		}	
	
		image_ok = src->getImage(buffer);
	}		
	return 0;
}
