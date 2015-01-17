#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

class ImageSource {

	public: 
		ImageSource(){}
		virtual ~ImageSource(){}
		
		virtual bool getImage(std::vector<unsigned char> &data) = 0;
		
		int height, width;		
};
