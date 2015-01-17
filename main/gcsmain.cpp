#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

#include <csignal>
#include <thread>

//Libraries
#include "filesource.h"
#include "imagepacket.h"
#include <opencv2/opencv.hpp>

uavimage impacket;

int main(){
	cv::Mat jpg, image;
	char viewoption;
	bool image_ok;
	std::vector<unsigned char> buffer;
	ImageSource* src;

	std::cout<<"Open from files [1], or stream [2]" <<std::endl;
	std::cin<<viewoption;


	cv::namedWindow("main", cv::WINDOW_AUTOSIZE);
	//if(viewoption=='1')
		src = new FileSource();	
			
	//else
 	image_ok = src->getImage(buffer);		
	while(image_ok){
		jpg = cv::Mat(buffer);
		image = cv::imdecode(jpg,1);
		cv::imshow("main", image);
		image_ok = src->getImage(buffer);
		cv::waitKey(0);

	}		
	return 0;
}
